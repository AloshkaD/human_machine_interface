

#include <rviz/visualization_manager.h>
#include <rviz/visualization_frame.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/yaml_config_reader.h>
#include <rviz/yaml_config_writer.h>
#include <rviz/view_manager.h>
#include <rviz/panel_dock_widget.h>
#include "../include/human_machine_interface/dinamicsview.h"
#include "../../human_machine_interface-build/ui_dinamicsview.h"

dinamicsView::dinamicsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dinamicsView)
{
    ui->setupUi(this);

    frame_=new rviz::VisualizationFrame();
    frame_->setSplashPath("");
    frame_->initialize();

    render_panel_ = new rviz::RenderPanel();
    /*rviz::YamlConfigReader reader;
    rviz::Config config;
     std::string filename = "/home/yolanda/iarc_ws/src/scripts/urdf.rviz";

    reader.readFile( config, QString::fromStdString( filename ));
    if( !reader.error() )
    {
        std::cout << "Se ha leido el archivo config correctamente";
        frame_->load( config);
    }

*/
    frame_->initialize("/home/yolanda/iarc_ws/src/scripts/urdf.rviz");
    manager_=frame_->getManager();
    render_panel_=manager_->getRenderPanel();
    // Set the top-level layout for Perception View widget.
    ui->gridVehicle->addWidget( render_panel_);
}

dinamicsView::~dinamicsView()
{
    delete render_panel_;
    delete grid_;
    delete manager_;
    delete ui;
}
