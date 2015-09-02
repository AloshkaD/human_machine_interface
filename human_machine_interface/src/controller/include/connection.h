#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include "telemetry_state_receiver.h"
#include "odometry_state_receiver.h"
#include "images_receiver.h"
#include "user_commander.h"
#include "sphere_view.h"
#include "ros_graph_receiver.h"

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
        bool connectStatus;

        TelemetryStateReceiver* telemetryReceiver;
        OdometryStateReceiver* odometryReceiver;
        ImagesReceiver* imgReceiver;
        RosGraphReceiver* graphReceiver;
        UserCommander* usercommander;

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
        void onButton_connect_clicked(bool check);
        void on_checkbox_use_environment_stateChanged(int state);
        bool init();
        bool init(const std::string &master_url, const std::string &host_url);

    /******************************************
    ** Manual connections
    *******************************************/
    //void updateLoggingView();

Q_SIGNALS:
        void connectionEstablish();
private:
    Ui::connection *ui;
    int init_argc;
    char** init_argv;

};

#endif // CONNECTION_H
