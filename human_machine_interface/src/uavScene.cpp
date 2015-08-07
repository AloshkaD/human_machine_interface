/*
  qoswidget
  Show the vehicle 3D model.
  @author  Angel Luis González López, Yolanda de la Hoz Simón.
  @date    03-2015
  @version 1.0
*/


#include "../include/human_machine_interface/uavScene.h"
#include "qt4/QtCore/QDebug"
#include "osgDB/ReadFile"
#include <math.h>

// TODO yolanda: communicate the collector with class to read the rotation angles.

uavScene::uavScene(QWidget *parent, telemetryStateReceiver *telemetryReceiver): QGLWidget(parent)
{
    telemReceiver=telemetryReceiver;
    // Create a view to show the scene with OSG.
    viewer = new osgViewer::Viewer;

    // Create the transformation matrix to show the 3D model, this is the root node.
    transformation = new osg::MatrixTransform;
    auxTransformation = new osg::MatrixTransform;

    
    // Load the 3D model, Geodo
    loadedModel = osgDB::readNodeFile("../../../../human_machine_interface/data/pelican.stl");
    if(loadedModel.get()==NULL)
      qDebug()<<"NULL";

    // Set camera
    osg::Vec3d eye( 20.0, -20.0, 20.0 );
    osg::Vec3d center( 0.0, 0.0, 0.0 );
    osg::Vec3d up( 0.0, 0.0, 1.0 );


    viewer->getCamera()->setViewMatrixAsLookAt( eye, center, up );


   // Set the 3D mode as child of the transformation.
   auxTransformation->addChild(loadedModel.get());

   auxTransformation->setMatrix(osg::Matrix::rotate( osg::DegreesToRadians(90.0), 1, 0, 0 ));
   
   transformation->addChild(auxTransformation);



    // Rotation angle
    cow_rot = 0;
}

void uavScene::initializeGL()
{
    // Use the context of OpenGL created by QGLWidget to OSG.
    // configure the viewport
    window = viewer->setUpViewerAsEmbeddedInWindow(0, 0, width(), height());

    // Set the object type to manipulate the camera
    viewer->setCameraManipulator(new osgGA::TrackballManipulator);
}

void uavScene::resizeGL(int width, int height)
{
    if (window.valid())
    {
        // Adjust the dimensions of the OSG if the widgets change the size
        // TODO yolanda: send a signal to resize the widget to call this function.
        window->resized(window->getTraits()->x, window->getTraits()->y, width, height);
        window->getEventQueue()->windowResize(window->getTraits()->x, window->getTraits()->y, width, height);
    }

}



void uavScene::paintGL()
{

    // Set a rotation matrix transforamtion to turn the model


    float pitchAngle=osg::DegreesToRadians(telemReceiver->RotationAnglesMsgs.vector.y);
    float yawAngle=osg::DegreesToRadians(telemReceiver->RotationAnglesMsgs.vector.z);
    float rollAngle=osg::DegreesToRadians(telemReceiver->RotationAnglesMsgs.vector.x);

    osg::Matrix pitchMatrix = osg::Matrix::rotate( pitchAngle, 1, 0, 0 );
    osg::Matrix yawMatrix = osg::Matrix::rotate( yawAngle, 0, 1, 0 );
    osg::Matrix rollMatrix = osg::Matrix::rotate( rollAngle, 0, 1, 0 );

    transformation->setMatrix(pitchMatrix*yawMatrix*rollMatrix);
//    transformation->setMatrix(osg::Matrix::rotate(cow_rot, 0, 0, 1));

    // Set the root node inside the scene
    viewer->setSceneData(transformation.get());

    // Increase the roation angle
    cow_rot += 2.06;

    // Render the frame
    if (viewer.valid())
        viewer->frame();
}

