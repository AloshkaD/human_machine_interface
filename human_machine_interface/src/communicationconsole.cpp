/*
  communicationconsole
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/


#include "../include/human_machine_interface/communicationconsole.h"
#include "../../human_machine_interface-build/ui_communicationconsole.h"


CommunicationConsole::CommunicationConsole(QWidget *parent,imagesReceiver* imgReceiver,telemetryStateReceiver* telemReceiver):
    QDialog(parent),
    ui(new Ui::CommunicationConsole)
{
    telemetryReceiver=telemReceiver;
    ui->setupUi(this);
    QObject::connect(telemetryReceiver, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    ui->odometryListView->setModel(telemetryReceiver->loggingModel());
}

void CommunicationConsole::updateLoggingView()
{
        ui->odometryListView->scrollToBottom();
}

void CommunicationConsole::close()
{
    this->~CommunicationConsole();
}


CommunicationConsole::~CommunicationConsole()
{
   delete ui;
}


