/*!*******************************************************************************************
 *  \file       connection.h
 *  \brief      Connection definition file.
 *  \details    This file includes the Connection class declaration. To obtain more
 *              information about it's definition consult the connection.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef CONNECTION_H
#define CONNECTION_H

#include <thread>
#include "telemetry_state_receiver.h"
#include "odometry_state_receiver.h"
#include "images_receiver.h"
#include "user_commander.h"
#include "mission_state_receiver.h"
#include "sphere_view.h"
#include "ros_graph_receiver.h"

#include <qt4/Qt/qdialog.h>

namespace Ui {
class connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0, int argc=0, char **argv=0);
    ~Connection();
        void ReadSettings(); // Load up program settings at startup
        void WriteSettings(); // Save program settings when closing


        void close();
        bool connect_status;
        bool readyForConnect();
        void shutdownThread();
        std::string rosnamespace;
        std::string node_name;


        TelemetryStateReceiver* telemetry_receiver;
        OdometryStateReceiver* odometry_receiver;
        ImagesReceiver* img_receiver;
        RosGraphReceiver* graph_receiver;
        UserCommander* usercommander;
        MissionStateReceiver* mission_planner_receiver;

        QString settings_file;

        void spinnerThread();

public Q_SLOTS:
        void onButton_connect_clicked(bool check);
        void on_checkbox_use_environment_stateChanged(int state);
        bool init();
        bool init(const std::string &master_url, const std::string &host_url);

    /******************************************
    ** Manual connections
    *******************************************/
    //void updateLoggingView();

Q_SIGNALS:
        void rosShutdown();
        void connectionEstablish();
private:

    bool initInCommon();
    std::thread connection_admin_thread;
    Ui::connection *ui;
    int init_argc;
    char** init_argv;


};

#endif // CONNECTION_H
