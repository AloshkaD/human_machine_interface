/*
  uercommander
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

 UserCommander:: UserCommander(){}

 void UserCommander::openPublications(ros::NodeHandle nodeHandle){

      //Set params
      if (!nodeHandle.getParam("pitchroll_publish_topic", pitchroll_topic))
        pitchroll_topic = "command/pitch_roll";

      if (!nodeHandle.getParam("daltitude_publish_topic", daltitude_topic))
        daltitude_topic = "command/dAltitude";

      if (!nodeHandle.getParam("dyawcmd_publish_topic", dyawcmd_topic))
        dyawcmd_topic = "command/dYaw";

      if (!nodeHandle.getParam("command_publish_topic", command_publish_topic))
        command_publish_topic = "command/high_level";



     // Topic communications
     DronePitchRollCmdPubl=nodeHandle.advertise<droneMsgsROS::dronePitchRollCmd>(ros::this_node::getNamespace() + "/" + pitchroll_topic ,1, true);
     DroneDAltitudeCmdPubl=nodeHandle.advertise<droneMsgsROS::droneDAltitudeCmd>(ros::this_node::getNamespace() + "/" + daltitude_topic,1, true);
     DroneDYawCmdPubl=nodeHandle.advertise<droneMsgsROS::droneDYawCmd>(ros::this_node::getNamespace() + "/" + dyawcmd_topic,1, true);
     droneCommandPubl=nodeHandle.advertise<droneMsgsROS::droneMissionPlannerCommand>(ros::this_node::getNamespace() + "/" + command_publish_topic,1, true);

     start();
 }

 void UserCommander::run() {
     ros::spin();
     std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
     Q_EMIT rosShutdown(); // used to signal the gui for a shutdown
 }

 UserCommander::~ UserCommander() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
    wait();
}



void  UserCommander::publish_takeoff() {
       if(order==droneMsgsROS::droneMissionPlannerCommand::TAKE_OFF)
       {
           droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::TAKE_OFF;

           modules_names.push_back("droneOdometryStateEstimator");
           modules_names.push_back("droneTrajectoryController");
           modules_names.push_back("droneArucoEyeROSModule");
           modules_names.push_back("droneLocalizer");

           droneCommandMsgs.drone_modules_names = modules_names;
           droneCommandPubl.publish(droneCommandMsgs);
           log(Info,std::string("Human Machine Interface sent: ")+"take_off");
       }
       order=100; //clear command
}


void  UserCommander::publish_land() {
       if(order==droneMsgsROS::droneMissionPlannerCommand::LAND)
       {
           droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::LAND;
           droneCommandPubl.publish(droneCommandMsgs);
           log(Info,std::string("Human Machine Interface sent: ")+"land");
       }
       order=100; //clear command
}

void  UserCommander::publish_hover() {
       if(order==droneMsgsROS::droneMissionPlannerCommand::HOVER)
       {
           droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::HOVER;
           droneCommandPubl.publish(droneCommandMsgs);
           log(Info,std::string("Human Machine Interface sent: ")+"hover");
       }
       order=100; //clear command
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


