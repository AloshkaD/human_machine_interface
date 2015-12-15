/*!*******************************************************************************************
 *  \file       ros_graph_receiver.h
 *  \brief      RosGraphReceiver definition file.
 *  \details    This file includes the VehicleView class declaration. To obtain more
 *              information about it's definition consult the ros_graph_receiver.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef HumanMachineInterface_ROSGRAPHRECEIVER_H
#define HumanMachineInterface_ROSGRAPHRECEIVER_H

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
#include "droneMsgsROS/BehaviorsList.h"

//Magnetometer and RotationAngles
#include "geometry_msgs/Vector3Stamped.h"

//Battery
#include "droneMsgsROS/battery.h"

//Altitude
#include "droneMsgsROS/droneAltitude.h"

#include "std_msgs/Bool.h"
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
         droneMsgsROS::BehaviorsList behavior_list;

        double supervisor_state_time;
        bool is_wifi_connected;


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
        void stateBehavior();
        void stateBehaviorReceived(const droneMsgsROS::BehaviorsList* list_behavior_state);


private:
        bool subscriptions_complete;

        std::string supervisor_process_error_unified_notification;
        std::string supervisor_processes_performance;
        std::string wifi_connection_topic;
        std::string behavior_state_topic;

        ros::Subscriber watchdog_subs;
        void processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg);
        ros::Subscriber wificonnection_subs;
        void wifiConnectionCheckCallback(const std_msgs::Bool::ConstPtr& msg);
        ros::Subscriber error_informer_subs;
        void errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg);
        ros::Subscriber behavior_state_subs;
        void behaviorStateCallback(const droneMsgsROS::BehaviorsList::ConstPtr& msg);


        QStringListModel logging_model;
};


#endif
