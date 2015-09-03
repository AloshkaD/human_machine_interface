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
#include "../../view/ui_communicationconsole.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

CommunicationConsole::CommunicationConsole(QWidget *parent,ImagesReceiver* imgReceiver,TelemetryStateReceiver* telemReceiver):
    QDialog(parent),
    ui(new Ui::CommunicationConsole)
{
    telemetryReceiver=telemReceiver;
    ui->setupUi(this);
    QObject::connect(telemetryReceiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    ui->ListView_tab1->setModel(telemetryReceiver->loggingModel());
}

void CommunicationConsole::updateLoggingView()
{
        ui->ListView_tab1->scrollToBottom();
}

void CommunicationConsole::close()
{
    this->~CommunicationConsole();
}


CommunicationConsole::~CommunicationConsole()
{
   delete ui;
}


