/*
  collector
  Launch a ROS node to subscribe topics.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
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
#include "../include/human_machine_interface/rosGraphReceiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

rosGraphReceiver::rosGraphReceiver(){}


void rosGraphReceiver::openSubscriptions(ros::NodeHandle nodeHandle){
    // Topic communications
  //  errorInformerSubs=nodeHandle.subscribe("/drone_0/error_informer", 1, &rosGraphReceiver::supervisorCallback,this);
    //watchdogSubs=nodeHandle.subscribe("/drone_0/watchdog_topic", 1, &rosGraphReceiver::watchdogCallback,this);

    start();
//    real_time=ros;
}

rosGraphReceiver::~rosGraphReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
	wait();
}

void rosGraphReceiver::droneStatusCallback(const droneMsgsROS::droneStatus::ConstPtr& msg)
{
    droneStatusMsgs=*msg; // status type
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from status: [%s]", msg->status);
    return;
}

void rosGraphReceiver::run() {
    ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


/*void rosGraphReceiver::watchdogCallback(const cvg_stack_msgs::error_message::ConstPtr& msg){

     description=   msg->description.c_str();
    node_name=  msg->node_name.c_str();
    if(msg->error_type.value==msg->error_type.FrozenNode)
      error_type="FrozenNode";
    if(msg->error_type.value==msg->error_type.InvalidInputData)
      error_type="InvalidInputData";
    if(msg->error_type.value==msg->error_type.SafeguardRecoverableError)
      error_type="SafeguardRecoverableError";
    if(msg->error_type.value==msg->error_type.SafeguarFatalError)
      error_type="SafeguarFatalError";
    if(msg->error_type.value==msg->error_type.UnexpectedNodeStop)
      error_type="UnexpectedNodeStop";

    hostname= msg->hostname.c_str();
    location = msg->location.c_str();
    supervisorStateTime = ros::Time::now().toSec();
    Q_EMIT supervisorStateReceived();


    ROS_INFO("Received description from /drone_0/watchdog_topic: [%s]", msg->description.c_str());
    ROS_INFO("Received node_name from /drone_0/watchdog_topic: [%s]", msg->node_name.c_str());
    ROS_INFO("Received hostname from /drone_0/watchdog_topic: [%s]", msg->hostname.c_str());
    ROS_INFO("Received location from /drone_0/watchdog_topic: [%s]",  msg->location.c_str());

}*/




/*void rosGraphReceiver::supervisorCallback(const cvg_stack_msgs::error_message::ConstPtr& msg){

     description=   msg->description.c_str();
    node_name=  msg->node_name.c_str();
    if(msg->error_type.value==msg->error_type.FrozenNode)
      error_type="FrozenNode";
    if(msg->error_type.value==msg->error_type.InvalidInputData)
      error_type="InvalidInputData";
    if(msg->error_type.value==msg->error_type.SafeguardRecoverableError)
      error_type="SafeguardRecoverableError";
    if(msg->error_type.value==msg->error_type.SafeguarFatalError)
      error_type="SafeguarFatalError";
    if(msg->error_type.value==msg->error_type.UnexpectedNodeStop)
      error_type="UnexpectedNodeStop";

    hostname= msg->hostname.c_str();
    location = msg->location.c_str();
    supervisorStateTime = ros::Time::now().toSec();
    Q_EMIT supervisorStateReceived();


    ROS_INFO("Received description from /drone_0/error_informer: [%s]", msg->description.c_str());
    ROS_INFO("Received node_name from /drone_0/error_informer: [%s]", msg->node_name.c_str());
    ROS_INFO("Received hostname from /drone_0/error_informer: [%s]", msg->hostname.c_str());
    ROS_INFO("Received location from /drone_0/error_informer: [%s]",  msg->location.c_str());

}*/


void rosGraphReceiver::log( const LogLevel &level, const std::string &msg) {
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


