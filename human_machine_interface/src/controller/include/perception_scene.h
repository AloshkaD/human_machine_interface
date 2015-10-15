/*!*******************************************************************************************
 *  \file       perception_scene.h
 *  \brief      PerceptionScene definition file.
 *  \details    This file includes the PerceptionScene class declaration. To obtain more
 *              information about it's definition consult the perception_scene.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef PERCEPTIONSCENE_H
#define PERCEPTIONSCENE_H

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


#include <QWidget>

#include <iostream>

const unsigned int g_numPoints = 400;
const float g_halfWidth = 4.0f;

class PerceptionScene : public QWidget, public osgViewer::CompositeViewer
{
     Q_OBJECT
public:
    PerceptionScene(QWidget *parent, osgViewer::ViewerBase::ThreadingModel threadingModel=osgViewer::CompositeViewer::SingleThreaded);
    ~PerceptionScene();
    QWidget* addViewWidget(osgQt::GraphicsWindowQt *gw);
    osgQt::GraphicsWindowQt *createGraphicsWindow( int x, int y, int w, int h, const std::string& name="", bool windowDecoration=false );

    void lines(osg::Geometry* line);
    void createPoles(osg::ref_ptr<osg::Group> root);
    void createMap(osg::ref_ptr<osg::Group> root);

    osg::Node* createMovingModel(const osg::Vec3& center, float radius, osg::Geometry *geometry);
    osg::Geometry* createPath(osg::ref_ptr<osg::Group> root);
    osg::AnimationPath* createAnimationPath(const osg::Vec3& center,float radius,double looptime);
    osg::Node* createModel(bool overlay, osgSim::OverlayNode::OverlayTechnique technique, osg::Geometry *geometryPath);
    osg::Geometry* drawPath( const osg::Vec3& colorRGB );

protected:
    virtual void paintEvent( QPaintEvent* event );
    osg::ref_ptr<osg::Node> loaded_model;
    QTimer _timer;
};

#endif // PERCEPTIONSCENE_H
