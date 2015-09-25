/*
  UserCommander
  Launch a ROS node to publish topics.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <sstream>
#include "../include/user_commander.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

UserCommander:: UserCommander(){
    subscriptions_complete = false;
}

void UserCommander::openPublications(ros::NodeHandle n, std::string rosnamespace){

    readParams(n);
    nodeHandle=n;
    drone=rosnamespace;
    // Topic communications
    drone_pitch_roll_cmd_publ=n.advertise<droneMsgsROS::dronePitchRollCmd>(rosnamespace + "/" + pitchroll_topic ,1, true);
    drone_daltitude_cmd_publisher=n.advertise<droneMsgsROS::droneDAltitudeCmd>(rosnamespace + "/" + daltitude_topic,1, true);
    drone_dyaw_cmd_publisher=n.advertise<droneMsgsROS::droneDYawCmd>(rosnamespace + "/" + dyawcmd_topic,1, true);
    drone_command_publisher=n.advertise<droneMsgsROS::droneMissionPlannerCommand>(rosnamespace + "/" + command_publish_topic,1, true);

    drone_position_reference_publisher = n.advertise<droneMsgsROS::dronePositionRefCommandStamped>(rosnamespace + "/" + drone_position_refs, 1);
    drone_yaw_reference_publisher = n.advertise<droneMsgsROS::droneYawRefCommand>(rosnamespace + "/" + drone_controller_yaw_ref_command, 1);
    drone_speeds_reference_publisher= n.advertise<droneMsgsROS::droneSpeeds>(rosnamespace + "/" + drone_speed_refs_topic, 1);

    drone_manager_status_subs  = n.subscribe(rosnamespace + "/" + drone_manager_status, 1, &UserCommander::droneCurrentManagerStatusSubCallback,this);
    drone_pos_reference_subs = n.subscribe(rosnamespace + "/" + drone_pos_rebroadcast_topic, 1, &UserCommander::droneCurrentPositionRefsSubCallback,this);
    drone_speed_reference_subscriber = n.subscribe(rosnamespace + "/" + drone_speed_refs_topic, 1, &UserCommander::droneCurrentSpeedsRefsSubCallback, this);
    drone_hl_comm_ack_subs = n.subscribe(rosnamespace + "/" + drone_hl_comm_ack_topic,1,&UserCommander::managerAckCallback,this);

    subscriptions_complete = true;

}

void UserCommander::readParams(ros::NodeHandle n)
{
    //Set params
    if (!n.getParam("pitchroll_topic", pitchroll_topic))
        pitchroll_topic = "command/pitch_roll";

    if (!n.getParam("daltitude_topic", daltitude_topic))
        daltitude_topic = "command/dAltitude";

    if (!n.getParam("dyawcmd_topic", dyawcmd_topic))
        dyawcmd_topic = "command/dYaw";

    if (!n.getParam("command_publish_topic", command_publish_topic))
        command_publish_topic = "droneMissionPlannerCommand";

    if (!n.getParam("drone_position_refs", drone_position_refs))
        drone_position_refs = "dronePositionRefs";

    if (!n.getParam("drone_controller_yaw_ref_command", drone_controller_yaw_ref_command))
        drone_controller_yaw_ref_command = "droneControllerYawRefCommand";

    if (!n.getParam("drone_speed_refs_topic", drone_speed_refs_topic))
        drone_speed_refs_topic = "droneSpeedsRefs";

    if (!n.getParam("drone_manager_status", drone_manager_status))
        drone_manager_status = "droneManagerStatus";

    if (!n.getParam("drone_position_rebroadcast", drone_pos_rebroadcast_topic))
        drone_pos_rebroadcast_topic = "trajectoryControllerPositionReferencesRebroadcast";

    if (!n.getParam("drone_speed_rebroadcast", drone_speed_rebroadcast_topic))
        drone_speed_rebroadcast_topic = "trajectoryControllerSpeedReferencesRebroadcast";

    if (!n.getParam("drone_hl_comm_ack_topic", drone_hl_comm_ack_topic))
        drone_hl_comm_ack_topic = "droneMissionHLCommandAck";

}

bool UserCommander::ready() {
    if (!subscriptions_complete)
        return false;
    return true; //Used this way instead of "return subscriptions_complete" due to preserve add more conditions
}

UserCommander::~ UserCommander() {}



void UserCommander::sendCommandInVisualServoingMode()
{
    std::cout<<"comand move() IN VISUAL SERVOING sent"<<std::endl;
    droneCommandMsgs.mpCommand =droneMsgsROS::droneMissionPlannerCommand::MOVE_VISUAL_SERVOING;
    droneCommandMsgs.drone_modules_names.clear();
    std::vector<std::string> modules_names;
    modules_names.push_back("droneOdometryStateEstimator");
    droneCommandMsgs.drone_modules_names = modules_names;
    drone_command_publisher.publish(droneCommandMsgs);
    ros::spinOnce();
}

void UserCommander::sendCommandForLooping()
{
    std::cout<<"Command loop() sent"<<std::endl;
    clearCmd();
    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::MOVE_FLIP_FRONT;
//    msg.drone_modules_names.clear();
//    std::vector<std::string> modules_names;
//    modules_names.push_back(MODULE_NAME_ODOMETRY_STATE_ESTIMATOR);
//    msg.drone_modules_names = modules_names;
    drone_command_publisher.publish(droneCommandMsgs);
    log(Info,std::string("Human Machine Interface sent: ")+"looping");
}

void UserCommander::sendCommandInSpeedControlMode(double vxfi, double vyfi)
{
    std::cout<<"comand move() IN SPEED sent"<<std::endl;
    droneCommandMsgs.mpCommand =droneMsgsROS::droneMissionPlannerCommand::MOVE_SPEED;
    droneCommandMsgs.drone_modules_names.clear();
    drone_command_publisher.publish(droneCommandMsgs);

    if(vxfi !=0 || vyfi != 0)
    {
        double current_vxfi, current_vyfi;
        current_vxfi = current_drone_speed_reference.dx;
        current_vyfi = current_drone_speed_reference.dy;

        std::cout<<"Speed reference: " <<std::endl;
        std::cout<<"current speed x: "+ boost::lexical_cast<std::string>(current_drone_speed_reference.dx) + " current speed y: "+ boost::lexical_cast<std::string>(current_drone_speed_reference.dy) <<std::endl;

        if(vxfi == 0.0)
            vxfi = current_vxfi;
        if(vyfi == 0.0)
            vyfi = current_vyfi;

        drone_speed_reference.time = ros::Time::now().toSec();
        drone_speed_reference.dx = vxfi;
        drone_speed_reference.dy = vyfi;
        drone_speed_reference.dz     = 0.0;
        drone_speed_reference.dyaw   = 0.0;
        drone_speed_reference.dpitch = 0.0;
        drone_speed_reference.droll  = 0.0;

        drone_speeds_reference_publisher.publish(drone_speed_reference);
    }
}

void UserCommander::sendCommandInMovingManualAltitudMode(double cte_command_pitch, double cte_command_roll, double cte_command_height, double cte_command_yaw)
{
    std::cout<<"Command move() sent"<<std::endl;


    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::MOVE_MANUAL_ALTITUD;
    drone_command_publisher.publish(droneCommandMsgs);

    if(cte_command_pitch != 0.0)
    {
        dronePitchRollCmdMsgs.pitchCmd = cte_command_pitch;
        drone_pitch_roll_cmd_publ.publish(dronePitchRollCmdMsgs);
    }

    if(cte_command_roll != 0.0)
    {
        dronePitchRollCmdMsgs.rollCmd = cte_command_roll;
        drone_pitch_roll_cmd_publ.publish(dronePitchRollCmdMsgs);
    }

    if(cte_command_height != 0.0)
    {
        droneDAltitudeCmdMsgs.dAltitudeCmd = cte_command_height;
        drone_daltitude_cmd_publisher.publish(droneDAltitudeCmdMsgs);
    }
    if(cte_command_yaw != 0.0)
    {
        droneDYawCmdMsgs.dYawCmd = cte_command_yaw;
        drone_dyaw_cmd_publisher.publish(droneDYawCmdMsgs);
    }

}

void UserCommander::sendCommandInPositionControlMode(double controller_step_command_x, double controller_step_command_y, double controller_step_command_z)
{
    std::cout<<"comand move() IN POSITION sent"<<std::endl;

    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::MOVE_POSITION;
    droneCommandMsgs.drone_modules_names.clear();
    drone_command_publisher.publish(droneCommandMsgs);


    if(controller_step_command_x !=0 || controller_step_command_y != 0 || controller_step_command_z != 0)
    {
        double current_xs, current_ys, current_zs;
        current_xs = current_drone_position_reference.x;
        current_ys = current_drone_position_reference.y;
        current_zs = current_drone_position_reference.z;
        std::cout<<"Position reference: " <<std::endl;
        std::cout<<"current pos.x: "+ boost::lexical_cast<std::string>(current_drone_position_reference.x) + " current pos.y: " + boost::lexical_cast<std::string>(current_drone_position_reference.y) + " current pos.z: "+ boost::lexical_cast<std::string>(current_drone_position_reference.z)  <<std::endl;


        dronePositionReference.header.stamp  = ros::Time::now();
        dronePositionReference.position_command.x = current_xs + controller_step_command_x;
        dronePositionReference.position_command.y = current_ys + controller_step_command_y;
        dronePositionReference.position_command.z = current_zs + controller_step_command_z;


        drone_position_reference_publisher.publish(dronePositionReference);
        log(Info,std::string("Human Machine Interface sent: ")+"position command");
    }
}

void UserCommander::sendYawCommandInPositionControlMode(double controller_step_command_yaw)
{
    std::cout<<"comand move() IN POSITION sent"<<std::endl;
    droneCommandMsgs.mpCommand =  droneMsgsROS::droneMissionPlannerCommand::MOVE_POSITION;
    droneCommandMsgs.drone_modules_names.clear();
    drone_command_publisher.publish(droneCommandMsgs);


    double current_yaws = current_drone_position_reference.yaw;
    droneYawReference.header.stamp = ros::Time::now();
    droneYawReference.yaw = current_yaws + controller_step_command_yaw;
    std::cout<<"Yaw reference: " <<std::endl;
    std::cout<<"current yaw: "+ boost::lexical_cast<std::string>(droneYawReference.yaw) <<std::endl;

    drone_yaw_reference_publisher.publish(droneYawReference);
    log(Info,std::string("Human Machine Interface sent: ")+"dyawcommand");
}


void  UserCommander::publish_takeoff(std::vector<std::string> modules_takeoff)
{
    std::cout<<"Command takeoff sent"<<std::endl;
    for(std::vector<std::string>::const_iterator i = modules_takeoff.begin(); i != modules_takeoff.end(); ++i) {
        modules_names.push_back(*i);
        std::cout << *i << std::endl;
    }
    clearCmd();//clear command
    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::TAKE_OFF;

    modules_names.push_back("droneOdometryStateEstimator");

    droneCommandMsgs.drone_modules_names = modules_names;
    drone_command_publisher.publish(droneCommandMsgs);
    log(Info,std::string("Human Machine Interface sent: ")+"take_off");

}

void  UserCommander::publish_land()
{
    std::cout<<"Command land() sent"<<std::endl;
    clearCmd(); //clear command
    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::LAND;
    drone_command_publisher.publish(droneCommandMsgs);
    log(Info,std::string("Human Machine Interface sent: ")+"land");
}

void  UserCommander::publish_hover()
{
    std::cout<<"Command hover() sent"<<std::endl;
    clearCmd();//clear command
    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::HOVER;
    droneCommandMsgs.drone_modules_names.clear();
   // std::vector<std::string> modules_names;
    //modules_names.push_back("droneOdometryStateEstimator");
   // droneCommandMsgs.drone_modules_names = modules_names;
    drone_command_publisher.publish(droneCommandMsgs);

}

void  UserCommander::publish_yaw_zero()
{
    std::cout<<"Command yaw zero sent"<<std::endl;
    droneDYawCmdMsgs.dYawCmd = 0.0;
    drone_dyaw_cmd_publisher.publish(droneDYawCmdMsgs);
    log(Info,std::string("Human Machine Interface sent: ")+"yaw zero");
}

void  UserCommander::publish_emergency()
{
    std::cout<<"Command emergency() sent"<<std::endl;
    clearCmd(); //clear command
    droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::EMERGENCY;
    drone_command_publisher.publish(droneCommandMsgs);
    log(Info,std::string("Human Machine Interface sent: ")+"emergency");
}

void UserCommander::clearCmd()
{
    dronePitchRollCmdMsgs.pitchCmd=0.0;
    dronePitchRollCmdMsgs.rollCmd=0.0;
    droneDAltitudeCmdMsgs.dAltitudeCmd=0.0;
    droneDYawCmdMsgs.dYawCmd=0.0;
}


void  UserCommander::droneCurrentManagerStatusSubCallback(const droneMsgsROS::droneManagerStatus::ConstPtr &msg)
{

    lastDroneManagerStatusMsg = (*msg);
        switch(lastDroneManagerStatusMsg.status)
        {
            case droneMsgsROS::droneManagerStatus::HOVERING:
                std::cout<<"Manager Status: HOVERING"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::LANDING:
                std::cout<<"Manager Status: LANDING"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::LANDED:
                std::cout<<"Manager Status: LANDED"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::TAKINGOFF:
                std::cout<<"Manager Status: TAKINGOFF"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD:
                std::cout<<"Manager Status: MOVING MANUAL ALTITUD"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::MOVING_POSITION:
                std::cout<<"Manager Status: MOVING POSITION"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::MOVING_SPEED:
                std::cout<<"Manager Status: MOVING SPEED"<<std::endl;
                break;

            case droneMsgsROS::droneManagerStatus::MOVING_TRAJECTORY:
                std::cout<<"Manager Status: MOVING TRAJECTORY"<<std::endl;
                break;
        }
     Q_EMIT managerStatusReceived();
}

void UserCommander::managerAckCallback(const droneMsgsROS::droneHLCommandAck::ConstPtr& msg)
{
    std::cout<<"Human Machine Interface: Received manager confirmation:"<<std::endl;
    droneHLCommAckMsg.time = msg->time;
    droneHLCommAckMsg.ack = msg->ack;

    if(droneHLCommAckMsg.ack)
        std::cout<<"Manager ack TRUE"<<std::endl;
    else if(!droneHLCommAckMsg.ack)
        std::cout<<"Manager ack FALSE"<<std::endl;

    return;
}

void UserCommander::droneCurrentPositionRefsSubCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    current_drone_position_reference = (*msg);
}

void UserCommander::droneCurrentSpeedsRefsSubCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg)
{
    current_drone_speed_reference = (*msg);
}


/* Stop/Start/Reset Modules*/

