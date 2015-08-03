/*
  qoswidget
  Show the vehicle 3D model.
  @author  Angel Luis González López, Yolanda de la Hoz Simón.
  @date    03-2015
  @version 1.0
*/


#include "../include/human_machine_interface/sphereview.h"
#include "qt4/QtCore/QDebug"
#include "osgDB/ReadFile"
#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>
#include <osg/StateSet>
#include <osg/Texture2D>
#include <osg/TexEnv>
#include <osg/TexGen>
#include <osg/ShapeDrawable>
#include <iostream>


#include <osg/LineWidth>
#include "osg/MatrixTransform"

#include <math.h>

// TODO yolanda: communicate the collector with class to read the rotation angles.
// TODO angel: sphere and uav design.
SphereView::SphereView(QWidget *parent, telemetryStateReceiver *telemetryReceiver): QGLWidget(parent)
{

    telemReceiver=telemetryReceiver;
    // Create a view to show the scene with OSG.
    viewer = new osgViewer::Viewer;

    // Create the transformation matrix to show the 3D model, this is the root node.
    root = new osg::MatrixTransform;
    mainXtrans = new osg::MatrixTransform;
    labelXtrans = new osg::MatrixTransform;
    osg::MatrixTransform* faxisXtrans = new osg::MatrixTransform;
    // createMap(root);
    // Draw shapes
    shapeDrawer(mainXtrans, faxisXtrans);

    // Set camera
    osg::Vec3d eye( 15.0, -15.0, 15.0 );
    osg::Vec3d center( 0.0, 0.0, 0.0 );
    osg::Vec3d up( 0.0, 0.0, 1.0 );


    viewer->getCamera()->setViewMatrixAsLookAt( eye, center, up );

    //viewer->getCamera()->setClearColor(osg::Vec4(0.2f,0.2f,0.2f,0.15f));




    root->addChild(faxisXtrans);



    root->addChild(mainXtrans);

   // root->addChild(labelXtrans);
}

void SphereView::initializeGL()
{
    // Use the context of OpenGL created by QGLWidget to OSG.
    // configure the viewport
    window = viewer->setUpViewerAsEmbeddedInWindow(0, 0, width(), height());

    // Set the object type to manipulate the camera
    //viewer->setCameraManipulator(new osgGA::TrackballManipulator);
}

void SphereView::resizeGL(int width, int height)
{
    if (window.valid())
    {
        // Adjust the dimensions of the OSG if the widgets change the size
        // TODO yolanda: send a signal to resize the widget to call this function.
        window->resized(window->getTraits()->x, window->getTraits()->y, width, height);
        window->getEventQueue()->windowResize(window->getTraits()->x, window->getTraits()->y, width, height);
    }
}



void SphereView::paintGL()
{


    float pitchAngle=osg::DegreesToRadians(telemReceiver->RotationAnglesMsgs.vector.y);
    float yawAngle=osg::DegreesToRadians(telemReceiver->RotationAnglesMsgs.vector.z);
    float rollAngle=osg::DegreesToRadians(telemReceiver->RotationAnglesMsgs.vector.x);

    qDebug()<<telemReceiver->RotationAnglesMsgs.vector.x;
    qDebug()<<telemReceiver->RotationAnglesMsgs.vector.y;
    qDebug()<<telemReceiver->RotationAnglesMsgs.vector.z;

    osg::Matrix pitchMatrix = osg::Matrix::rotate( pitchAngle, 1, 0, 0 );
    osg::Matrix yawMatrix = osg::Matrix::rotate( yawAngle, 0, 1, 0 );
    osg::Matrix rollMatrix = osg::Matrix::rotate( rollAngle, 0, 1, 0 );

    mainXtrans->setMatrix(pitchMatrix*yawMatrix*rollMatrix);
   // labelXtrans->setMatrix(rollMatrix);

    viewer->setSceneData(root);
    // Increase the roation angle

    // Increase the roation angle
    cow_rot += 2.06;


    // Render the frame
    if (viewer.valid())
        viewer->frame();
}



