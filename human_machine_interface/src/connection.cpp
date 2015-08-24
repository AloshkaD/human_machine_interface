/*
  connection
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

#include "../include/human_machine_interface/connection.h"
#include "../../human_machine_interface-build/ui_connection.h"

Connection::Connection(QWidget *parent,int argc, char** argv):
    init_argc(argc),
    init_argv(argv),
    QDialog(parent),
    ui(new Ui::connection)
{
    telemetryReceiver= new telemetryStateReceiver();
    odometryReceiver= new odometryStateReceiver();
    imgReceiver = new imagesReceiver();
    usercommander= new UserCommander();
    ui->setupUi(this);
    connectStatus=false;
    connect(ui->connectButton,SIGNAL(clicked(bool)),this, SLOT(onButton_connect_clicked(bool)));
}


/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void Connection::onButton_connect_clicked(bool check) {
    std::string master;
    std::string host;
    if ( ui->checkbox_use_environment->isChecked() ) {
        if(!this->init()){
            connectStatus=false;
         }else{
            connectStatus=true;
            ui->connectButton->setEnabled(false);
         }
    }else{
        master=ui->line_edit_master->text().toStdString();
        host=ui->line_edit_host->text().toStdString();
        if(!this->init(master,host)){
            connectStatus=false;
        }else{
            ui->connectButton->setEnabled(false);
            ui->line_edit_master->setReadOnly(true);
            ui->line_edit_host->setReadOnly(true);
            connectStatus=true;
        }
    }
   Q_EMIT connectionEstablish();
}


void Connection::on_checkbox_use_environment_stateChanged(int state) {
    bool enabled;
    if ( state == 0 )
        enabled = true;
    else
        enabled = false;

    ui->line_edit_master->setEnabled(enabled);
    ui->line_edit_host->setEnabled(enabled);
}

bool Connection::init(){
    ros::init(init_argc,init_argv,"HMI");// ros node started.
    if ( ! ros::master::check() ) // Check if roscore has been initialized.
      return false;

    ros::start(); // explicitly call to ros start
    ros::NodeHandle n;
    // Start query threads
    telemetryReceiver->openGeneralSubscriptions(n);
    odometryReceiver->openGeneralSubscriptions(n);
    odometryReceiver->openSubscriptionsController(n);
    imgReceiver->openSubscriptions(n);
    // Start command threads
    usercommander->openPublications(n);
    return true;
}

bool Connection::init(const std::string &master_url, const std::string &host_url) {
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,"HMI");
    if ( ! ros::master::check() )
        return false;

    ros::start(); // explicitly call to ros start
    ros::NodeHandle n;
    // Start query threads
    telemetryReceiver->openGeneralSubscriptions(n);


    // Start command threads
    return true;
}

void Connection::close()
{
    this->~Connection();
}
Connection::~Connection()
{
    delete ui;
}

