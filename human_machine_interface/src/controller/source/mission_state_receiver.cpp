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

MissionStateReceiver::MissionStateReceiver(){}


void MissionStateReceiver::openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace){
    // Topic communications

      //start();
//    real_time=ros;
}


void MissionStateReceiver::run() {
    //ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


MissionStateReceiver::~MissionStateReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
	wait();
}

/*
std::string DroneLoggerROSModule::droneMissionInfoCallback(const droneMsgsROS::droneMissionInfo::ConstPtr &msg)
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
  */
/*

std::string DroneLoggerROSModule::obstaclesTwoDimCallback(const droneMsgsROS::obstaclesTwoDim::ConstPtr &msg)
{
    std::stringstream result_ss;


    //msg->walls
    result_ss<< "walls_id:[";
    for (unsigned int i=0; i<msg->walls.size(); i++) {
        result_ss<<msg->walls[i].id<<";";
    }
    result_ss<<"]";
    result_ss<<" walls_center:[";
    for (unsigned int i=0; i<msg->walls.size(); i++) {
        result_ss<<msg->walls[i].centerX<<",";
        result_ss<<msg->walls[i].centerY<<";";
    }
    result_ss<<"]";

    result_ss<<" walls_size:[";
    for (unsigned int i=0; i<msg->walls.size(); i++) {
        result_ss<<msg->walls[i].sizeX<<",";
        result_ss<<msg->walls[i].sizeY<<";";
    }
    result_ss<<"]";

    result_ss<<" walls_yaw:[";
    for (unsigned int i=0; i<msg->walls.size(); i++) {
        result_ss<<msg->walls[i].yawAngle<<";";
    }
    result_ss<<"]";

    // msg->poles
    result_ss<<" poles_id:[";
    for (unsigned int i=0; i<msg->poles.size(); i++) {
        result_ss<<msg->poles[i].id<<";";
    }
    result_ss<<"]";
    result_ss<<" poles_center:[";
    for (unsigned int i=0; i<msg->poles.size(); i++) {
        result_ss<<msg->poles[i].centerX<<",";
        result_ss<<msg->poles[i].centerY<<";";
    }
    result_ss<<"]";
    result_ss<<" poles_size:[";
    for (unsigned int i=0; i<msg->poles.size(); i++) {
        result_ss<<msg->poles[i].radiusX<<",";
        result_ss<<msg->poles[i].radiusY<<";";
    }
    result_ss<<"]";
    result_ss<<" poles_yaw:[";
    for (unsigned int i=0; i<msg->poles.size(); i++) {
        result_ss<<msg->poles[i].yawAngle<<";";
    }
    result_ss<<"]";


    return result_ss.str();
}
*/


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


