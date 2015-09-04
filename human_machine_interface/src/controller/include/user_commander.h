/**
 * @file /include/GroundControlSystem/usercommander.hpp
 *
 * @brief ROS node thread to publish topics.
 *
 * @date March 2015
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef USERCOMMANDER_H
#define USERCOMMANDER_H


/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include "droneMsgsROS/droneMissionPlannerCommand.h"
#include "droneMsgsROS/dronePitchRollCmd.h"
#include "droneMsgsROS/droneDYawCmd.h"
#include "droneMsgsROS/droneManagerStatus.h"
#include "droneMsgsROS/droneDAltitudeCmd.h"
#include "droneMsgsROS/dronePose.h"
#include "droneMsgsROS/dronePositionRefCommandStamped.h"
#include "droneMsgsROS/droneYawRefCommand.h"
#include <QThread>
#include "communication_definition.h"
#include <QStringListModel>


/*****************************************************************************
** Class
*****************************************************************************/

class UserCommander : public QThread {
    Q_OBJECT
public:
        UserCommander();
	virtual ~UserCommander();
        int command;
        void run();
        void  openPublications(ros::NodeHandle nodeHandle);


        droneMsgsROS::dronePitchRollCmd DronePitchRollCmdMsgs;
        droneMsgsROS::droneDAltitudeCmd DroneDAltitudeCmdMsgs;
        droneMsgsROS::droneDYawCmd DroneDYawCmdMsgs;
        droneMsgsROS::droneMissionPlannerCommand droneCommandMsgs;
        droneMsgsROS::droneManagerStatus droneManagerStatus;
        droneMsgsROS::droneManagerStatus lastDroneManagerStatusMsg;
        droneMsgsROS::dronePose currentDronePositionReference;
        droneMsgsROS::droneYawRefCommand droneYawReference;
        droneMsgsROS::dronePositionRefCommandStamped  dronePositionReference;


        droneMsgsROS::droneManagerStatus getDroneManagerStatus(){return lastDroneManagerStatusMsg;}

        void sendCommandInPositionControlMode(double controller_step_command_x, double controller_step_command_y, double controller_step_command_z);
        void sendYawCommandInPositionControlMode(double controller_step_command_yaw);
        void sendCommandInMovingManualAltitudMode(double cte_command_pitch, double cte_command_roll, double cte_command_height, double cte_command_yaw);

        void publish_takeoff();
        void processCommmand(int command);
        void publish_land();
        void publish_hover();

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
            Land,
            ControlModeAltitude,
            ControlModeSpeed,
            ControlModePosition
        };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);


Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();

private:
        std::vector<std::string> modules_names;

        std::string pitchroll_topic;
        std::string daltitude_topic;
        std::string dyawcmd_topic;
        std::string command_publish_topic;

        ros::Publisher DronePitchRollCmdPubl;
        ros::Publisher DroneDAltitudeCmdPubl;
        ros::Publisher DroneDYawCmdPubl;
        ros::Publisher droneCommandPubl;
        ros::Publisher dronePositionReferencePublisher;
        ros::Publisher droneYawReferencePublisher;

        ros::Subscriber droneManagerStatusSubs;

        void droneCurrentManagerStatusSubCallback(const droneMsgsROS::droneManagerStatus::ConstPtr &msg);

        QStringListModel logging_model;
};


#endif // USERCOMMANDER_H

