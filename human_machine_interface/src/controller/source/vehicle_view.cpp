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
#include "../include/vehicle_view.h"
#include "qt4/QtCore/QDebug"
#include "osgDB/ReadFile"
#include <math.h>
/*****************************************************************************
** Implementation
*****************************************************************************/

VehicleView::VehicleView(QWidget* parent,osgViewer::ViewerBase::ThreadingModel threadingModel, TelemetryStateReceiver *telemetryReceiver) :
    QWidget(parent)
{
    telemReceiver=telemetryReceiver;
    setThreadingModel(threadingModel);
    // disable the default setting of viewer.done() by pressing Escape.
    setKeyEventSetsDone(0);
    connect( &_timer, SIGNAL(timeout()), this, SLOT(update()) );
    _timer.start( 10 );

}

void VehicleView::paintEvent( QPaintEvent* event )
{
    frame();
}

osgQt::GraphicsWindowQt*  VehicleView::createGraphicsWindow( int x, int y, int w, int h, const std::string& name, bool windowDecoration)
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

QWidget* VehicleView::addViewWidget(osgQt::GraphicsWindowQt* gw)
{
    // Create a view to show the scene with OSG.
    osgViewer::View* view = new osgViewer::View;
    addView( view );
    view->getCamera()->setGraphicsContext( gw );
    const osg::GraphicsContext::Traits* traits = gw->getTraits();

    // Create the transformation matrix to show the 3D model, this is the root node.
    root = new osg::MatrixTransform;
    transformation = new osg::MatrixTransform;
    aux_transformation = new osg::MatrixTransform;

    // Load the 3D model, Geodo
    loaded_model = osgDB::readNodeFile("model2.osg");

    // Set camera
      osg::Vec3d eye( 15.0, -15.0, 15.0 );
      osg::Vec3d center( 0.0, 0.0, 0.0 );
      osg::Vec3d up( 0.0, 0.0, 1.0 );

    view->getCamera()->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
    view->getCamera()->setViewMatrixAsLookAt( eye, center, up );
    view->getCamera()->setClearColor( osg::Vec4(0.106078,  0.6, 0.6, 1.0) );




    if(loaded_model.get()!=NULL){
        // Set the 3D mode as child of the transformation.
        aux_transformation->addChild(loaded_model.get());
        //aux_transformation->setMatrix(osg::Matrix::rotate( osg::DegreesToRadians(90.0), 1, 0, 0 ));
        transformation->addChild(aux_transformation);
    }else
        std::cout<<"the model is not loaded"<<std::endl;

    view->setSceneData(transformation.get());
    view->addEventHandler( new osgViewer::StatsHandler );
    view->setCameraManipulator( new osgGA::TrackballManipulator );
    return gw->getGLWidget();
}


VehicleView::~VehicleView()
{
}
