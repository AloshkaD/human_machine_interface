/*
  Control_panel
  Control_panel template and pop-up windows signals handlers.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/control_panel.h"
#include "qt4/QtGui/qwidget.h"
#include "qt4/QtGui/qevent.h"
#include <qt4/Qt/qpointer.h>
#include <qt4/Qt/qcombobox.h>
#include <qt4/Qt/qlabel.h>
#include <qt4/Qt/qfiledialog.h>
#include <qt4/Qt/qpixmap.h>
#include <qt4/Qt/qsize.h>
#include <qt4/Qt/qapplication.h>
#include <qt4/Qt/qdesktopwidget.h>
#include <qt4/Qt/qwidgetaction.h>
#include <qt4/Qt/qmenu.h>
#include <qt4/Qt/qlist.h>
#include <qt4/Qt/qstring.h>
#include <qt4/QtCore/QObject>



//Define step commands
#define CTE_COMMAND_YAW    0.40
#define CTE_COMMAND_PITCH  0.33
#define CTE_COMMAND_ROLL   0.33
#define CTE_COMMAND_HEIGHT 0.50


// Define controller commands define constants
#define CONTROLLER_CTE_COMMAND_SPEED        ( 1.00 )
#define CONTROLLER_STEP_COMMAND_POSITTION   ( 0.25 )
#define CONTROLLER_STEP_COMMAND_ALTITUDE    ( 0.25 )
#define CONTROLLER_STEP_COMMAND_YAW         ( 10.0 * (M_PI/180.0) )


using namespace std;
/*****************************************************************************
** Implementation
*****************************************************************************/




class MyContextMenu : public QMenu
{
public:
    MyContextMenu (QWidget *parent = 0) : QMenu (parent) { is_ignore_hide = false; }
    MyContextMenu (const QString &title, QWidget *parent = 0) : QMenu (title, parent) { is_ignore_hide = false; }
    void add_action_with_showed_menu (const QAction *action) { actions_with_showed_menu.insert (action); }

    virtual void setVisible (bool visible)
    {
        if (is_ignore_hide)
        {
            is_ignore_hide = false;
            return;
        }
        QMenu::setVisible (visible);
    }

    virtual void mouseReleaseEvent (QMouseEvent *e)
    {
        const QAction *action = actionAt (e->pos ());
        if (action)
            if (actions_with_showed_menu.contains (action))
                is_ignore_hide = true;
        QMenu::mouseReleaseEvent (e);
    }
private:
    // clicking on this actions don't close menu
    QSet <const QAction *> actions_with_showed_menu;
    bool is_ignore_hide;
};



ControlPanel::ControlPanel(QWidget *parent,Connection* connection) :
    QWidget(parent),
    ui(new Ui::ControlPanel) //initialize ui member
{
    ui->setupUi(this);// connects all ui's triggers

    connect=connection;
    timer = new QTimer(this); // Shows new frames rate -> 1 ms.
    timer->start(1);

    setSignalHandlers(); // triggers

    this->current_time = new QTime(0,0,0);
    setTimerInterval(1000);// 1 second = 1000

    flight_timer = new QTimer(this);
    flight_timer->start(1000);

    //old_height=this->height();
    is_init_takeoff_context_menu=false;
}
char* ControlPanel::getProcessName(const char* process_name_temp)//TODO::Comprobar si existe namespace.
{
    char output[10012];
    strncpy(output, process_name_temp, sizeof(output));
    output[sizeof(output) - 1] = 0;
    char* process_name = strtok(output, "/");
    process_name = strtok(NULL, "/");
    return process_name;
}

std::vector<std::string> ControlPanel::checkListToTakeOff()
{
   std::vector<std::string> modules_to_takeoff;
   for(int i=0;i<menu_takeoff_actions.size();i++)
   {
     if(menu_takeoff_actions.at(i)->isChecked()){
     modules_to_takeoff.push_back(menu_takeoff_actions.at(i)->text().toStdString());
     }
   }
  return modules_to_takeoff;
}

