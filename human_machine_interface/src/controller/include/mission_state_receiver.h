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

#ifndef HumanMachineInterface_MISSIONSTATERECEIVER_H_
#define HumanMachineInterface_MISSIONSTATERECEIVER_H_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include "std_msgs/String.h"
#include "std_srvs/Empty.h"
#include "droneMsgsROS/droneMissionInfo.h"
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
        void deActivateAutonomousMode();


Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();

private:

	int init_argc;
        int real_time;
	char** init_argv;
        bool subscriptions_complete;
        ros::ServiceClient mission_planner_srv_start;
        ros::ServiceClient mission_planner_srv_stop;
        std::string droneMissionInfoCallback(const droneMsgsROS::droneMissionInfo::ConstPtr &msg);
        QStringListModel logging_model;
};


#endif /* HumanMachineInterface_mission_state_receiver_h_ */
