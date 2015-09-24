/*!*******************************************************************************************
 *  \file       mission_state_receiver.h
 *  \brief      MissionStateReceiver definition file.
 *  \details    This file includes the MissionStateReceiver class declaration. To obtain more
 *              information about it's definition consult the mission_state_receiver.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef HumanMachineInterface_MISSIONSTATERECEIVER_H_
#define HumanMachineInterface_MISSIONSTATERECEIVER_H_

#include <ros/ros.h>
#include <string>
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"
#include "droneMsgsROS/droneMissionInfo.h"
#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qthread.h>
#include <qt4/QtCore/QtDebug>
#include <qt4/Qt/qstringlistmodel.h>

class MissionStateReceiver: public QObject {
    Q_OBJECT
public:
         MissionStateReceiver();
	virtual ~ MissionStateReceiver();

        void run();
        bool ready();


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
        bool is_autonomous_mode_active;
        void activateAutonomousMode();
        void isInAutonomousMode();
        void deactivateAutonomousMode();

        droneMsgsROS::droneMissionInfo mission_info;



Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();

private:
        std::string mission_info_topic;


	int init_argc;
        int real_time;
	char** init_argv;
        bool subscriptions_complete;
        ros::ServiceClient mission_planner_srv_start;
        ros::ServiceClient mission_planner_srv_stop;
        ros::Subscriber mission_info_subs;
        void droneMissionInfoCallback(const droneMsgsROS::droneMissionInfo::ConstPtr &msg);
        QStringListModel logging_model;
};


#endif /* HumanMachineInterface_mission_state_receiver_h_ */
