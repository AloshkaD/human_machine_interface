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
#include "../include/usercommander.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

 UserCommander:: UserCommander()
 {

 }

 void UserCommander::openPublications(ros::NodeHandle nodeHandle){
     // Topic communications
     DronePitchRollCmdPubl=nodeHandle.advertise<droneMsgsROS::dronePitchRollCmd>("drone0/" + DRONE_CONSOLE_INTERFACE_COMMAND_DRONE_COMMAND_PITCH_ROLL_PUBLICATION,1, true);
     DroneDAltitudeCmdPubl=nodeHandle.advertise<droneMsgsROS::droneDAltitudeCmd>("drone0/" + DRONE_CONSOLE_INTERFACE_COMMAND_DRONE_COMMAND_DALTITUDE_PUBLICATION,1, true);
     DroneDYawCmdPubl=nodeHandle.advertise<droneMsgsROS::droneDYawCmd>("drone0/" + DRONE_CONSOLE_INTERFACE_COMMAND_DRONE_COMMAND_DYAW_PUBLICATION,1, true);
     DroneCommandPubl=nodeHandle.advertise<droneMsgsROS::droneCommand>("drone0/" + DRONE_CONSOLE_INTERFACE_COMMAND_DRONE_HL_COMMAND_PUBLICATION,1, true);

     start();
 }

 UserCommander::~ UserCommander() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
    wait();
}



void  UserCommander::publish_takeoff() {
       if(order==droneMsgsROS::droneCommand::TAKE_OFF)
       {
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::TAKE_OFF;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"take_off");
       }
       order=100; //clear command
}

void  UserCommander::publish_land() {
       if(order==droneMsgsROS::droneCommand::LAND)
       {
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::LAND;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"land");
       }
       order=100; //clear command
}

void  UserCommander::publish_reset() {
       if(order==droneMsgsROS::droneCommand::RESET)
       {
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::RESET;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"reset");
       }
       order=100; //clear command
}

void  UserCommander::publish_hover() {
       if(order==droneMsgsROS::droneCommand::HOVER)
       {
       DroneCommandMsgs.command = droneMsgsROS::droneCommand::HOVER;
       DroneCommandPubl.publish(DroneCommandMsgs);
       log(Info,std::string("Human Machine Interface sent: ")+"hover");
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
       order=100; //clear command*/
}


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


