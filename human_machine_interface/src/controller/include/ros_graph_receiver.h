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

#ifndef HumanMachineInterface_ROSGRAPHRECEIVER_H
#define HumanMachineInterface_ROSGRAPHRECEIVER_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QString>
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"
#include "geometry_msgs/Point.h"
#include "droneMsgsROS/droneDYawCmd.h"
#include "droneMsgsROS/droneStatus.h"
#include "droneMsgsROS/droneDAltitudeCmd.h"
#include "droneMsgsROS/dronePitchRollCmd.h"
#include "communication_definition.h"
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
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
#include <QThread>
#include <QString>
#include <QStringListModel>


/*****************************************************************************
** Class
*****************************************************************************/

class RosGraphReceiver: public QThread {
    Q_OBJECT
public:
         RosGraphReceiver();
	virtual ~ RosGraphReceiver();

        void run();
        QString description;
        QString node_name;
        QString error_type;
        QString hostname;
        QString location;
        QString ns;
        QString action;



        droneMsgsROS::ProcessDescriptorList listProcessState;
        droneMsgsROS::ProcessDescriptor node_container;
        droneMsgsROS::droneStatus droneStatusMsgs;
        double supervisorStateTime;


	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
        void openSubscriptions(ros::NodeHandle nodeHandle);



Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();
        void parameterReceived();
        void updateStatus();
        void supervisorStateReceived( );
        void errorInformerReceived();


private:

	int init_argc;
	char** init_argv;

        ros::Subscriber watchdogSubs;
        void processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg);
        ros::Subscriber errorInformerSubs;
        void errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg);



        QStringListModel logging_model;
};


#endif
