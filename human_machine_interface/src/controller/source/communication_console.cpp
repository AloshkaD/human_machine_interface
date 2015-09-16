/*
  Communication Console - Debug console to receive ROS info messages about the state of incoming connections 
  @author  Yolanda de la Hoz Simón
  @date    04-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/communication_console.h"
#include "../.././../../../hmi_cvg_stack-build/human_machine_interface/ui_communicationconsole.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

CommunicationConsole::CommunicationConsole(QWidget *parent,ImagesReceiver* img_receiver,TelemetryStateReceiver* telem_receiver,OdometryStateReceiver* odom_receiver,RosGraphReceiver* gr_receiver ):
    QDialog(parent),
    ui(new Ui::CommunicationConsole)
{
    ui->setupUi(this);

    telemetry_receiver=telem_receiver;
    images_receiver=img_receiver;
    odometry_receiver=odom_receiver;
    graph_receiver=gr_receiver;

    connect(telemetry_receiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    connect(images_receiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    connect(odometry_receiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    connect(graph_receiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    ui->list_view_tab1->setModel(telemetry_receiver->loggingModel());
    ui->list_view_tab2->setModel(images_receiver->loggingModel());
    ui->list_view_tab3->setModel(odometry_receiver->loggingModel());
    ui->list_view_tab4->setModel(graph_receiver->loggingModel());
}

void CommunicationConsole::updateLoggingView()
{
        ui->list_view_tab1->scrollToBottom();
        ui->list_view_tab2->scrollToBottom();
        ui->list_view_tab3->scrollToBottom();
        ui->list_view_tab4->scrollToBottom();
}

void CommunicationConsole::close()
{
    this->~CommunicationConsole();
}


CommunicationConsole::~CommunicationConsole()
{
   delete ui;
}


