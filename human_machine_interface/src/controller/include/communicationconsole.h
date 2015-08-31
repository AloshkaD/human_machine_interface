#ifndef COMMUNICATIONCONSOLE_H
#define COMMUNICATIONCONSOLE_H


#include <QDialog>
#include "telemetryStateReceiver.h"
#include "odometryStateReceiver.h"
#include "imagesreceiver.h"
#include "usercommander.h"
#include "sphereview.h"

namespace Ui {
class CommunicationConsole;
}

class CommunicationConsole : public QDialog
{
    Q_OBJECT

public:
    explicit CommunicationConsole(QWidget *parent = 0, imagesReceiver *imgReceiver=0, telemetryStateReceiver *telemReceiver=0);
    ~CommunicationConsole();



        void close();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
        void updateLoggingView();


    /******************************************
    ** Manual connections
    *******************************************/
    //void updateLoggingView();


private:
    Ui::CommunicationConsole *ui;
    telemetryStateReceiver* telemetryReceiver;
    odometryStateReceiver* odometryReceiver;
    imagesReceiver* imgReceiver;

};

#endif // COMMUNICATIONCONSOLE_H
