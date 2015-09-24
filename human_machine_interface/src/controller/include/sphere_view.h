/*!*******************************************************************************************
 *  \file       sphere_view.h
 *  \brief      SphereView definition file.
 *  \details    This file includes the SphereView class declaration. To obtain more
 *              information about it's definition consult the sphere_view.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef SPHEREVIEW_H
#define SPHEREVIEW_H

#include "qt4/QtOpenGL/QGLWidget"

#include "osgDB/ReadFile"
#include "osgText/Text"
#include "osgGA/TrackballManipulator"
#include "osg/MatrixTransform"
#include "osgViewer/Viewer"
#include "telemetry_state_receiver.h"

class SphereView: public QGLWidget
{
    Q_OBJECT

    public:
        explicit SphereView(QWidget *parent, TelemetryStateReceiver *telemetryReceiver=0);
    void onResize( int width, int height );

    private:
        void initializeGL();
        void resizeGL(int width, int height);
        void paintGL();
        void shapeDrawer(osg::MatrixTransform* mainXtrans, osg::MatrixTransform* faxisXtrans);
        void axisGenerator(osg::Geometry* axis, bool fixed);


    public Q_SLOTS:
    private:
        float cow_rot;
        float pitch;
        float yaw;
        float roll;
        TelemetryStateReceiver* telemReceiver;

        osg::ref_ptr<osgViewer::Viewer> viewer;
        osg::observer_ptr<osgViewer::GraphicsWindowEmbedded> window;
        osg::ref_ptr<osg::MatrixTransform> mainXtrans;
        osg::ref_ptr<osg::MatrixTransform> labelXtrans;
        osg::ref_ptr<osg::MatrixTransform> root;
};

#endif // SPHEREVIEW_H
