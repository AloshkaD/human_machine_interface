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


#include <qt4/Qt/qtimer.h>
#include <qt4/Qt/qapplication.h>
#include <qt4/Qt/qgridlayout.h>
#include <osg/MatrixTransform>
#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgGA/TrackballManipulator>

#include <osgDB/ReadFile>
#include <osgQt/GraphicsWindowQt>

#include <osg/Depth>
#include <osg/Node>
#include <osgUtil/Optimizer>
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
#include <osgSim/OverlayNode>
#include <osg/Plane>
#include <osg/Material>

#include <osg/LineWidth>
#include "telemetry_state_receiver.h"


#include <QWidget>

#include <iostream>


class VehicleView: public QWidget, public osgViewer::CompositeViewer
{
    Q_OBJECT

    public:
         VehicleView(QWidget *parent, osgViewer::ViewerBase::ThreadingModel threadingModel=osgViewer::CompositeViewer::SingleThreaded,TelemetryStateReceiver *telemetryReceiver=0);
         ~VehicleView();
         QWidget* addViewWidget(osgQt::GraphicsWindowQt *gw);
         osgQt::GraphicsWindowQt *createGraphicsWindow( int x, int y, int w, int h, const std::string& name="", bool windowDecoration=false );
         explicit VehicleView(QWidget *parent = 0,TelemetryStateReceiver *telemetryReceiver=0);

    protected:
        virtual void paintEvent( QPaintEvent* event );
        QTimer _timer;
        float pitch;
        float yaw;
        float roll;
        TelemetryStateReceiver* telemReceiver;

        osg::ref_ptr<osgViewer::Viewer> viewer;
        osg::ref_ptr<osg::Node> loaded_model;
        osg::ref_ptr<osg::MatrixTransform> transformation;
        osg::ref_ptr<osg::MatrixTransform> aux_transformation;
        osg::ref_ptr<osg::MatrixTransform> root;
};

#endif
