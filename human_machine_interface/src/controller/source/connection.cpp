/*
  Connection - Intializes ROS threads to send and receive packages 
  @author  Yolanda de la Hoz Simón
  @date    05-2015
  @version 2.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/connection.h"
#include "../../../../human_machine_interface-build/ui_connection.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

Connection::Connection(QWidget *parent,int argc, char** argv):
    init_argc(argc),
    init_argv(argv),
    QDialog(parent),
    ui(new Ui::connection)
{
	ui->setupUi(this);

    telemetryReceiver= new TelemetryStateReceiver();
    odometryReceiver= new OdometryStateReceiver();
    imgReceiver = new ImagesReceiver();
    usercommander= new UserCommander();
    graphReceiver= new RosGraphReceiver();
   
    connectStatus=false;
    connect(ui->connectButton,SIGNAL(clicked(bool)),this, SLOT(onButton_connect_clicked(bool)));
}


/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */
void Connection::onButton_connect_clicked(bool check)
{
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


void Connection::on_checkbox_use_environment_stateChanged(int state)
{
    bool enabled;
    if ( state == 0 )
        enabled = true;
    else
        enabled = false;

    ui->line_edit_master->setEnabled(enabled);
    ui->line_edit_host->setEnabled(enabled);
}


bool Connection::init()
{
    ros::init(init_argc,init_argv,ros::this_node::getName());// ros node started.
    if ( ! ros::master::check() ) // Check if roscore has been initialized.
      return false;

    ros::start(); // explicitly call to ros start
    ros::NodeHandle n;

    // Start query threads
    telemetryReceiver->openSubscriptions(n);
    odometryReceiver->openSubscriptions(n);
    imgReceiver->openSubscriptions(n);
    graphReceiver->openSubscriptions(n);
    // Start command threads
    usercommander->openPublications(n);


    return true;
}


bool Connection::init(const std::string &master_url, const std::string &host_url)
{
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,"HMI");
    if ( ! ros::master::check() )
        return false;

    ros::start(); // explicitly call to ros start
    ros::NodeHandle n;
    // Start query threads
    //telemetryReceiver->openGeneralSubscriptions(n);


    // Start command threads
    return true;
}


void Connection::ReadSettings()
{
  /*  QSettings settings("Qt-Ros Package", qnode->nodeName().c_str());
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui->line_edit_master->setText(master_url);
    ui->line_edit_host->setText(host_url);
    bool remember = settings.value("remember_settings", false).toBool();
    ui->checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui->checkbox_use_environment->setChecked(checked);
    if ( checked ) {
        ui->line_edit_master->setEnabled(false);
        ui->line_edit_host->setEnabled(false);
    }*/
}


void Connection::WriteSettings()
{
   /* QSettings settings("Qt-Ros Package", qnode->nodeName().c_str());
    settings->setValue("geometry", geometry());
    settings->setValue("master_url",ui.line_edit_master->text());
    settings->setValue("host_url",ui.line_edit_host->text());
    settings->setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings->setValue("windowState", saveState());
    settings->setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));*/
}


void Connection::close()
{
    this->~Connection();
}


Connection::~Connection()
{
    delete ui;
}

