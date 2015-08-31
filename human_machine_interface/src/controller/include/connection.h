#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include "telemetryStateReceiver.h"
#include "odometryStateReceiver.h"
#include "imagesreceiver.h"
#include "usercommander.h"
#include "sphereview.h"

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

        telemetryStateReceiver* telemetryReceiver;
        odometryStateReceiver* odometryReceiver;
        imagesReceiver* imgReceiver;

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
