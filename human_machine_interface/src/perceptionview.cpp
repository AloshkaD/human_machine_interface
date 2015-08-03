/*
  PerceptionView
  Perception View window. Displays rviz scene.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/



#include <rviz/visualization_manager.h>
#include <rviz/visualization_frame.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/yaml_config_reader.h>
#include <rviz/yaml_config_writer.h>
#include <rviz/view_manager.h>
#include <rviz/panel_dock_widget.h>
#include "../include/human_machine_interface/perceptionview.h"
#include "../../human_machine_interface-build/ui_perceptionview.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

PerceptionView::PerceptionView(QWidget *parent, QString *file_name) :
    QDockWidget(parent),
    ui(new Ui::perceptionView)
{

    ui->setupUi(this);

    frame_=new rviz::VisualizationFrame();
    frame_->setSplashPath("");
    frame_->initialize();

    render_panel_ = new rviz::RenderPanel();
    rviz::YamlConfigReader reader;
    rviz::Config config;
    std::string filename = "/home/yolanda/workspace/ros/quadrotor_stack_catkin/src/quadrotor_stack/stack/HMI/droneSimulatorRvizROSModule/launch/Simulator_rviz.rviz";
            //;
            //"/home/yolanda/workspace/ros/quadrotor_stack_catkin/src/quadrotor_stack/stack/HMI/droneSimulatorRvizROSModule/launch/Simulator_rviz.rviz" ;
    // /home/yolanda/workspace/ros/quadrotor_stack_catkin/src/quadrotor_stack/stack/HMI/droneSimulatorRvizROSModule/launch/Simulator_rviz.rviz
    //home/yolanda/iarc_ws/src/scripts/perception.rviz
   // /home/yolanda/workspace/ros/quadrotor_stack_catkin/src/quadrotor_stack/stack/HMI/droneSimulatorRvizROSModule/launch/Simulator_rviz.rviz
    reader.readFile( config, QString::fromStdString( filename ));
   /* if( !reader.error() )
    {
        std::cout << "Se ha leido el archivo config correctamente";
        frame_->load( config);
    }
    "/home/yolanda/workspace/ros/quadrotor_stack_catkin/src/quadrotor_stack/stack/HMI/droneSimulatorRvizROSModule/launch/Simulator_rviz.rviz"
*/

    frame_->initialize("/home/yolanda/iarc_ws/src/scripts/perception.rviz");
    manager_=frame_->getManager();
    render_panel_=manager_->getRenderPanel();
    // Set the top-level layout for Perception View widget.
     this->setWidget( render_panel_);
}

PerceptionView::~PerceptionView()
{
    delete render_panel_;
    delete grid_;
    delete manager_;
    delete ui;
}
