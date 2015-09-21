/*
  MissionStateReceiver
  Launch a ROS node to subscribe topics.
  @author  Yolanda de la Hoz Simón
  @date    06-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/mission_state_receiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

MissionStateReceiver::MissionStateReceiver(){
     subscriptions_complete = false;
}


void MissionStateReceiver::openSubscriptions(ros::NodeHandle n, std::string rosnamespace){
    // Topic communications

    if (!n.getParam("mission_info_topic", mission_info_topic))
        mission_info_topic = "droneMissionInfo";

     mission_info_subs=n.subscribe(rosnamespace + "/" + mission_info_topic, 1, &MissionStateReceiver::droneMissionInfoCallback, this);

     subscriptions_complete = true;
     is_autonomous_mode_active=false;
     mission_planner_srv_start=n.serviceClient<std_srvs::Empty>("/" + rosnamespace +  "/" + "droneMissionScheduleProcessor/start");
     mission_planner_srv_stop=n.serviceClient<std_srvs::Empty>("/" + rosnamespace +  "/" + "droneMissionScheduleProcessor/stop");
//    real_time=ros;
}


bool MissionStateReceiver::ready() {
    if (!subscriptions_complete)
        return false;
    return true; //Used this way instead of "return subscriptions_complete" due to preserve add more conditions
}


MissionStateReceiver::~MissionStateReceiver() {}

void MissionStateReceiver::activateAutonomousMode(){
     if(!is_autonomous_mode_active){
     std::cout<<"Starting Mission Planner...."<<std::endl;
     std_srvs::Empty emptySrvMsg;
     mission_planner_srv_start.call(emptySrvMsg);
     is_autonomous_mode_active=true;
     }
}

void MissionStateReceiver::deactivateAutonomousMode(){
     if(is_autonomous_mode_active){
     std_srvs::Empty emptySrvMsg;
     mission_planner_srv_stop.call(emptySrvMsg);
     is_autonomous_mode_active=false;
     }
 }

void MissionStateReceiver::droneMissionInfoCallback(const droneMsgsROS::droneMissionInfo::ConstPtr &msg)
{
    if(is_autonomous_mode_active){
        std::cout << msg->durationMission.toSec() << std::endl;
        std::cout << msg->durationSubmission.toSec() << std::endl;
        std::cout << msg->idSubmission << std::endl;

        std::cout << msg->durationTask.toSec() << std::endl;
        std::cout << msg->idTask << std::endl;

        mission_info=*msg;
    }

}



void MissionStateReceiver::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}


