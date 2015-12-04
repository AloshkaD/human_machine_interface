/*!*******************************************************************************************
 *  \file       user_commander.h
 *  \brief      UserCommander definition file.
 *  \details    This file includes the UserCommander class declaration. To obtain more
 *              information about it's definition consult the user_commander.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef USERCOMMANDER_H
#define USERCOMMANDER_H

#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>

#include "droneMsgsROS/droneMissionPlannerCommand.h"

#include <droneMsgsROS/dronePitchRollCmd.h>
#include <droneMsgsROS/droneDYawCmd.h>
#include "droneMsgsROS/droneManagerStatus.h"
#include <droneMsgsROS/droneDAltitudeCmd.h>
#include <droneMsgsROS/dronePose.h>
#include "droneMsgsROS/droneStatus.h"
#include "droneMsgsROS/behaviorRequest.h"
#include <droneMsgsROS/dronePositionRefCommandStamped.h>
#include <droneMsgsROS/droneYawRefCommand.h>
#include <droneMsgsROS/dronePitchRollCmd.h>
#include <droneMsgsROS/dronePositionTrajectoryRefCommand.h>
#include <droneMsgsROS/droneSpeeds.h>
#include <droneMsgsROS/droneHLCommandAck.h>
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"
//#include "../include/behaviour_viewer.h"
//#include "behaviour_viewer.h"


#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qthread.h>
#include <qt4/QtCore/QtDebug>
#include <qt4/Qt/qstringlistmodel.h>



class UserCommander : public QObject {
    Q_OBJECT
public:
    UserCommander();
    virtual ~UserCommander();

    bool ready();
    void openPublications(ros::NodeHandle nodeHandle, std::string rosnamespace);

    void sendCommandInPositionControlMode(double controller_step_command_x, double controller_step_command_y, double controller_step_command_z);
    void sendYawCommandInPositionControlMode(double controller_step_command_yaw);
    void sendCommandInMovingManualAltitudMode(double cte_command_pitch, double cte_command_roll, double cte_command_height, double cte_command_yaw);
    void sendCommandInSpeedControlMode(double vxfi, double vyfi);
    void sendCommandInVisualServoingMode();
    void sendCommandForLooping();

    void processMonitorCommander(std::string moduleName, int command);
    void clearCmd();
    void publish_takeoff(std::vector<std::string> modules_takeoff);
    void publish_land();
    void publish_hover();
    void publish_yaw_zero();
    void publish_reset();
    void publish_emergency();



    void readParams(ros::NodeHandle n);

    droneMsgsROS::droneManagerStatus getDroneManagerStatus(){return lastDroneManagerStatusMsg;}


    /*void publish_reset();
        void publish_emergencyStop();
        void publish_LLCommand();*/


    enum LogLevel {
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    };

    enum userCommands {
        TakeOff,
        Hover,
        Land
    };


    enum processMonitorStates {
        Start,
        Stop,
        Reset
    };

    QStringListModel* loggingModel() { return &logging_model; }
    void log( const LogLevel &level, const std::string &msg);


Q_SIGNALS:
    void loggingUpdated();
    void parameterReceived();
    void updateStatus();
    void managerStatusReceived();

private:
    bool subscriptions_complete;
    ros::NodeHandle nodeHandle;
    std::string drone;
    std::vector<std::string> modules_names;

    droneMsgsROS::dronePitchRollCmd dronePitchRollCmdMsgs;
    droneMsgsROS::droneDAltitudeCmd droneDAltitudeCmdMsgs;
    droneMsgsROS::droneDYawCmd droneDYawCmdMsgs;
    droneMsgsROS::droneMissionPlannerCommand droneCommandMsgs;
    droneMsgsROS::droneManagerStatus droneManagerStatus;
    droneMsgsROS::droneManagerStatus lastDroneManagerStatusMsg;
    droneMsgsROS::droneYawRefCommand droneYawReference;
    droneMsgsROS::dronePositionRefCommandStamped  dronePositionReference;
    droneMsgsROS::dronePositionTrajectoryRefCommand drone_trajectory_reference;
    droneMsgsROS::droneSpeeds drone_speed_reference;
    droneMsgsROS::dronePose   current_drone_position_reference;
    droneMsgsROS::droneSpeeds current_drone_speed_reference;
    droneMsgsROS::droneHLCommandAck droneHLCommAckMsg;

    std::string pitchroll_topic;
    std::string daltitude_topic;
    std::string dyawcmd_topic;
    std::string command_publish_topic;
    std::string drone_position_refs;
    std::string drone_pos_rebroadcast_topic;
    std::string drone_speed_refs_topic;
    std::string drone_controller_yaw_ref_command;
    std::string drone_manager_status;
    std::string drone_estimated_pos_topic;
    std::string drone_speed_rebroadcast_topic;
    std::string drone_hl_comm_ack_topic;

    ros::Publisher drone_pitch_roll_cmd_publ;
    ros::Publisher drone_daltitude_cmd_publisher;
    ros::Publisher drone_dyaw_cmd_publisher;
    ros::Publisher drone_command_publisher;
    ros::Publisher drone_position_reference_publisher;
    ros::Publisher drone_yaw_reference_publisher;
    ros::Publisher drone_speeds_reference_publisher;
    ros::Publisher drone_rel_trajectory_reference_publisher;

    ros::Subscriber drone_manager_status_subs;
    ros::Subscriber drone_pos_reference_subs;
    ros::Subscriber drone_estimated_pose_subs;
    ros::Subscriber drone_speed_reference_subscriber;
    ros::Subscriber drone_hl_comm_ack_subs;

    ros::ServiceClient modules_srv_start;
    ros::ServiceClient modules_srv_stop;
    ros::ServiceClient modules_srv_reset;
    ros::ServiceClient request_srv_behavior;

    void droneCurrentManagerStatusSubCallback(const droneMsgsROS::droneManagerStatus::ConstPtr &msg);
    void droneCurrentSpeedsRefsSubCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);
    void droneCurrentPositionRefsSubCallback(const droneMsgsROS::dronePose::ConstPtr &msg);
    void managerAckCallback(const droneMsgsROS::droneHLCommandAck::ConstPtr &msg);
    void request_behavior(std::string current_behavior_name,bool status);

    QStringListModel logging_model;
};


#endif // USERCOMMANDER_H

