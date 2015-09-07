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
#include "../.././../../../src-build/human_machine_interface/ui_communicationconsole.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

CommunicationConsole::CommunicationConsole(QWidget *parent,ImagesReceiver* imgReceiver,TelemetryStateReceiver* telemReceiver):
    QDialog(parent),
    ui(new Ui::CommunicationConsole)
{
    telemetryReceiver=telemReceiver;
    imagesReceiver=imgReceiver;
    ui->setupUi(this);
    connect(telemetryReceiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    connect(imagesReceiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    ui->ListView_tab1->setModel(telemetryReceiver->loggingModel());
    ui->ListView_tab2->setModel(imagesReceiver->loggingModel());
}

void CommunicationConsole::updateLoggingView()
{
        ui->ListView_tab1->scrollToBottom();
        ui->ListView_tab2->scrollToBottom();
}

void CommunicationConsole::close()
{
    this->~CommunicationConsole();
}


CommunicationConsole::~CommunicationConsole()
{
   delete ui;
}


