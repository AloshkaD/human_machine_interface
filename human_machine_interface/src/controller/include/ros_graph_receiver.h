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
#include <qt4/Qt/qthread.h>
#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qstringlistmodel.h>



/*****************************************************************************
** Class
*****************************************************************************/

class RosGraphReceiver: public QObject{
    Q_OBJECT

public:
        RosGraphReceiver();
        virtual ~ RosGraphReceiver();
        bool ready(); 
        
        QString description;
        QString node_name;
        QString error_type;
        QString hostname;
        QString location;
        QString ns;
        QString action;



        droneMsgsROS::ProcessDescriptorList list_process_state;
        droneMsgsROS::ProcessDescriptor node_container;
        droneMsgsROS::droneStatus droneStatusMsgs;
        double supervisor_state_time;


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
        void parameterReceived();
        void updateStatus();
        void supervisorStateReceived( );
        void errorInformerReceived();


private:
        bool subscriptions_complete;

        ros::Subscriber watchdog_subs;
        void processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg);
        ros::Subscriber error_informer_subs;
        void errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg);

        std::string supervisor_process_error_unified_notification;
        std::string supervisor_processes_performance;

        QStringListModel logging_model;
};


#endif
