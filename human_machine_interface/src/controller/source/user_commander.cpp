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

      if (!nodeHandle.getParam("command_publish_topic", command_publish_topic))
        command_publish_topic = "command/high_level";


     // Topic communications
     dronePitchRollCmdPubl=nodeHandle.advertise<droneMsgsROS::dronePitchRollCmd>(ros::this_node::getNamespace() + "/" + pitchroll_topic ,1, true);
     droneDAltitudeCmdPubl=nodeHandle.advertise<droneMsgsROS::droneDAltitudeCmd>(ros::this_node::getNamespace() + "/" + daltitude_topic,1, true);
     droneDYawCmdPubl=nodeHandle.advertise<droneMsgsROS::droneDYawCmd>(ros::this_node::getNamespace() + "/" + dyawcmd_topic,1, true);
     droneCommandPubl=nodeHandle.advertise<droneMsgsROS::droneMissionPlannerCommand>(ros::this_node::getNamespace() + "/" + command_publish_topic,1, true);
     dronePositionReferencePublisher = nodeHandle.advertise<droneMsgsROS::dronePositionRefCommandStamped>("dronePositionRefs", 1);
     droneYawReferencePublisher = nodeHandle.advertise<droneMsgsROS::droneYawRefCommand>("droneControllerYawRefCommand", 1);
     drone_speeds_reference_publisher     = nodeHandle.advertise<droneMsgsROS::droneSpeeds>("droneSpeedsRefs", 1);
     drone_rel_trajectory_reference_publisher = nodeHandle.advertise<droneMsgsROS::dronePositionTrajectoryRefCommand>("droneTrajectoryRefCommand", 1);

     droneManagerStatusSubs  = nodeHandle.subscribe("droneManagerStatus", 1, &UserCommander::droneCurrentManagerStatusSubCallback,this);

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

 void UserCommander::sendCommandInSpeedControlMode(double vxfi, double vyfi)
 {
     std::cout<<"comand move() IN SPEED sent"<<std::endl;
     droneCommandMsgs.mpCommand =droneMsgsROS::droneMissionPlannerCommand::MOVE_SPEED;
     droneCommandPubl.publish(droneCommandMsgs);


 //    drone_speed_reference.target_frame = "drone_GMR";
 //    drone_speed_reference.reference_frame = "GFF";
 //    drone_speed_reference.YPR_system = "wYvPuR";

     if(vxfi !=0 || vyfi != 0)
     {
         double current_vxfi, current_vyfi;
         current_vxfi = current_drone_speed_reference.dx;
         current_vyfi = current_drone_speed_reference.dy;

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

     droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::MOVE_POSITION;
     droneCommandPubl.publish(droneCommandMsgs);

     if(cte_command_pitch != 0.0)
     {
         dronePitchRollCmdMsgs.pitchCmd = cte_command_pitch;
         dronePitchRollCmdPubl.publish(dronePitchRollCmdMsgs);
     }

     if(cte_command_roll != 0.0)
     {
         dronePitchRollCmdMsgs.rollCmd = cte_command_roll;
         dronePitchRollCmdPubl.publish(dronePitchRollCmdMsgs);
     }

     if(cte_command_height != 0.0)
     {
         droneDAltitudeCmdMsgs.dAltitudeCmd = cte_command_height;
         droneDAltitudeCmdPubl.publish(droneDAltitudeCmdMsgs);
     }
     if(cte_command_yaw != 0.0)
     {
         droneDYawCmdMsgs.dYawCmd = cte_command_yaw;
         droneDYawCmdPubl.publish(droneDYawCmdMsgs);
     }

 }

 void UserCommander::sendCommandInPositionControlMode(double controller_step_command_x, double controller_step_command_y, double controller_step_command_z)
 {
     std::cout<<"comand move() IN POSITION sent"<<std::endl;

     droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::MOVE_POSITION;
     droneCommandPubl.publish(droneCommandMsgs);

 //    double current_xs, current_ys, current_zs, current_yaws;
 //    current_xs = last_drone_estimated_GMRwrtGFF_pose.x;
 //    current_ys = last_drone_estimated_GMRwrtGFF_pose.y;
 //    current_zs = last_drone_estimated_GMRwrtGFF_pose.z;
 //    current_yaws = last_drone_estimated_GMRwrtGFF_pose.yaw;

     if(controller_step_command_x !=0 || controller_step_command_y != 0 || controller_step_command_z != 0)
     {
         double current_xs, current_ys, current_zs;
         current_xs = current_drone_position_reference.x;
         current_ys = current_drone_position_reference.y;
         current_zs = current_drone_position_reference.z;


         dronePositionReference.header.stamp  = ros::Time::now();
         dronePositionReference.position_command.x = current_xs + controller_step_command_x;
         dronePositionReference.position_command.y = current_ys + controller_step_command_y;
         dronePositionReference.position_command.z = current_zs + controller_step_command_z;


         dronePositionReferencePublisher.publish(dronePositionReference);
         log(Info,std::string("Human Machine Interface sent: ")+"position command");
     }
 }

 void UserCommander::sendYawCommandInPositionControlMode(double controller_step_command_yaw)
 {
     std::cout<<"comand move() IN POSITION sent"<<std::endl;
     droneCommandMsgs.mpCommand =  droneMsgsROS::droneMissionPlannerCommand::MOVE_POSITION;
     droneCommandPubl.publish(droneCommandMsgs);


     double current_yaws = current_drone_position_reference.yaw;
     droneYawReference.header.stamp = ros::Time::now();
     droneYawReference.yaw = current_yaws + controller_step_command_yaw;

     droneYawReferencePublisher.publish(droneYawReference);
     log(Info,std::string("Human Machine Interface sent: ")+"dyawcommand");
 }


void  UserCommander::publish_takeoff() {
           std::cout<<"Command takeoff sent"<<std::endl;
           clearCmd();//clear command
           droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::TAKE_OFF;

           modules_names.push_back("droneOdometryStateEstimator");
           modules_names.push_back("droneTrajectoryController");
           modules_names.push_back("droneArucoEyeROSModule");
           modules_names.push_back("droneLocalizer");

           droneCommandMsgs.drone_modules_names = modules_names;
           droneCommandPubl.publish(droneCommandMsgs);
           log(Info,std::string("Human Machine Interface sent: ")+"take_off");

}

void  UserCommander::droneCurrentManagerStatusSubCallback(const droneMsgsROS::droneManagerStatus::ConstPtr &msg) {

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

}


void  UserCommander::publish_land() {
           std::cout<<"Command land() sent"<<std::endl;
           clearCmd(); //clear command
           droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::LAND;
           droneCommandPubl.publish(droneCommandMsgs);
           log(Info,std::string("Human Machine Interface sent: ")+"land");     
}

void  UserCommander::publish_hover() {
           std::cout<<"Command hover() sent"<<std::endl;
           clearCmd();//clear command
           droneCommandMsgs.mpCommand = droneMsgsROS::droneMissionPlannerCommand::HOVER;
           droneCommandPubl.publish(droneCommandMsgs);
           log(Info,std::string("Human Machine Interface sent: ")+"hover");

}

void UserCommander::clearCmd()
{
    dronePitchRollCmdMsgs.pitchCmd=0.0;
    dronePitchRollCmdMsgs.rollCmd=0.0;
    droneDAltitudeCmdMsgs.dAltitudeCmd=0.0;
    droneDYawCmdMsgs.dYawCmd=0.0;
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


