#include "../include/perception_scene.h"


PerceptionScene::PerceptionScene(QWidget* parent,osgViewer::ViewerBase::ThreadingModel threadingModel) :
    QWidget(parent)
{
    setThreadingModel(threadingModel);
    // disable the default setting of viewer.done() by pressing Escape.
    setKeyEventSetsDone(0);
    connect( &_timer, SIGNAL(timeout()), this, SLOT(update()) );
    _timer.start( 10 );

}

void PerceptionScene::paintEvent( QPaintEvent* event ){
    frame();
}

osg::Geode* PerceptionScene::createNodeWithMyImageOnIt(const std::string& filename)
{
    osg::Geode* geode = new osg::Geode;
    osg::Geometry* geometry = osg::createTexturedQuadGeometry(osg::Vec3(0,0.5,0),osg::Vec3(1,0,0),osg::Vec3(0,0,1),0, 0, 1, 1);
    geode->addDrawable(geometry);
    osg::Texture2D* texture = new osg::Texture2D(osgDB::readImageFile(filename));
    geode->getOrCreateStateSet()->setTextureAttributeAndModes(0,texture, osg::StateAttribute::ON);
    geode->getOrCreateStateSet()->setTextureMode(0, GL_TEXTURE_2D,osg::StateAttribute::ON);
    //geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
    return geode;
}


QWidget* PerceptionScene::addViewWidget(osgQt::GraphicsWindowQt* gw)
{

    osg::ref_ptr<osg::Group> root = new osg::Group;

    bool overlay = true;
    osgSim::OverlayNode::OverlayTechnique technique = osgSim::OverlayNode::OBJECT_DEPENDENT_WITH_ORTHOGRAPHIC_OVERLAY;
    // load the nodes from the commandline arguments.
    osg::Node* model = createModel(overlay, technique);

    // run optimization over the scene graph
    osgUtil::Optimizer optimzer;
    optimzer.optimize(root);

    osg::Projection* Proj = new osg::Projection;
    Proj->setMatrix(osg::Matrix::ortho2D(0,1,0,1));
    osg::Geode* backgroundImage = createNodeWithMyImageOnIt("Metal_Corrogated_Shiny.jpg");
    Proj->addChild(backgroundImage);


    createMap(root);
    createPoles(root);
    root->addChild(model);
        root->addChild(Proj);

    osgViewer::View* view = new osgViewer::View;
    addView( view );

    osg::Camera* camera = view->getCamera();
    camera->setGraphicsContext( gw );

    const osg::GraphicsContext::Traits* traits = gw->getTraits();

    // camera->setClearColor( osg::Vec4(0.106078,  0.6, 0.6, 1.0) );
    camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
    camera->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f );

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

void PerceptionScene::createPoles(osg::ref_ptr<osg::Group> root){
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


void PerceptionScene::auxiliarLine(osg::Geometry* line){
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
    line->setStateSet(stateset);
}



void PerceptionScene::createMap(osg::ref_ptr<osg::Group>  root){
    osg::ShapeDrawable* map = new osg::ShapeDrawable;

    osg::Geometry* auxLines = new osg::Geometry;

    osg::Geode* mapGeode = new osg::Geode();


    map->setShape( new osg::Box(osg::Vec3(10.0f, 10.0f, 0.0f), 20.0f, 20.0f, 0.0001f));
    map->setColor( osg::Vec4(0.8f, 0.8f, 0.8f, 1.0f));
    auxiliarLine(auxLines);

    mapGeode->addDrawable( map );
    mapGeode->addDrawable(auxLines);

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

osg::Node* PerceptionScene::createMovingModel(const osg::Vec3& center, float radius)
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
        xform->addChild(positioned);


        model->addChild(xform);
    }
    return model;
}

osg::Node* PerceptionScene::createModel(bool overlay, osgSim::OverlayNode::OverlayTechnique technique)
{
    osg::Vec3 center(10.0f,10.0f,2.0f);
    float radius =4.0f;

    osg::Group* root = new osg::Group;

    float baseHeight = center.z()-radius;
    //osg::Node* baseModel = createBase(osg::Vec3(center.x(), center.y(), baseHeight),radius);
    osg::Node* movingModel = createMovingModel(center,radius*0.8f);

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
