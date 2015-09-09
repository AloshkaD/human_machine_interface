/*
  OdometryStateReceiver
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
#include "../include/odometry_state_receiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

OdometryStateReceiver::OdometryStateReceiver(){}


void OdometryStateReceiver::openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace){

    OdometryStateReceiver::readParams(nodeHandle);

    DroneGMREstimatedPoseSubs=nodeHandle.subscribe(rosnamespace + "/" + drone_trajectory_controller_pose_subscription_gmr, 1, &OdometryStateReceiver::droneGMREstimatedPoseCallback, this); //EstimatedPose_droneGMR_wrt_GFF
    DroneGMREstimatedSpeedSubs=nodeHandle.subscribe(rosnamespace + "/" +  drone_trajectory_controller_speeds_subscription_gmr, 1, &OdometryStateReceiver::droneGMREstimatedSpeedCallback, this);//EstimatedSpeed_droneGMR_wrt_GFF
    DroneSOEstimatedPoseSubs=nodeHandle.subscribe(rosnamespace + "/" + drone_state_estimator_interface_pose_subscription_lmrt, 1, &OdometryStateReceiver::droneSOEstimatedPoseCallback, this); //SOEstimatedPose
    DroneSOEstimatedSpeedsSubs=nodeHandle.subscribe(rosnamespace + "/" +  drone_state_estimator_interface_speeds_subscription_lmrt, 1, &OdometryStateReceiver::droneSOEstimatedSpeedsCallback, this);//SOEstimatedSpeeds


    // Topic communications droneArucoEye
    DroneArucoEstimatedPoseSubs=nodeHandle.subscribe(rosnamespace + "/" + drone_trajectory_planner_pose_subscription, 1, &OdometryStateReceiver::droneArucoEstimatedPoseCallback, this); //ArucoSlam_EstimatedPose
    DroneArucoEstimatedSpeedSubs=nodeHandle.subscribe(rosnamespace + "/" +  drone_trajectory_controller_speeds_subscription_gmr_aruco, 1, &OdometryStateReceiver::droneArucoEstimatedSpeedCallback, this);//ArucoSlam_EstimatedSpeeds
    DroneArucoEyeObservationSubs=nodeHandle.subscribe(rosnamespace + "/" +  drone_logger_aruco_eye_observationvec_list, 1, &OdometryStateReceiver::droneArucoEyeObservationCallback, this);


    // Topic communications controller
    // Controller references (rebroadcasts): control mode and position, speed and trajectory references
    DroneTrajectoryPositionSubs=nodeHandle.subscribe(rosnamespace + "/" + drone_logger_position_ref_rebroadcast_subscription, 1, &OdometryStateReceiver::dronePoseCallback, this);
    DroneTrajectorySpeedsSubs=nodeHandle.subscribe(rosnamespace + "/" + drone_logger_speed_ref_rebroadcast_subscription, 1, &OdometryStateReceiver::droneSpeedsCallback, this);

    start();
//    real_time=ros;
}

void OdometryStateReceiver::run() {
    ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

OdometryStateReceiver::~OdometryStateReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
    wait();
}


void OdometryStateReceiver::readParams(ros::NodeHandle nodeHandle){

    if (!nodeHandle.getParam("drone_trajectory_controller_pose_subscription_gmr", drone_trajectory_controller_pose_subscription_gmr))
      drone_trajectory_controller_pose_subscription_gmr = "ArucoSlam_EstimatedPose";

    if (!nodeHandle.getParam("drone_trajectory_controller_speeds_subscription_gmr", drone_trajectory_controller_speeds_subscription_gmr))
      drone_trajectory_controller_speeds_subscription_gmr = "EstimatedSpeed_droneGMR_wrt_GFF";
    
    if (!nodeHandle.getParam("drone_state_estimator_interface_pose_subscription_lmrt", drone_state_estimator_interface_pose_subscription_lmrt))
      drone_state_estimator_interface_pose_subscription_lmrt = "SOEstimatedPose";

    if (!nodeHandle.getParam("drone_state_estimator_interface_speeds_subscription_lmrt", drone_state_estimator_interface_speeds_subscription_lmrt))
      drone_state_estimator_interface_speeds_subscription_lmrt = "SOEstimatedSpeeds";
    
    if (!nodeHandle.getParam("drone_trajectory_planner_pose_subscription", drone_trajectory_planner_pose_subscription))
      drone_trajectory_planner_pose_subscription = "ArucoSlam_EstimatedPose";

    if (!nodeHandle.getParam("drone_trajectory_controller_speeds_subscription_gmr_aruco", drone_trajectory_controller_speeds_subscription_gmr_aruco))
      drone_trajectory_controller_speeds_subscription_gmr_aruco = "ArucoSlam_EstimatedSpeeds";

    if (!nodeHandle.getParam("drone_logger_aruco_eye_observationvec_list", drone_logger_aruco_eye_observationvec_list))
      drone_logger_aruco_eye_observationvec_list = "arucoObservationl";

    if (!nodeHandle.getParam("drone_logger_position_ref_rebroadcast_subscription", drone_logger_position_ref_rebroadcast_subscription))
      drone_logger_position_ref_rebroadcast_subscription = "trajectoryControllerPositionReferencesRebroadcast";
    
    if (!nodeHandle.getParam("drone_logger_speed_ref_rebroadcast_subscription", drone_logger_speed_ref_rebroadcast_subscription))
      drone_logger_speed_ref_rebroadcast_subscription = "trajectoryControllerSpeedReferencesRebroadcast";


}

void OdometryStateReceiver::droneArucoEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    DronePoseMsgs=*msg;
    log(Info,std::string("Received pitch from ArucoSlam_EstimatedPose: ")+ boost::lexical_cast<std::string>(msg->pitch));
    log(Info,std::string("Received roll from ArucoSlam_EstimatedPose: ")+ boost::lexical_cast<std::string>(msg->roll));
    log(Info,std::string("Received yaw from ArucoSlam_EstimatedPose: ")+ boost::lexical_cast<std::string>(msg->yaw));
    log(Info,std::string("Received yaw from ArucoSlam_EstimatedPose: ")+ boost::lexical_cast<std::string>(msg->x));
    log(Info,std::string("Received pos.y from ArucoSlam_EstimatedPose: ")+ boost::lexical_cast<std::string>(msg->y));
    log(Info,std::string("Received pos.z from ArucoSlam_EstimatedPose: ")+ boost::lexical_cast<std::string>(msg->z));
    ROS_INFO("Received pitch from ArucoSlam_EstimatedPose: [%f]", msg->pitch);
    ROS_INFO("Received roll from ArucoSlam_EstimatedPose: [%f]", msg->roll);
    ROS_INFO("Received yaw from ArucoSlam_EstimatedPose: [%f]", msg->yaw);
    ROS_INFO("Received pos.x from ArucoSlam_EstimatedPose: [%f]", msg->x);
    ROS_INFO("Received pos.y from ArucoSlam_EstimatedPose: [%f]", msg->y);
    ROS_INFO("Received pos.z from ArucoSlam_EstimatedPose: [%f]", msg->z);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;

}

void OdometryStateReceiver::droneArucoEstimatedSpeedCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg)
{
    DroneSpeedsMsgs=*msg;
    log(Info,std::string("Received dx from ArucoSlam_EstimatedSpeeds: [%")+ boost::lexical_cast<std::string>(msg->dx));
    log(Info,std::string("Received dy from ArucoSlam_EstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dy));
    log(Info,std::string("Received dz from ArucoSlam_EstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dz));
    log(Info,std::string("Received dyaw from ArucoSlam_EstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dyaw));
    log(Info,std::string("Received dpitch from ArucoSlam_EstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dpitch));
    log(Info,std::string("Received droll from ArucoSlam_EstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->droll));
    ROS_INFO("Received dx from ArucoSlam_EstimatedSpeeds: [%f]", msg->dx);
    ROS_INFO("Received dy from ArucoSlam_EstimatedSpeeds: [%f]", msg->dy);
    ROS_INFO("Received dz from ArucoSlam_EstimatedSpeeds: [%f]", msg->dz);
    ROS_INFO("Received dyaw from ArucoSlam_EstimatedSpeeds: [%f]", msg->dyaw);
    ROS_INFO("Received dpitch from ArucoSlam_EstimatedSpeeds: [%f]", msg->dpitch);
    ROS_INFO("Received droll from ArucoSlam_EstimatedSpeeds: [%f]", msg->droll);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;

}




void OdometryStateReceiver::droneGMREstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    DronePoseMsgs=*msg;
    log(Info,std::string("Received dx from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->pitch));
    log(Info,std::string("Received dy from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->roll));
    log(Info,std::string("Received dz from EstimatedSpeed_droneGMR_wrt_GFF:")+ boost::lexical_cast<std::string>(msg->yaw));
    log(Info,std::string("Received dyaw from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->x));
    log(Info,std::string("Received dpitch from EstimatedSpeed_droneGMR_wrt_GFF:  ")+ boost::lexical_cast<std::string>(msg->y));
    log(Info,std::string("Received droll from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->z));
    ROS_INFO("Received pitch from EstimatedPose_droneGMR_wrt_GFF: [%f]", msg->pitch);
    ROS_INFO("Received roll from EstimatedPose_droneGMR_wrt_GFF: [%f]", msg->roll);
    ROS_INFO("Received yaw from EstimatedPose_droneGMR_wrt_GFF: [%f]", msg->yaw);
    ROS_INFO("Received pos.x from EstimatedPose_droneGMR_wrt_GFF: [%f]", msg->x);
    ROS_INFO("Received pos.y from EstimatedPose_droneGMR_wrt_GFF: [%f]", msg->y);
    ROS_INFO("Received pos.z from EstimatedPose_droneGMR_wrt_GFF: [%f]", msg->z);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;

}

void OdometryStateReceiver::droneGMREstimatedSpeedCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg)
{
    DroneSpeedsMsgs=*msg;
    log(Info,std::string("Received dx from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->dx));
    log(Info,std::string("Received dy from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->dy));
    log(Info,std::string("Received dz from EstimatedSpeed_droneGMR_wrt_GFF:")+ boost::lexical_cast<std::string>(msg->dz));
    log(Info,std::string("Received dyaw from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>( msg->dyaw));
    log(Info,std::string("Received dpitch from EstimatedSpeed_droneGMR_wrt_GFF:  ")+ boost::lexical_cast<std::string>(msg->dpitch));
    log(Info,std::string("Received droll from EstimatedSpeed_droneGMR_wrt_GFF: ")+ boost::lexical_cast<std::string>(msg->droll));
    ROS_INFO("Received dx from EstimatedSpeed_droneGMR_wrt_GFF: [%f]", msg->dx);
    ROS_INFO("Received dy from EstimatedSpeed_droneGMR_wrt_GFF: [%f]", msg->dy);
    ROS_INFO("Received dz from EstimatedSpeed_droneGMR_wrt_GFF: [%f]", msg->dz);
    ROS_INFO("Received dyaw from EstimatedSpeed_droneGMR_wrt_GFF: [%f]", msg->dyaw);
    ROS_INFO("Received dpitch from EstimatedSpeed_droneGMR_wrt_GFF: [%f]", msg->dpitch);
    ROS_INFO("Received droll from EstimatedSpeed_droneGMR_wrt_GFF: [%f]", msg->droll);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;

}

void OdometryStateReceiver::droneSOEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    DronePoseMsgs=*msg;
    log(Info,std::string("Received pitch from SOEstimatedPose: ")+ boost::lexical_cast<std::string>(msg->pitch));
    log(Info,std::string("Received roll from SOEstimatedPose: ")+ boost::lexical_cast<std::string>(msg->roll));
    log(Info,std::string("Received yaw from SOEstimatedPose:")+ boost::lexical_cast<std::string>(msg->yaw));
    log(Info,std::string("Received pos.x from SOEstimatedPose: ")+ boost::lexical_cast<std::string>(msg->x));
    log(Info,std::string("Received pos.y from SOEstimatedPose:")+ boost::lexical_cast<std::string>(msg->y));
    log(Info,std::string("Received pos.z from SOEstimatedPose: ")+ boost::lexical_cast<std::string>(msg->z));
    ROS_INFO("Received pitch from SOEstimatedPose: [%f]", msg->pitch);
    ROS_INFO("Received roll from SOEstimatedPose: [%f]", msg->roll);
    ROS_INFO("Received yaw from SOEstimatedPose: [%f]", msg->yaw);
    ROS_INFO("Received pos.x from SOEstimatedPose: [%f]", msg->x);
    ROS_INFO("Received pos.y from SOEstimatedPose: [%f]", msg->y);
    ROS_INFO("Received pos.z from SOEstimatedPose: [%f]", msg->z);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;

}

void OdometryStateReceiver::droneSOEstimatedSpeedsCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg)
{
    DroneSpeedsMsgs=*msg;
    log(Info,std::string("Received dx from SOEstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dx));
    log(Info,std::string("Received dy from SOEstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dy));
    log(Info,std::string("Received dz from SOEstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dz));
    log(Info,std::string("Received dyaw from SOEstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dyaw));
    log(Info,std::string("Received dpitch from SOEstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->dpitch));
    log(Info,std::string("Received droll from SOEstimatedSpeeds: ")+ boost::lexical_cast<std::string>(msg->droll));
    ROS_INFO("Received dx from SOEstimatedSpeeds: [%f]", msg->dx);
    ROS_INFO("Received dy from SOEstimatedSpeeds: [%f]", msg->dy);
    ROS_INFO("Received dz from SOEstimatedSpeeds: [%f]", msg->dz);
    ROS_INFO("Received dyaw from SOEstimatedSpeeds: [%f]", msg->dyaw);
    ROS_INFO("Received dpitch from SOEstimatedSpeeds: [%f]", msg->dpitch);
    ROS_INFO("Received droll from SOEstimatedSpeeds: [%f]", msg->droll);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;

}




void OdometryStateReceiver::dronePoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    DroneControllerPoseMsgs=*msg;

    log(Info,std::string("Received pitch from Controller:  ")+ boost::lexical_cast<std::string>(msg->pitch));
    log(Info,std::string("Received roll from Controller: ")+ boost::lexical_cast<std::string>(msg->roll));
    log(Info,std::string("Received yaw from Controller: ")+ boost::lexical_cast<std::string>(msg->yaw));
    log(Info,std::string("Received pos.x from Controller: ")+ boost::lexical_cast<std::string>(msg->x));
    log(Info,std::string("Received pos.y from Controller: ")+ boost::lexical_cast<std::string>(msg->y));
    log(Info,std::string("Received pos.z from Controller: ")+ boost::lexical_cast<std::string>( msg->z));
    ROS_INFO("Received pitch from Controller: [%f]", msg->pitch);
    ROS_INFO("Received roll from Controller: [%f]", msg->roll);
    ROS_INFO("Received yaw from Controller: [%f]", msg->yaw);
    ROS_INFO("Received pos.x from Controller: [%f]", msg->x);
    ROS_INFO("Received pos.y from Controller: [%f]", msg->y);
    ROS_INFO("Received pos.z from Controller: [%f]", msg->z);

    Q_EMIT parameterReceived();
    Q_EMIT updateStatus();
    return;
}

void OdometryStateReceiver::droneSpeedsCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg)
{
     DroneControllerSpeedsMsgs=*msg;
     log(Info,std::string("Received dx from Controller:  ")+ boost::lexical_cast<std::string>(msg->dx) );
     log(Info,std::string("Received dy from Controller: ")+ boost::lexical_cast<std::string>(msg->dy) );
     log(Info,std::string("Received dz from Controller: ")+ boost::lexical_cast<std::string>(msg->dz) );
     log(Info,std::string("Received dyaw from Controller: ")+ boost::lexical_cast<std::string>(msg->dyaw) );
     log(Info,std::string("Received dpitch from Controller: ")+ boost::lexical_cast<std::string>(msg->dpitch) );
     log(Info,std::string("Received droll from Controller: ")+ boost::lexical_cast<std::string>(msg->droll) );
     ROS_INFO("Received dx from Controller: [%f]", msg->dx);
     ROS_INFO("Received dy from Controller: [%f]", msg->dy);
     ROS_INFO("Received dz from Controller: [%f]", msg->dz);
     ROS_INFO("Received dyaw from Controller: [%f]", msg->dyaw);
     ROS_INFO("Received dpitch from Controller: [%f]", msg->dpitch);
     ROS_INFO("Received droll from Controller: [%f]", msg->droll);

     Q_EMIT parameterReceived();
     Q_EMIT updateStatus();
     return;
}

void OdometryStateReceiver::droneArucoEyeObservationCallback(const droneMsgsROS::obsVector::ConstPtr &msg)
{

    // TODO
    return;

}

void OdometryStateReceiver::log( const LogLevel &level, const std::string &msg) {
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


