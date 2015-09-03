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
#include "droneMsgsROS/droneCommand.h"
#include "droneMsgsROS/dronePitchRollCmd.h"
#include "droneMsgsROS/droneDYawCmd.h"
#include "droneMsgsROS/droneDAltitudeCmd.h"
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
        int order;
        void run();
        void  openPublications(ros::NodeHandle nodeHandle);


        droneMsgsROS::dronePitchRollCmd DronePitchRollCmdMsgs;
        droneMsgsROS::droneDAltitudeCmd DroneDAltitudeCmdMsgs;
        droneMsgsROS::droneDYawCmd DroneDYawCmdMsgs;
        droneMsgsROS::droneCommand DroneCommandMsgs;




        void publish_takeoff();
        void publish_land();
        void publish_reset();
        void publish_hover();
        void publish_emergencyStop();
        void publish_LLCommand();


	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);


Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();

private:
        ros::MultiThreadedSpinner threadSpin;
	ros::Publisher gcs_publisher;
        ros::Publisher DronePitchRollCmdPubl;
        ros::Publisher DroneDAltitudeCmdPubl;
        ros::Publisher DroneDYawCmdPubl;
        ros::Publisher DroneCommandPubl;
        QStringListModel logging_model;
};


#endif // USERCOMMANDER_H

