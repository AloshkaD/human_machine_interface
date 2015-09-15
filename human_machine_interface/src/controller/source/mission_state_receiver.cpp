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


void MissionStateReceiver::openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace){
    // Topic communications

      //start();
     subscriptions_complete = true;
//    real_time=ros;
}


bool MissionStateReceiver::ready() {
    if (!subscriptions_complete)
        return false;
    return true; //Used this way instead of "return subscriptions_complete" due to preserve add more conditions
}


MissionStateReceiver::~MissionStateReceiver() {}


std::string MissionStateReceiver::droneMissionInfoCallback(const droneMsgsROS::droneMissionInfo::ConstPtr &msg)
{
    std::stringstream result_ss;

    result_ss<< "durationMission:"<<msg->durationMission.toSec();
    result_ss<<" durationSubmission:"<<msg->durationSubmission.toSec();
    result_ss<<" idSubmission:"<<msg->idSubmission;
    result_ss<<" loopSubmision:"<<static_cast<int>(msg->loopSubmission);
    result_ss<<" durationTask:"<<msg->durationTask.toSec();
    result_ss<<" idTask:"<<msg->idTask;
    result_ss<<" taskType:"<<msg->taskType;
    result_ss<<" taskState:";
    switch(msg->taskState)
    {
    case droneMsgsROS::droneMissionInfo::WAITING_BRAIN:
        result_ss<<"WAITING_BRAIN";
        break;
    case droneMsgsROS::droneMissionInfo::TASK_RUNNING:
        result_ss<<"TASK_RUNNING";
        break;
    default:
        result_ss<<"UNKNOWN";
        break;
    }

    return result_ss.str();
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


