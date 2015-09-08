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
#include "droneMsgsROS/droneStatus.h"
#include "droneMsgsROS/dronePositionRefCommandStamped.h"
#include "droneMsgsROS/droneYawRefCommand.h"
#include "droneMsgsROS/dronePitchRollCmd.h"
#include "droneMsgsROS/dronePositionTrajectoryRefCommand.h"
#include "droneMsgsROS/droneSpeeds.h"
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

        void run();
        void  openPublications(ros::NodeHandle nodeHandle);


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
        std::string rosnamespace;


        droneMsgsROS::droneManagerStatus getDroneManagerStatus(){return lastDroneManagerStatusMsg;}

        void sendCommandInPositionControlMode(double controller_step_command_x, double controller_step_command_y, double controller_step_command_z);
        void sendYawCommandInPositionControlMode(double controller_step_command_yaw);
        void sendCommandInMovingManualAltitudMode(double cte_command_pitch, double cte_command_roll, double cte_command_height, double cte_command_yaw);
        void sendCommandInSpeedControlMode(double vxfi, double vyfi);

        void clearCmd();

        void publish_takeoff();
        void publish_land();
        void publish_hover();
        void publish_yaw_zero();

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
        std::string drone_position_refs;
        std::string drone_speed_refs_topic;
        std::string drone_controller_yaw_ref_command;
        std::string drone_manager_status;

        ros::Publisher dronePitchRollCmdPubl;
        ros::Publisher droneDAltitudeCmdPubl;
        ros::Publisher droneDYawCmdPubl;
        ros::Publisher droneCommandPubl;
        ros::Publisher dronePositionReferencePublisher;
        ros::Publisher droneYawReferencePublisher;
        ros::Publisher drone_position_reference_publisher;
        ros::Publisher drone_speeds_reference_publisher;
        ros::Publisher drone_rel_trajectory_reference_publisher;

        ros::Subscriber droneManagerStatusSubs;

        void droneCurrentManagerStatusSubCallback(const droneMsgsROS::droneManagerStatus::ConstPtr &msg);

        QStringListModel logging_model;
};


#endif // USERCOMMANDER_H

