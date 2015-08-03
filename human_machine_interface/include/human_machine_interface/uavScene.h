/*
 * OpenSceneGraph + Qt + Offscreen rendering example.
 * Copyright (C) 2011  Gonzalo Exequiel Pedone
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with This program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://hipersayanx.blogspot.com/
 */

#ifndef UAVSCENE_H
#define UAVSCENE_H

#include "qt4/QtOpenGL/QGLWidget"

#include "osgDB/ReadFile"
#include "osgGA/TrackballManipulator"
#include "osg/MatrixTransform"
#include "osgViewer/Viewer"
#include "telemetryStateReceiver.h"

class uavScene: public QGLWidget
{
    Q_OBJECT

    public:
        explicit uavScene(QWidget *parent = 0,telemetryStateReceiver *telemetryReceiver=0);

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
        telemetryStateReceiver* telemReceiver;


        osg::ref_ptr<osgViewer::Viewer> viewer;
        osg::observer_ptr<osgViewer::GraphicsWindowEmbedded> window;
        osg::ref_ptr<osg::Node> loadedModel;
        osg::ref_ptr<osg::MatrixTransform> transformation;
        osg::ref_ptr<osg::MatrixTransform> auxTransformation;
};

#endif // UAVSCENE_H
