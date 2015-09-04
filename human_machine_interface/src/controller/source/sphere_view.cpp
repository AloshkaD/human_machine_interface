/*
  qoswidget
  Show the vehicle 3D model.
  @author  Yolanda de la Hoz Simón.
  @date    06-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/sphere_view.h"
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
/*****************************************************************************
** Implementation
*****************************************************************************/

SphereView::SphereView(QWidget *parent, TelemetryStateReceiver *telemetryReceiver): QGLWidget(parent)
{

    telemReceiver=telemetryReceiver;
    // Create a view to show the scene with OSG.
    viewer = new osgViewer::Viewer;

    // Create the transformation matrix to show the 3D model, this is the root node.
    root = new osg::MatrixTransform;
    mainXtrans = new osg::MatrixTransform;
    labelXtrans = new osg::MatrixTransform;
    osg::MatrixTransform* faxisXtrans = new osg::MatrixTransform;
    // Draw shapes
    shapeDrawer(mainXtrans, faxisXtrans);

    // Set camera
    osg::Vec3d eye( 15.0, -15.0, 15.0 );
    osg::Vec3d center( 0.0, 0.0, 0.0 );
    osg::Vec3d up( 0.0, 0.0, 1.0 );


    viewer->getCamera()->setViewMatrixAsLookAt( eye, center, up );

    viewer->getCamera()->setClearColor(osg::Vec4(0.2f,0.2f,0.2f,0.15f));

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
        // send a signal to resize the widget to call this function.
        window->resized(window->getTraits()->x, window->getTraits()->y, width, height);
        window->getEventQueue()->windowResize(window->getTraits()->x, window->getTraits()->y, width, height);

    }
}



void SphereView::paintGL()
{


    float pitchAngle=osg::DegreesToRadians(telemReceiver->rotationAnglesMsgs.vector.y);
    float yawAngle=osg::DegreesToRadians(telemReceiver->rotationAnglesMsgs.vector.z);
    float rollAngle=osg::DegreesToRadians(telemReceiver->rotationAnglesMsgs.vector.x);


    osg::Matrix pitchMatrix = osg::Matrix::rotate( pitchAngle, 1, 0, 0 );
    osg::Matrix yawMatrix = osg::Matrix::rotate( yawAngle, 0, 0, 1 );
    osg::Matrix rollMatrix = osg::Matrix::rotate( rollAngle, 0, 1, 0 );

    mainXtrans->setMatrix(pitchMatrix*yawMatrix*rollMatrix);
   // labelXtrans->setMatrix(rollMatrix);

    viewer->setSceneData(root);
    // Increase the roation angle


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