void SphereView::shapeDrawer(osg::MatrixTransform* mainXtrans, osg::MatrixTransform* faxisXtrans){

    // Shapes
    osg::ref_ptr<osg::ShapeDrawable> sphere = new osg::ShapeDrawable;

    osg::ref_ptr<osg::ShapeDrawable> coneX = new osg::ShapeDrawable;
    osg::ref_ptr<osg::ShapeDrawable> coneY = new osg::ShapeDrawable;
    osg::ref_ptr<osg::ShapeDrawable> coneZ = new osg::ShapeDrawable;

    osg::Geometry* axis = new osg::Geometry;
    osg::Geometry* fixedAxis = new osg::Geometry;

    // Geodes
    osg::Geode* sphereGeode = new osg::Geode();
    osg::Geode* coneXGeode = new osg::Geode();
    osg::Geode* coneYGeode = new osg::Geode();
    osg::Geode* coneZGeode = new osg::Geode();
    osg::Geode* fixedAxisGeode = new osg::Geode();
    osg::Geode* XtextGeode = new osg::Geode();



    // Transformations
    osg::PositionAttitudeTransform* xconeXForm = new osg::PositionAttitudeTransform();
    osg::PositionAttitudeTransform* xlabelXForm = new osg::PositionAttitudeTransform();
    osg::PositionAttitudeTransform* yconeXForm = new osg::PositionAttitudeTransform();
    osg::PositionAttitudeTransform* zconeXForm = new osg::PositionAttitudeTransform();


  //  osgText::Text* xLabel = new osgText::Text();


    // Creating Shapes
    sphere->setShape( new osg::Sphere(osg::Vec3(0.0f, 0.0f, 0.0f), 1.0f));
    sphere->setColor( osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));


    coneX->setShape( new osg::Cone(osg::Vec3(0.0f, 0.0f, 0.0f), 0.25f, 1.0f));
    coneY->setShape( new osg::Cone(osg::Vec3(0.0f, 0.0f, 0.0f), 0.25f, 1.0f));
    coneZ->setShape( new osg::Cone(osg::Vec3(0.0f, 0.0f, 0.0f), 0.25f, 1.0f));

    coneX->setColor( osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f));
    coneY->setColor( osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
    coneZ->setColor( osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));


    axisGenerator(axis, false);
    axisGenerator(fixedAxis, true);



    // Transformations
    xconeXForm->setPosition(osg::Vec3(5.0f,0,0));
    xconeXForm->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(0,1,0) ) );

    //xlabelXForm->setPosition(osg::Vec3(5.0f,0,0));
    //xlabelXForm->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(0,1,0) ) );


    xconeXForm->setPosition(osg::Vec3(5.0f,0,0));
    xconeXForm->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(0,1,0) ) );


    yconeXForm->setPosition(osg::Vec3(0,5.0f,0));
    yconeXForm->setAttitude(osg::Quat(osg::DegreesToRadians(-90.0), osg::Vec3(1,0,0) ) );

    zconeXForm->setPosition(osg::Vec3(0.0,0,5.0f));


    // linking
    sphereGeode->addDrawable( axis );
    sphereGeode->addDrawable( sphere );


    coneXGeode->addDrawable( coneX );
    //XtextGeode->addDrawable( xLabel );

    // Set up the parameters for the text we'll add to the X axis:
   /*  xLabel->setCharacterSize(0.3);
     xLabel->setFont("");
     xLabel->setText("ROLL");
     xLabel->setAxisAlignment(osgText::Text::SCREEN);
     xLabel->setPosition(osg::Vec3(0.6f,0.6f,0.6f));
     xLabel->setColor( osg::Vec4(199, 77, 15, 1) );*/


    coneYGeode->addDrawable( coneY );
    coneZGeode->addDrawable( coneZ );

    fixedAxisGeode-> addDrawable( fixedAxis );




    xconeXForm->addChild(coneXGeode);
  //  xlabelXForm->addChild(XtextGeode);
    yconeXForm->addChild(coneYGeode);
    zconeXForm->addChild(coneZGeode);