void ControlPanel::initContextMenuTakeOff()
{
    if(!is_init_takeoff_context_menu){
        MyContextMenu* take_off_contextmenu = new MyContextMenu();
        QAction* action;
        for(unsigned int i = 0; i < connect->graph_receiver->list_process_state.process_list.size(); i++)
        {
            node_container= connect->graph_receiver->list_process_state.process_list.at(i);
            char* process_name = getProcessName(node_container.name.c_str());
            /**/
            action = new QAction(process_name, this);
            action->setCheckable(true);
            //action->setCheckable(inx == 0);
            take_off_contextmenu->addAction(action);
            take_off_contextmenu->add_action_with_showed_menu(action);
        }
       ui->take_off_button->setMenu(take_off_contextmenu);
       menu_takeoff_actions=take_off_contextmenu->actions();

    }
    is_init_takeoff_context_menu=true;
    disconnect(connect->graph_receiver, SIGNAL(supervisorStateReceived()), this, SLOT(initContextMenuTakeOff( )));
}

void ControlPanel::setTimerInterval(double ms)
{
    d_interval = qRound(ms);

    if ( d_timerId >= 0 )
    {
        killTimer(d_timerId);
        d_timerId = -1;
    }
    if (d_interval >= 0 )
        d_timerId = startTimer(d_interval);
}


void ControlPanel::setSignalHandlers()
{
      
    QObject::connect(connect->telemetry_receiver, SIGNAL(parameterReceived()), this, SLOT(updateStatusPanel( )));
    QObject::connect(connect->usercommander, SIGNAL( managerStatusReceived( )), this, SLOT( updateStatusPanel( )));
    QObject::connect(connect,SIGNAL(connectionEstablish( )),this, SLOT(testConnection()));
    QObject::connect(connect->graph_receiver, SIGNAL(supervisorStateReceived()), this, SLOT(initContextMenuTakeOff( )));
    //connect(connection->telemetryReceiver, SIGNAL( parameterReceived( )), this, SLOT(show_frame()));
    QObject::connect(ui->land_button,SIGNAL(clicked()),this, SLOT(onLandButton()));
    QObject::connect(ui->take_off_button,SIGNAL(clicked()),this, SLOT(onTakeOffButton()));
    //connect(ui->yaw_zero_button,SIGNAL(clicked()),this, SLOT(onYawZeroButton()));
    QObject::connect(ui->reset_button,SIGNAL(clicked()),this, SLOT(onResetCommandButton()));
    QObject::connect(ui->loop_button,SIGNAL(clicked()),this, SLOT(onLoopButton()));
    QObject::connect(ui->hover_button,SIGNAL(clicked()),this, SLOT(onHoverButton()));
    QObject::connect(ui->emergency_stop_button,SIGNAL(clicked()),this, SLOT(onEmergencyStopButton()));
    
    QObject::connect(ui->selection_mode, SIGNAL(currentIndexChanged(int)), this, SLOT(onControlModeChange(int)));
    QObject::connect(connect->graph_receiver, SIGNAL( errorInformerReceived( )), this, SLOT( incrementErrorsCounter( )));
    QObject::connect(connect->usercommander, SIGNAL( managerStatusReceived( )), this, SLOT( setInitialControlMode( )));
    //connect(ui->tabManager, SIGNAL(clicked()), this, SLOT(openTab()));
    QObject::connect(ui->take_off_button,SIGNAL(customContextMenuRequested(const QPoint&)),this,SLOT(onCustomContextMenuRequested(const QPoint&)));

}
void ControlPanel::showNoMasterMessage()
{
    QMessageBox msgBox;
    msgBox.setText("roscore node could have not been initialized");
    msgBox.exec();
}

void ControlPanel::showConnectionEstablished()
{
    QMessageBox msgBox;
    msgBox.setText("The connection has been established succesfully.");
    msgBox.exec();
}

void ControlPanel::testConnection()
{
    if (!connect->connect_status){
        cout << "roscore node could have not been initialized" << '\n';
        showNoMasterMessage();
    }else{
        showConnectionEstablished();
        ui->value_wifi->setText("Connected");
        setCurrentUAV();
        QObject::connect(flight_timer, SIGNAL(timeout()), this, SLOT(flightTime()));
    }
}

void ControlPanel::flightTime()
{
    this->current_time->setHMS(this->current_time->addSecs(+1).hour(),this->current_time->addSecs(+1).minute(),this->current_time->addSecs(+1).second());
    QString text = this->current_time->toString();
    ui->value_fligth_time->setText(text);
}


void ControlPanel::incrementErrorsCounter()
{
    if (connect->connect_status){
        error_counter++;
        ui->value_errors->setText(QString::number(error_counter));
    }
}


