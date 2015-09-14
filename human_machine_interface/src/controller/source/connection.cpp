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
#include <qt4/Qt/qsettings.h>
#include "../.././../../../hmi_cvg_stack -build/human_machine_interface/ui_connection.h"
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
    ReadSettings();
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
    if(ros::this_node::getNamespace().compare(" /")){
        rosnamespace.append("/drone0");//default namespace
        node_name.append(ros::this_node::getName());
    }
    else{
        rosnamespace.append(ros::this_node::getNamespace());
        node_name.append("HMI");
    }

    ros::init(init_argc,init_argv,node_name);// ros node started.
    if ( ! ros::master::check() ) // Check if roscore has been initialized.
      return false;

    ros::start(); // explicitly call to ros start
    ros::NodeHandle n;

    std::cout << "Namespace con ros::this_node::getNamespace(): " << ros::this_node::getNamespace()<<std::endl;
    

    // Start query threads
    telemetryReceiver->openSubscriptions(n, rosnamespace);
    odometryReceiver->openSubscriptions(n, rosnamespace);
    imgReceiver->openSubscriptions(n, rosnamespace);
    graphReceiver->openSubscriptions(n, rosnamespace);
    // Start command threads
    usercommander->openPublications(n, rosnamespace);


    return true;
}


bool Connection::init(const std::string &master_url, const std::string &host_url)
{
    if(ros::this_node::getNamespace().compare(" /")){
        rosnamespace.append("/drone0");//default namespace
        node_name.append(ros::this_node::getName());
    }
    else{
        rosnamespace.append(ros::this_node::getNamespace());
        node_name.append("HMI");
    }

    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,node_name);
    if ( ! ros::master::check() )
        return false;

    ros::start(); // explicitly call to ros start
    ros::NodeHandle n;

    std::cout << "Namespace con ros::this_node::getNamespace(): " << ros::this_node::getNamespace()<<std::endl;


    // Start query threads
    telemetryReceiver->openSubscriptions(n, rosnamespace);
    odometryReceiver->openSubscriptions(n, rosnamespace);
    imgReceiver->openSubscriptions(n, rosnamespace);
    graphReceiver->openSubscriptions(n, rosnamespace);
    // Start command threads
    usercommander->openPublications(n, rosnamespace);


    return true;
}


void Connection::ReadSettings()
{
    QSettings settings("Human Machine Interface - QSettings", node_name.c_str());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    ui->line_edit_master->setText(master_url);
    ui->line_edit_host->setText(host_url);
    bool remember = settings.value("remember_settings", false).toBool();
    ui->checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui->checkbox_use_environment->setChecked(checked);
    if ( checked ) {
        ui->line_edit_master->setEnabled(false);
        ui->line_edit_host->setEnabled(false);
    }
}


void Connection::WriteSettings()
{
    QSettings settings("Human Machine Interface - QSettings", node_name.c_str());
    settings.setValue("master_url",ui->line_edit_master->text());
    settings.setValue("host_url",ui->line_edit_host->text());
    settings.setValue("use_environment_variables",QVariant(ui->checkbox_use_environment->isChecked()));
    settings.setValue("remember_settings",QVariant(ui->checkbox_remember_settings->isChecked()));
}


void Connection::close()
{
    this->~Connection();
}


Connection::~Connection()
{
    delete ui;
}

