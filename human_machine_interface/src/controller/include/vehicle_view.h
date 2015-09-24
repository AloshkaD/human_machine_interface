/*!*******************************************************************************************
 *  \file       vehicle_view.h
 *  \brief      VehicleView definition file.
 *  \details    This file includes the VehicleView class declaration. To obtain more
 *              information about it's definition consult the vehicle_view.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef VEHICLEVIEW_H
#define VEHICLEVIEW_H

#include "qt4/QtOpenGL/QGLWidget"

#include "osgDB/ReadFile"
#include "osgGA/TrackballManipulator"
#include "osg/MatrixTransform"
#include "osgViewer/Viewer"
#include "telemetry_state_receiver.h"

class VehicleView: public QGLWidget
{
    Q_OBJECT

    public:
        explicit VehicleView(QWidget *parent = 0,TelemetryStateReceiver *telemetryReceiver=0);

    private:
        void initializeGL();
        void resizeGL(int width, int height);
        void paintGL();



    public Q_SLOTS:
    private:
        float cow_rot;
        float pitch;
        float yaw;
        float roll;
        TelemetryStateReceiver* telemReceiver;
        osg::ref_ptr<osgViewer::Viewer> viewer;
        osg::observer_ptr<osgViewer::GraphicsWindowEmbedded> window;
        osg::ref_ptr<osg::Node> loaded_model;
        osg::ref_ptr<osg::MatrixTransform> transformation;
        osg::ref_ptr<osg::MatrixTransform> aux_transformation;
};

#endif
