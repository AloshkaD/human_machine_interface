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
#include "../include/ros_graph_receiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

RosGraphReceiver::RosGraphReceiver(){}


void RosGraphReceiver::openSubscriptions(ros::NodeHandle nodeHandle){
    // Topic communications
    //supervisor
    errorInformerSubs=nodeHandle.subscribe("drone0/process_error_unified_notification", 1, &RosGraphReceiver::errorInformerCallback,this);
    watchdogSubs=nodeHandle.subscribe("drone0/processes_performance", 1, &RosGraphReceiver::processPerformanceListCallback,this);


    start();
//    real_time=ros;
}

RosGraphReceiver::~RosGraphReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
	wait();
}


void RosGraphReceiver::run() {
    ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void RosGraphReceiver::errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg)
{

     description=   msg->description.c_str();
    node_name=  msg->process_name.c_str();
    if(msg->error_type.value==msg->error_type.FrozenNode)
      error_type="FrozenNode";
    if(msg->error_type.value==msg->error_type.InvalidInputData)
      error_type="InvalidInputData";
    if(msg->error_type.value==msg->error_type.SafeguardRecoverableError)
      error_type="SafeguardRecoverableError";
    if(msg->error_type.value==msg->error_type.SafeguarFatalError)
      error_type="SafeguarFatalError";
    if(msg->error_type.value==msg->error_type.UnexpectedProcessStop)
      error_type="UnexpectedProcessStop";

    hostname= msg->hostname.c_str();
    location = msg->function.c_str();
    supervisorStateTime = ros::Time::now().toSec();
    Q_EMIT errorInformerReceived();


    ROS_INFO("Received description from /drone_0/error_informer: [%s]", msg->description.c_str());
    ROS_INFO("Received node_name from /drone_0/error_informer: [%s]", msg->process_name.c_str());
    ROS_INFO("Received hostname from /drone_0/error_informer: [%s]", msg->hostname.c_str());
    ROS_INFO("Received location from /drone_0/error_informer: [%s]",  msg->function.c_str());

}


void RosGraphReceiver::processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg)
{

    listProcessState=*msg;


    for(unsigned int i = 0; i < msg->process_list.size(); i = i + 1)
    {
     node_container= msg->process_list.at(i);
     node_container.name;
     ROS_INFO("Reveived process state from drone0/processes_performance: [%d]",  node_container.current_state.state);
    }

    Q_EMIT supervisorStateReceived();

}


void RosGraphReceiver::log( const LogLevel &level, const std::string &msg) {
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