bool ControlPanel::isInAutonomousMode()
{
    for(unsigned int i = 0; i < connect->graph_receiver->list_process_state.process_list.size(); i++)
    {
        node_container= connect->graph_receiver->list_process_state.process_list.at(i);
        char* process_name = getProcessName(node_container.name.c_str());
        if((strcmp(process_name, "droneMissionScheduleProcessor") == 0)&&node_container.is_alive&&node_container.current_state.state!=droneMsgsROS::ProcessState::NotStarted)
        return true;
    }
  return false;
}

void ControlPanel::setInitialControlMode()
{
    if(!isInAutonomousMode()){
        switch(connect->usercommander->getDroneManagerStatus().status)
        {
        case(droneMsgsROS::droneManagerStatus::MOVING_POSITION):
            if(current_control_mode!=control_modes::position){
                ui->selection_mode->setCurrentIndex(1);
                current_control_mode =control_modes::position;
            }
            break;
        case(droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD):
            if(current_control_mode!=control_modes::altitude){
                ui->selection_mode->setCurrentIndex(2);
                current_control_mode =control_modes::altitude;
            }
            break;
        case(droneMsgsROS::droneManagerStatus::MOVING_SPEED):
            if(current_control_mode!=control_modes::speed){
                ui->selection_mode->setCurrentIndex(3);
                current_control_mode =control_modes::speed;
            }
            break;
        case(droneMsgsROS::droneManagerStatus::MOVING_VISUAL_SERVOING):
            if(current_control_mode!=control_modes::visual_servoing){
                ui->selection_mode->setCurrentIndex(4);
                current_control_mode =control_modes::visual_servoing;
            }
            break;
        }
    }else

      ui->selection_mode->setCurrentIndex(0);
    disconnect(connect->usercommander, SIGNAL( managerStatusReceived( )), this, SLOT( setInitialControlMode( )));
}

void ControlPanel::updateStatusPanel() //TODO cambiar nombre a updateStatusPanel
{

    if (connect->connect_status){

        switch(connect->usercommander->getDroneManagerStatus().status)
        {
        case droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD:
            ui->value_currentGoal->setText("Moving Manual Altitude");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_EMERGENCY:
            ui->value_currentGoal->setText("Moving Emergency");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_TRAJECTORY:
            ui->value_currentGoal->setText("Moving Trajectory");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_FLIP:
            ui->value_currentGoal->setText("Moving Flip");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_FLIP_BACK:
            ui->value_currentGoal->setText("Moving Flip Back");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_FLIP_FRONT:
            ui->value_currentGoal->setText("Moving Flip Front");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_FLIP_LEFT:
            ui->value_currentGoal->setText("Moving Flip Left");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_FLIP_RIGHT:
            ui->value_currentGoal->setText("Moving Flip Right");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_MANUAL_THRUST:
            ui->value_currentGoal->setText("Moving Manual Thrust");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_POSITION:
            ui->value_currentGoal->setText("Moving Position");
            break;
        case droneMsgsROS::droneManagerStatus::MOVING_SPEED:
            ui->value_currentGoal->setText("Moving Speed");
            break;
        case droneMsgsROS::droneManagerStatus::EMERGENCY:
            ui->value_currentGoal->setText("Emergency");
            break;
        case droneMsgsROS::droneManagerStatus::HOVERING:
            ui->value_currentGoal->setText("Hovering");
            break;
        case droneMsgsROS::droneManagerStatus::HOVERING_VISUAL_SERVOING:
            ui->value_currentGoal->setText("Hovering Visual Servoing");
            break;
        case droneMsgsROS::droneManagerStatus::LANDED:
            ui->value_currentGoal->setText("Landed");
            break;
        case droneMsgsROS::droneManagerStatus::LANDING:
            ui->value_currentGoal->setText("Landing");
            break;
        case droneMsgsROS::droneManagerStatus::UNKNOWN:
            ui->value_currentGoal->setText("Unknow");
            break;
        case droneMsgsROS::droneManagerStatus::TAKINGOFF:
            ui->value_currentGoal->setText("Taking Off");
            break;
        case droneMsgsROS::droneManagerStatus::SLEEPING:
            ui->value_currentGoal->setText("Sleeping");
            break;
        }

        if(connect->telemetry_receiver->battery_msgs.batteryPercent<=25.0&&connect->telemetry_receiver->battery_msgs.batteryPercent!=0){
            QPalette* palette = new QPalette();
            palette->setColor(QPalette::WindowText,Qt::red);
            ui->value_battery->setPalette(*palette);
        }
        ui->value_battery->setText(QString::number(connect->telemetry_receiver->battery_msgs.batteryPercent) +  "%");

        if(connect->graph_receiver->is_wifi_connected)
            ui->value_wifi->setText("Connected");
        else
            ui->value_wifi->setText("Disconnected");

        ui->value_task->setText(QString::number(connect->mission_planner_receiver->mission_info.idTask));
        ui->value_mission->setText(QString::number(connect->mission_planner_receiver->mission_info.idSubmission));
    }
}

