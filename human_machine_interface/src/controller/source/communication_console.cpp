/*
  communicationconsole
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/


#include "../include/communication_console.h"
#include "../../../../human_machine_interface-build/ui_communicationconsole.h"


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