//    labelXtrans->addChild(XtextGeode);

    faxisXtrans->addChild(fixedAxisGeode);


    mainXtrans->addChild(sphereGeode);

    mainXtrans->addChild(xconeXForm);
    mainXtrans->addChild(yconeXForm);
    mainXtrans->addChild(zconeXForm);




}

void SphereView::mainLines(osg::Geometry* line){
    osg::Vec3Array* coords = new osg::Vec3Array(10);
    (*coords)[0] = osg::Vec3(0.0f, 0.0f, 0.01f); // Roja
    (*coords)[1] = osg::Vec3(20.0f, 0.0f, 0.01f);
    (*coords)[2] = osg::Vec3(0.0f, 10.0f, 0.01f); // Blanca
    (*coords)[3] = osg::Vec3(20.0f,10.0f, 0.01f);
    (*coords)[4] = osg::Vec3(0.0f, 20.0f, 0.01f); // verde
    (*coords)[5] = osg::Vec3(20.0f,20.0f, 0.01f);

    (*coords)[6] = osg::Vec3(0.0f, 0.0f,  0.01f); // Izq
    (*coords)[7] = osg::Vec3(0.0f, 20.0f, 0.01f);
    (*coords)[8] = osg::Vec3(20.0f, 0.0f, 0.01f); // derecha
    (*coords)[9] = osg::Vec3(20.0f,20.0f, 0.01f);

    line->setVertexArray(coords);

    osg::Vec4 loose_color(1.0f, 0.0f, 0.0f, 1.0f);
    osg::Vec4 neutral_color(1.0f, 1.0f, 1.0f, 1.0f);
    osg::Vec4 win_color(0.0f, 1.0f, 0.0f, 1.0f);



    osg::Vec4Array* color = new osg::Vec4Array(10);
    (*color)[0] = loose_color;
    (*color)[1] = loose_color;
    (*color)[2] = neutral_color;
    (*color)[3] = neutral_color;
    (*color)[4] = win_color;
    (*color)[5] = win_color;
    (*color)[6] = neutral_color;
    (*color)[7] = neutral_color;
    (*color)[8] = neutral_color;
    (*color)[9] = neutral_color;

    line->setColorArray(color, osg::Array::BIND_PER_VERTEX);

    line->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES,0,10));

    osg::StateSet* stateset = new osg::StateSet;
    osg::LineWidth* linewidth = new osg::LineWidth();
    linewidth->setWidth(6.0f);
    stateset->setAttributeAndModes(linewidth,osg::StateAttribute::ON);
    stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
    line->setStateSet(stateset);
}


void SphereView::createMap(osg::MatrixTransform* root){
    osg::ShapeDrawable* map = new osg::ShapeDrawable;


    osg::Geometry* mainLine = new osg::Geometry;
    osg::Geometry* auxLines = new osg::Geometry;

    osg::Geode* mapGeode = new osg::Geode();


    map->setShape( new osg::Box(osg::Vec3(10.0f, 10.0f, 0.0f), 20.0f, 20.0f, 0.0001f));
    map->setColor( osg::Vec4(0.8f, 0.8f, 0.8f, 1.0f));
    mainLines(mainLine);
    //auxiliarLine(auxLines);

    mapGeode->addDrawable( map );
    mapGeode->addDrawable(mainLine);
    //mapGeode->addDrawable(auxLines);


    //const char* a = mapGeode->getDrawable(3)->getShape()->className();

    //std::cout << a << '\n';
    root->addChild(mapGeode);
}




