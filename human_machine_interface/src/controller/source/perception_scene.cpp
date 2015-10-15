#include "../include/perception_scene.h"


class TrailerCallback : public osg::NodeCallback
{
public:
    TrailerCallback( osg::Geometry* ribbon ) : _ribbon(ribbon) {}

    virtual void operator()( osg::Node* node, osg::NodeVisitor* nv )
    {
        osg::MatrixTransform* trans = static_cast<osg::MatrixTransform*>(node);
        if ( trans && _ribbon.valid() )
        {
            osg::Matrix matrix = trans->getMatrix();
            osg::Vec3Array* vertices = static_cast<osg::Vec3Array*>( _ribbon->getVertexArray() );
            osg::Vec3Array* normals = static_cast<osg::Vec3Array*>( _ribbon->getNormalArray() );

            for ( unsigned int i=0; i<g_numPoints-3; i+=2 )
            {
                (*vertices)[i] = (*vertices)[i+2];
                (*vertices)[i+1] = (*vertices)[i+3];
                (*normals)[i] = (*normals)[i+2];
                (*normals)[i+1] = (*normals)[i+3];
            }

            (*vertices)[g_numPoints-2] = osg::Vec3(0.0f,-g_halfWidth, 0.0f) * matrix;
            (*vertices)[g_numPoints-1] = osg::Vec3(0.0f, g_halfWidth, 0.0f) * matrix;
            vertices->dirty();

            osg::Vec3 normal = osg::Vec3(0.0f, 0.0f, 1.0f) * matrix;
            normal.normalize();
            (*normals)[g_numPoints-2] = normal;
            (*normals)[g_numPoints-1] = normal;
            normals->dirty();

            _ribbon->dirtyBound();
        }
        traverse( node, nv );
    }

protected:
    osg::observer_ptr<osg::Geometry> _ribbon;
};



PerceptionScene::PerceptionScene(QWidget* parent,osgViewer::ViewerBase::ThreadingModel threadingModel) :
    QWidget(parent)
{
    setThreadingModel(threadingModel);
    // disable the default setting of viewer.done() by pressing Escape.
    setKeyEventSetsDone(0);
    connect( &_timer, SIGNAL(timeout()), this, SLOT(update()) );
    _timer.start( 10 );

}

void PerceptionScene::paintEvent( QPaintEvent* event )
{
    frame();
}


osg::Geometry* PerceptionScene::drawPath( const osg::Vec3& colorRGB )
{
    osg::ref_ptr<osg::Vec3Array> vertices =new osg::Vec3Array(g_numPoints);
    osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(g_numPoints);
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(g_numPoints);
    osg::Vec3 origin = osg::Vec3(0.0f, 0.0f, 0.0f);
    osg::Vec3 normal = osg::Vec3(0.0f, 0.0f, 1.0f);

    for ( unsigned int i=0; i<g_numPoints-1; i+=2 )
    {
        (*vertices)[i] = origin; (*vertices)[i+1] = origin;
        (*normals)[i] = normal; (*normals)[i+1] = normal;
        float alpha = sinf(osg::PI * (float)i / (float)g_numPoints);
        (*colors)[i] = osg::Vec4(colorRGB, alpha);
        (*colors)[i+1] = osg::Vec4(colorRGB, alpha);
    }
    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
    geom->setDataVariance( osg::Object::DYNAMIC );
    geom->setUseDisplayList( false );
    geom->setUseVertexBufferObjects( true );

    geom->setVertexArray( vertices.get() );
    geom->setNormalArray( normals.get() );
    geom->setNormalBinding( osg::Geometry::BIND_PER_VERTEX );
    geom->setColorArray( colors.get() );
    geom->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
    geom->addPrimitiveSet( new osg::DrawArrays(GL_QUAD_STRIP, 0, g_numPoints) );
    return geom.release();
}

osg::Geometry* PerceptionScene::createPath(osg::ref_ptr<osg::Group> root)
{
   osg::Geometry* geometry = drawPath( osg::Vec3(1.0f, 0.0f, 1.0f) );
   osg::ref_ptr<osg::Geode> geode = new osg::Geode;
   geode->addDrawable( geometry );
   geode->getOrCreateStateSet()->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
   geode->getOrCreateStateSet()->setMode( GL_BLEND, osg::StateAttribute::ON );
   geode->getOrCreateStateSet()->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
   return geometry;
}