void UserCommander::processMonitorCommander(std::string moduleName,int command)
{
    std_srvs::Empty emptySrvMsg;
    switch(command){
    case processMonitorStates::Start:
        std::cout<<"Start module: " + moduleName <<std::endl;
        modules_srv_stop=nodeHandle.serviceClient<std_srvs::Empty>("/" + drone +  "/" + moduleName + "/start");
        modules_srv_stop.call(emptySrvMsg);
        break;
    case processMonitorStates::Stop:
        std::cout<<"Stop module: " + moduleName <<std::endl;
        modules_srv_start=nodeHandle.serviceClient<std_srvs::Empty>("/" + drone +  "/" + moduleName + "/stop");
        modules_srv_start.call(emptySrvMsg);
        break;
    case processMonitorStates::Reset:
        std::cout<<"Reset module: " + moduleName <<std::endl;
        modules_srv_reset=nodeHandle.serviceClient<std_srvs::Empty>("/" + drone +  "/" + moduleName + "/reset");
        modules_srv_reset.call(emptySrvMsg);
        break;
    }
}



/*

void  UserCommander::publish_reset() {
       if(order==droneMsgsROS::droneCommand::RESET)
       {
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::RESET;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"reset");
       }
       order=100; //clear command
}


void  UserCommander::publish_emergencyStop() {
       if(order==droneMsgsROS::droneCommand::EMERGENCY_STOP)
       {
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::EMERGENCY_STOP;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"emergency stop");
       }
       order=100; //clear command
}


void  UserCommander::publish_LLCommand() {
       /*if(order==7){ //
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::EMERGENCY_STOP;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"emergency stop");
       }
       order=100; //clear command
}

*/
void  UserCommander::log( const LogLevel &level, const std::string &msg) {
    logging_model.insertRows(logging_model.rowCount(),1);
    std::stringstream logging_model_msg;
    switch ( level ) {
        case(Debug) : {
                ROS_DEBUG_STREAM(msg);
                logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Info) : {
                ROS_INFO_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Warn) : {
                ROS_WARN_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Error) : {
                ROS_ERROR_STREAM(msg);
                logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Fatal) : {
                ROS_FATAL_STREAM(msg);
                logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
                break;
        }
    }
    QVariant new_row(QString(logging_model_msg.str().c_str()));
    logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
    Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}