void ControlPanel::setCurrentUAV()
{
    if(connect->rosnamespace.compare("/")!=0){
        char output[10012];
        strncpy(output, connect->rosnamespace.c_str(), sizeof(output));
        output[sizeof(output) - 1] = 0;
        char* process_name = strtok(output, "/drone");
        int drone_id = atoi( process_name );
            std::cout<<drone_id<<std::endl;
        ui->selection_vehicle->setCurrentIndex(drone_id);
    }
}


// User commands in GUI//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Control Mode
void ControlPanel::onControlModeChange(int key){
    std::cout<<key<<std::endl;
    if (connect->connect_status){
        switch(key)
        {
        case(0):
            std::cout<<"Changing to Autonomous Mode"<<std::endl;
            connect->mission_planner_receiver->activateAutonomousMode();
            current_control_mode=control_modes::autonomous;
            ui->selection_mode->setCurrentIndex(0);
            break;
        case(1):
            std::cout<<"Changing to Control Mode Position"<<std::endl;
            if(connect->mission_planner_receiver->is_autonomous_mode_active)
                connect->mission_planner_receiver->deactivateAutonomousMode();
            connect->usercommander->sendCommandInPositionControlMode(0.0, 0.0, 0.0);
            current_control_mode=control_modes::position;
            ui->selection_mode->setCurrentIndex(1);
            break;
        case(2):
            std::cout<<"Changing to Control Mode Altitude"<<std::endl;
            if(connect->mission_planner_receiver->is_autonomous_mode_active)
                connect->mission_planner_receiver->deactivateAutonomousMode();
            connect->usercommander->sendCommandInMovingManualAltitudMode(0.0,0.0,0.0,0.0);
            current_control_mode=control_modes::altitude;
            ui->selection_mode->setCurrentIndex(2);
            break;
        case(3):
            std::cout<<"Changing to Control Mode Speed"<<std::endl;
            if(connect->mission_planner_receiver->is_autonomous_mode_active)
                connect->mission_planner_receiver->deactivateAutonomousMode();
            connect->usercommander->sendCommandInSpeedControlMode(0.0, 0.0);
            current_control_mode=control_modes::speed;
            ui->selection_mode->setCurrentIndex(3);
            break;
        case(4):
            std::cout<<"Changing to Control Mode Visual Servoing"<<std::endl;
            if(connect->mission_planner_receiver->is_autonomous_mode_active)
                connect->mission_planner_receiver->deactivateAutonomousMode();
            connect->usercommander->sendCommandInVisualServoingMode();
            current_control_mode=control_modes::visual_servoing;
            ui->selection_mode->setCurrentIndex(4);
            break;
        }
    }
}

void ControlPanel::onTakeOffButton()
{
    std::cout<<"Take Off pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        std::vector<std::string> modules_takeoff=checkListToTakeOff();
        connect->usercommander->publish_takeoff(modules_takeoff);
    }
}

void ControlPanel::onLandButton()
{
    std::cout<<"Land pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        connect->usercommander->publish_land();
    }
}

void ControlPanel::onHoverButton()
{
    std::cout<<"Hover pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        connect->usercommander->publish_hover();
    }
}

void ControlPanel::onYawZeroButton()
{
    std::cout<<"Yaw zero pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        connect->usercommander->publish_yaw_zero();
    }
}

void ControlPanel::onEmergencyStopButton()
{
    std::cout<<"Emergency pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        connect->usercommander->publish_emergency();
    }
}

void ControlPanel::onLoopButton()
{
    std::cout<<"looping pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        connect->usercommander->sendCommandForLooping();
    }
}

void ControlPanel::onResetCommandButton()
{
    std::cout<<"Reset pressed buttom"<<std::endl;
    if (connect->connect_status){
        if(connect->mission_planner_receiver->is_autonomous_mode_active)
            connect->mission_planner_receiver->deactivateAutonomousMode();
        connect->usercommander->publish_reset();
    }
}


// Processes instances management///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



ControlPanel::~ControlPanel()
{
    delete ui;
}


