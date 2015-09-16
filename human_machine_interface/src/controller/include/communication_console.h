#ifndef COMMUNICATIONCONSOLE_H
#define COMMUNICATIONCONSOLE_H


#include <QDialog>
#include "telemetry_state_receiver.h"
#include "odometry_state_receiver.h"
#include "images_receiver.h"
#include "ros_graph_receiver.h"
#include "sphere_view.h"

namespace Ui {
class CommunicationConsole;
}

class CommunicationConsole : public QDialog
{
    Q_OBJECT

public:
    explicit CommunicationConsole(QWidget *parent = 0, ImagesReceiver *imgReceiver=0, TelemetryStateReceiver *telemReceiver=0, OdometryStateReceiver* odom_receiver=0,RosGraphReceiver* gr_receiver=0);
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
    TelemetryStateReceiver* telemetry_receiver;
    OdometryStateReceiver* odometry_receiver;
    ImagesReceiver* images_receiver;
    RosGraphReceiver* graph_receiver;

};

#endif // COMMUNICATIONCONSOLE_H