QWidget* PerceptionScene::addViewWidget(osgQt::GraphicsWindowQt* gw)
{
    osg::ref_ptr<osg::Group> root = new osg::Group;

    // run optimization over the scene graph
    osgUtil::Optimizer optimzer;
    optimzer.optimize(root);

    // create the scene graph

    osg::Geometry* geometry = drawPath( osg::Vec3(1.0f, 0.0f, 1.0f) );
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable( geometry );
    geode->getOrCreateStateSet()->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
    geode->getOrCreateStateSet()->setMode( GL_BLEND, osg::StateAttribute::ON );
    geode->getOrCreateStateSet()->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

    bool overlay = true;
    osgSim::OverlayNode::OverlayTechnique technique = osgSim::OverlayNode::OBJECT_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY;
    // load the nodes from the commandline arguments.
    osg::Node* model = createModel(overlay, technique, geometry);


    createMap(root);
    createPoles(root);
    root->addChild( geode.get() );
    root->addChild(model);


    osgViewer::View* view = new osgViewer::View;
    addView( view );

    osg::Camera* camera = view->getCamera();
    camera->setGraphicsContext( gw );

    const osg::GraphicsContext::Traits* traits = gw->getTraits();

    camera->setClearColor( osg::Vec4(0.106078,  0.6, 0.6, 1.0) );
    camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
    camera->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f );
    osg::DisplaySettings::instance()->setNumMultiSamples( 88 );
    view->setSceneData(root);
    view->addEventHandler( new osgViewer::StatsHandler );
    view->setCameraManipulator( new osgGA::TrackballManipulator );

    return gw->getGLWidget();
}

osgQt::GraphicsWindowQt*  PerceptionScene::createGraphicsWindow( int x, int y, int w, int h, const std::string& name, bool windowDecoration)
{
    osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
    traits->windowName = name;
    traits->windowDecoration = windowDecoration;
    traits->x = x;
    traits->y = y;
    traits->width = w;
    traits->height = h;
    traits->doubleBuffer = true;
    traits->alpha = ds->getMinimumNumAlphaBits();
    traits->stencil = ds->getMinimumNumStencilBits();
    traits->sampleBuffers = ds->getMultiSamples();
    traits->samples = ds->getNumMultiSamples();

    return new osgQt::GraphicsWindowQt(traits.get());
}

void PerceptionScene::createPoles(osg::ref_ptr<osg::Group> root)
{
    osg::Geode* obstacleGeode = new osg::Geode();

    osg::ShapeDrawable* pole;
    for (int i = 0; i < 4; i++){
        pole = new osg::ShapeDrawable;

        float x = osg::DegreesToRadians(i*(360.0/6.0));
        pole->setShape(new osg::Cylinder(osg::Vec3(20/2 + (5.0f * cos(x)), 20/2 + (5.0f * sin(x)), 0.05f), 0.5f, 5.0f));
        pole->setColor( osg::Vec4(1.0f, 0.0f, 1.0f, 1.0f));

        obstacleGeode->addDrawable(pole);
    }

    root->addChild(obstacleGeode);
}

void PerceptionScene::lines(osg::Geometry* line)
{
    osg::Vec3Array* coords = new osg::Vec3Array(76);
    osg::Vec4Array* color = new osg::Vec4Array(76);

    float ifloat = 1;
    for (int i = 0; i < 76; i+=4){

        (*coords)[i]   = osg::Vec3(ifloat, 0.0f, 0.01f);
        (*coords)[i+1] = osg::Vec3(ifloat, 20.0f, 0.01f);

        (*coords)[i+2]   = osg::Vec3(  0.0, ifloat,  0.01f);
        (*coords)[i+3] = osg::Vec3(20.0f, ifloat, 0.01f);



        (*color)[i]    = osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f);
        (*color)[i+1]  = osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f);

        (*color)[i+2]  = osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f);
        (*color)[i+3]  = osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f);

        ifloat++;
    }

    line->setVertexArray(coords);
    line->setColorArray(color, osg::Array::BIND_PER_VERTEX);
    line->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES,0,76));
    osg::StateSet* stateset = new osg::StateSet;
    osg::LineWidth* linewidth = new osg::LineWidth();
    linewidth->setWidth(2.0f);
    stateset->setAttributeAndModes(linewidth,osg::StateAttribute::ON);
    stateset->setMode(GL_LIGHTING,osg::StateAttribute::ON);
    stateset->setMode( GL_LINE_SMOOTH, osg::StateAttribute::ON );
    stateset->setMode( GL_BLEND, osg::StateAttribute::ON );
    line->setStateSet(stateset);
}