void SphereView::BuildWall(osg::MatrixTransform* root)
{

    osg::Geode* WallGeode = new osg::Geode();
    osg::Geometry* WallGeometry = new osg::Geometry();

    WallGeode->addDrawable(WallGeometry);
    //add the Node to the root Node
    root->addChild(WallGeode);
    //specify vertices
    osg::Vec3Array* WallVertices = new osg::Vec3Array;
    WallVertices->push_back( osg::Vec3(0, 0, 0) ); // front left
    WallVertices->push_back( osg::Vec3(10, 0, 0) ); // front right
    WallVertices->push_back( osg::Vec3(10,10, 0) ); // back right
    WallVertices->push_back( osg::Vec3(0,10, 0) ); // back left
    WallGeometry->setVertexArray( WallVertices );

    //specify the kind of geometry we want to draw here
    osg::DrawElementsUInt* WallBase = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    //specify the order we want to draw the base of our geometry
    WallBase->push_back(3);
    WallBase->push_back(2);
    WallBase->push_back(1);
    WallBase->push_back(0);
    WallGeometry->addPrimitiveSet(WallBase);
    //Declare and load an array of Vec4 elements to store colors.
    osg::Vec4Array* colors = new osg::Vec4Array;
    //colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 0 red
    //colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); //index 1 green
    //colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) ); //index 2 blue
    colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 3 white
    //colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 4 red

    WallGeometry->setColorArray(colors);
    WallGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

    // Declare and initialize a transform node.
    osg::PositionAttitudeTransform* WallTwoXForm = new osg::PositionAttitudeTransform();

    // Use the 'addChild' method of the osg::Group class to
    // add the transform as a child of the root node and the
    // pyramid node as a child of the transform.
    root->addChild(WallTwoXForm);
    WallTwoXForm->addChild(WallGeode);
    float scale=root->getBound().radius();
    WallTwoXForm->setScale(osg::Vec3d(scale,scale,scale));

    // Declare and initialize a Vec3 instance to change the
    // position of the tank model in the scene
    osg::Vec3 WallTwoPosition(15,0,0);

    WallTwoXForm->setPosition(WallTwoPosition );

}


void SphereView::axisGenerator(osg::Geometry* axis, bool fixed){
    osg::Vec3Array* coords = new osg::Vec3Array(6);
    (*coords)[0] = osg::Vec3(-5.0f, 0.0f, 0.0f); // X
    (*coords)[1] = osg::Vec3(5.0f, 0.0f, 0.0f);
    (*coords)[2] = osg::Vec3(0.0f, -5.0f, 0.0f); // Y
    (*coords)[3] = osg::Vec3(0.0f, 5.0f, 0.0f);
    (*coords)[4] = osg::Vec3(0.0f, 0.0f, -5.0f); // Z
    (*coords)[5] = osg::Vec3(0.0f, 0.0f, 5.0f);

    axis->setVertexArray(coords);

    osg::Vec4 x_color(0.0f, 0.0f, 1.0f, 1.0f);
    osg::Vec4 y_color(1.0f, 0.0f, 0.0f, 1.0f);
    osg::Vec4 z_color(0.0f, 1.0f, 0.0f, 1.0f);

    if (fixed){
        osg::Vec4 xf_color(0.0f, 0.0f, 0.4f, 1.0f);
        osg::Vec4 yf_color(0.4f, 0.0f, 0.0f, 1.0f);
        osg::Vec4 zf_color(0.0f, 0.4f, 0.0f, 1.0f);

        x_color = xf_color;
        y_color = yf_color;
        z_color = zf_color;
    }



    osg::Vec4Array* color = new osg::Vec4Array(6);
    (*color)[0] = x_color;
    (*color)[1] = x_color;
    (*color)[2] = y_color;
    (*color)[3] = y_color;
    (*color)[4] = z_color;
    (*color)[5] = z_color;

    axis->setColorArray(color, osg::Array::BIND_PER_VERTEX);

    axis->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES,0,6));

    osg::StateSet* stateset = new osg::StateSet;
    osg::LineWidth* linewidth = new osg::LineWidth();
    linewidth->setWidth(4.0f);
    stateset->setAttributeAndModes(linewidth,osg::StateAttribute::ON);
    stateset->setMode(GL_LIGHTING,osg::StateAttribute::OFF);
    axis->setStateSet(stateset);
}
