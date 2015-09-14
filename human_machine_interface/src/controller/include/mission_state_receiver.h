/**
 * @file /include/GroundControlSystem/collector.hpp
 *
 * @brief ROS node thread to subscribe topics.
 *
 * @date March 2015
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef GroundControlSystem_MISSIONSTATERECEIVER_HPP_
#define GroundControlSystem_MISSIONSTATERECEIVER_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"
#include "geometry_msgs/Point.h"
#include "droneMsgsROS/droneDYawCmd.h"
#include "droneMsgsROS/droneStatus.h"
#include "droneMsgsROS/droneDAltitudeCmd.h"
#include "droneMsgsROS/dronePitchRollCmd.h"
#include "communication_definition.h"
#include "sensor_msgs/Imu.h"
//Magnetometer and RotationAngles
#include "geometry_msgs/Vector3Stamped.h"

//Battery
#include "droneMsgsROS/battery.h"

//Altitude
#include "droneMsgsROS/droneAltitude.h"

#include "droneMsgsROS/dronePose.h"
//Ground Speed
#include "droneMsgsROS/vector2Stamped.h"
#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qthread.h>
#include <qt4/QtCore/QtDebug>
#include <qt4/Qt/qstringlistmodel.h>


/*****************************************************************************
** Class
*****************************************************************************/

class MissionStateReceiver: public QObject {
    Q_OBJECT
public:
         MissionStateReceiver();
	virtual ~ MissionStateReceiver();

        void run();
        bool ready();
        QString description;
        QString node_name;
        QString error_type;
        QString hostname;
        QString location;
        QString ns;
        QString action;




        QStringList fieldsMsgs;
        droneMsgsROS::dronePitchRollCmd DronePitchRollCmdMsgs;
        droneMsgsROS::droneDAltitudeCmd DroneDAltitudeCmdMsgs;
        droneMsgsROS::droneDYawCmd DroneDYawCmdMsgs;
        droneMsgsROS::dronePose DronePoseMsgs;




        geometry_msgs::Vector3Stamped MagnetometerMsgs;
        droneMsgsROS::battery BatteryMsgs;
        droneMsgsROS::droneAltitude AltitudeMsgs;
        geometry_msgs::Vector3Stamped RotationAnglesMsgs;
        droneMsgsROS::vector2Stamped GroundSpeedMsgs;
        sensor_msgs::Imu ImuMsgs;
        droneMsgsROS::droneStatus droneStatusMsgs;


        float time;
        double supervisorStateTime;

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
        void openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace);


Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();
        void parameterReceived();
        void updateStatus();
        void supervisorStateReceived( );


private:

	int init_argc;
        int real_time;
	char** init_argv;
        bool subscriptions_complete;
        ros::Subscriber DronePitchRollCmdSubs;
        ros::Subscriber DroneDAltitudeCmdSubs;
        ros::Subscriber DroneDYawCmdSubs;
        ros::Subscriber DroneCommandSubs;
        ros::Subscriber droneStatusSubs;
        void droneStatusCallback(const droneMsgsROS::droneStatus::ConstPtr& msg);

        ros::Subscriber MagnetometerSubs;
        void magnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

        ros::Subscriber BatterySubs;
        void batteryCallback(const droneMsgsROS::battery::ConstPtr& msg);

        ros::Subscriber AltitudeSubs;
        void altitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg);

        ros::Subscriber RotationAnglesSubs;
        void rotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

        ros::Subscriber GroundSpeedSubs;
        void groundSpeedCallback(const droneMsgsROS::vector2Stamped::ConstPtr& msg);

        ros::Subscriber ImuSubs;
        void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);

        ros::Subscriber dronePositionSubs;
        void dronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg);

        void droneDYawCmdCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg);
        void droneDAltitudeCmdCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);
        void dronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg);

        QStringListModel logging_model;
};


#endif /* GroundControlSystem_QNODE_HPP_ */
