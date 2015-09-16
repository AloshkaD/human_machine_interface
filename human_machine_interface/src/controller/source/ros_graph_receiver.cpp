/*
  RosGraphReceiver
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

RosGraphReceiver::RosGraphReceiver(){
    subscriptions_complete = false;
}


void RosGraphReceiver::openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace){
    // Topic communications

    if (!nodeHandle.getParam("process_error_unified_notification", supervisor_process_error_unified_notification))
         supervisor_process_error_unified_notification = "process_error_unified_notification";

    if (!nodeHandle.getParam("processes_performance", supervisor_processes_performance))
         supervisor_processes_performance = "processes_performance";

    //supervisor
    error_informer_subs=nodeHandle.subscribe(rosnamespace + "/" + supervisor_process_error_unified_notification, 1, &RosGraphReceiver::errorInformerCallback,this);
    watchdog_subs=nodeHandle.subscribe(rosnamespace + "/"  + supervisor_processes_performance, 1, &RosGraphReceiver::processPerformanceListCallback,this);


    subscriptions_complete=true;
//    real_time=ros;
}

RosGraphReceiver::~RosGraphReceiver() {}


bool RosGraphReceiver::ready() {
    if (!subscriptions_complete)
        return false;
    return true; //Used this way instead of "return subscriptions_complete" due to preserve add more conditions
}

// TODO:: Check wifi connection topic callback
//................


void RosGraphReceiver::errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg)
{

    description=msg->description.c_str();
    node_name=msg->process_name.c_str();
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
    supervisor_state_time = ros::Time::now().toSec();
    Q_EMIT errorInformerReceived();

    //log(Info,std::string("Received description from /drone_0/error_informer: ")+ boost::lexical_cast<std::string>(msg->description.c_str()) );
    //log(Info,std::string("Received node_name from /drone_0/error_informer: ")+ boost::lexical_cast<std::string>(msg->process_name.c_str()) );
    //log(Info,std::string("Received hostname from /drone_0/error_informer: ")+ boost::lexical_cast<std::string>(msg->hostname.c_str()) );
    //log(Info,std::string("Received location from /drone_0/error_informer: ")+ boost::lexical_cast<std::string>(msg->function.c_str()) );

}


void RosGraphReceiver::processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg)
{
    list_process_state=*msg;
    for(unsigned int i = 0; i < msg->process_list.size(); i = i + 1)
    {
        node_container= msg->process_list.at(i);
        node_container.name;
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