void PerceptionScene::createMap(osg::ref_ptr<osg::Group>  root)
{
    osg::ShapeDrawable* map = new osg::ShapeDrawable;

    osg::Geometry* gridLines = new osg::Geometry;

    osg::Geode* mapGeode = new osg::Geode();


    map->setShape( new osg::Box(osg::Vec3(10.0f, 10.0f, 0.0f), 20.0f, 20.0f, 0.0001f));
    map->setColor( osg::Vec4(0.8f, 0.8f, 0.8f, 1.0f));
    lines(gridLines);

    mapGeode->addDrawable( map );
    mapGeode->addDrawable(gridLines);

    root->addChild(mapGeode);
}

osg::AnimationPath* PerceptionScene::createAnimationPath(const osg::Vec3& center,float radius,double looptime)
{
    // set up the animation path
    osg::AnimationPath* animationPath = new osg::AnimationPath;
    animationPath->setLoopMode(osg::AnimationPath::LOOP);

    int numSamples = 40;
    float yaw = 0.0f;
    float yaw_delta = 2.0f*osg::PI/((float)numSamples-1.0f);
    float roll = osg::inDegrees(0.0f);

    double time=0.0f;
    double time_delta = looptime/(double)numSamples;
    for(int i=0;i<numSamples;++i)
    {
        osg::Vec3 position(center+osg::Vec3(sinf(yaw)*radius,cosf(yaw)*radius,0.0f));
        osg::Quat rotation(osg::Quat(roll,osg::Vec3(0.0,1.0,0.0))*osg::Quat(-(yaw+osg::inDegrees(90.0f)),osg::Vec3(0.0,0.0,1.0)));

        animationPath->insert(time,osg::AnimationPath::ControlPoint(position,rotation));

        yaw += yaw_delta;
        time += time_delta;

    }
    return animationPath;
}

osg::Node* PerceptionScene::createMovingModel(const osg::Vec3& center, float radius, osg::Geometry* geometry)
{
    float animationLength = 10.0f;

    osg::AnimationPath* animationPath = createAnimationPath(center,radius,animationLength);

    osg::Group* model = new osg::Group;

    osg::Node* droneModel = osgDB::readNodeFile("model2.osg");
    if (droneModel)
    {
        const osg::BoundingSphere& bs = droneModel->getBound();

        float size = radius/bs.radius()*0.3f;
        std::cout << size << std::endl;
        osg::MatrixTransform* positioned = new osg::MatrixTransform;
        positioned->setDataVariance(osg::Object::STATIC);
        positioned->setMatrix(osg::Matrix::translate(-bs.center())*
                              // osg::Matrix::scale(size,size,size)*
                              osg::Matrix::rotate(osg::DegreesToRadians(0.0f),0.0f,0.0f,0.0f));

        positioned->addChild(droneModel);

        osg::PositionAttitudeTransform* xform = new osg::PositionAttitudeTransform;
        xform->setUpdateCallback(new osg::AnimationPathCallback(animationPath,0.0,1.0));
        xform->addUpdateCallback( new TrailerCallback(geometry) );
        xform->addChild(positioned);


        model->addChild(xform);
    }
    return model;
}

osg::Node* PerceptionScene::createModel(bool overlay, osgSim::OverlayNode::OverlayTechnique technique, osg::Geometry* geometryPath)
{
    osg::Vec3 center(10.0f,10.0f,2.0f);
    float radius =4.0f;

    osg::Group* root = new osg::Group;

    float baseHeight = center.z()-radius;
    //osg::Node* baseModel = createBase(osg::Vec3(center.x(), center.y(), baseHeight),radius);
    osg::Node* movingModel = createMovingModel(center,radius*0.8f,geometryPath);

    if (overlay)
    {
        osgSim::OverlayNode* overlayNode = new osgSim::OverlayNode(technique);
        overlayNode->setContinuousUpdate(true);
        overlayNode->setOverlaySubgraph(movingModel);
        overlayNode->setOverlayBaseHeight(baseHeight-0.01);
        //overlayNode->addChild(baseModel);
        root->addChild(overlayNode);
    }
    else
    {

        //root->addChild(baseModel);
    }

    root->addChild(movingModel);

    return root;
}

PerceptionScene::~PerceptionScene()
{
}
