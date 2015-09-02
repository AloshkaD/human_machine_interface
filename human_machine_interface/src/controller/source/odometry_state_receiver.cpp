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
#include "../include/odometry_state_receiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

OdometryStateReceiver::OdometryStateReceiver(){}


void OdometryStateReceiver::openGeneralSubscriptions(ros::NodeHandle nodeHandle){

    readParams();

    DroneGMREstimatedPoseSubs=nodeHandle.subscribe("drone0/" + DRONE_TRAJECTORY_CONTROLLER_POSE_SUBSCRIPTION_GMR, 1, &OdometryStateReceiver::droneGMREstimatedPoseCallback, this); //EstimatedPose_droneGMR_wrt_GFF
    DroneGMREstimatedSpeedSubs=nodeHandle.subscribe("drone0/" +  DRONE_TRAJECTORY_CONTROLLER_SPEEDS_SUBSCRIPTION_GMR, 1, &OdometryStateReceiver::droneGMREstimatedSpeedCallback, this);//EstimatedSpeed_droneGMR_wrt_GFF
    DroneSOEstimatedPoseSubs=nodeHandle.subscribe("drone0/" + DRONE_STATE_ESTIMATOR_INTERFACE_POSE_SUBSCRIPTION_LMrT, 1, &OdometryStateReceiver::droneSOEstimatedPoseCallback, this); //SOEstimatedPose
    DroneSOEstimatedSpeedsSubs=nodeHandle.subscribe("drone0/" +  DRONE_STATE_ESTIMATOR_INTERFACE_SPEEDS_SUBSCRIPTION_LMrT, 1, &OdometryStateReceiver::droneSOEstimatedSpeedsCallback, this);//SOEstimatedSpeeds
    start();
//    real_time=ros;
}



void OdometryStateReceiver::readParams(){
    //if (!n.getParam("alive_signal_topic", alive_signal_topic))
        //alive_signal_topic = "process_alive_signal";

     //if (!n.getParam("error_topic", error_topic))
       // error_topic = "self_detected_process_error";

    // if (!n.getParam("error_notification_topic", error_notification_topic))
        //error_notification_topic = "error_notification_topic";

     //if (!n.getParam("processes_performance_topic", processes_performance_topic))
       // processes_performance_topic = "processes_performance";

}


void OdometryStateReceiver::openSubscriptionsArucoSlam(ros::NodeHandle nodeHandle){

    // Topic communications droneArucoEye
    DroneArucoEstimatedPoseSubs=nodeHandle.subscribe("drone0/" + DRONE_TRAJECTORY_PLANNER_POSE_SUBSCRIPTION, 1, &OdometryStateReceiver::droneArucoEstimatedPoseCallback, this); //ArucoSlam_EstimatedPose
    DroneArucoEstimatedSpeedSubs=nodeHandle.subscribe("drone0/" +  DRONE_TRAJECTORY_CONTROLLER_SPEEDS_SUBSCRIPTION_GMR, 1, &OdometryStateReceiver::droneArucoEstimatedSpeedCallback, this);//ArucoSlam_EstimatedSpeeds
    DroneArucoEyeObservationSubs=nodeHandle.subscribe("drone0/" +  DRONE_LOGGER_ARUCO_EYE_OBSERVATIONVEC_LIST, 1, &OdometryStateReceiver::droneArucoEyeObservationCallback, this);
}

void OdometryStateReceiver::openSubscriptionsController(ros::NodeHandle nodeHandle){

    // Topic communications controller
    // Controller references (rebroadcasts): control mode and position, speed and trajectory references
    //DroneTrajectoryControlSubs=nodeHandle.subscribe("drone0/" + MODULE_NAME_TRAJECTORY_CONTROLLER +"/controlMode", 1, &odometryStateReceiver::droneTrajectoryControllerControlModeCallback, this);
    DroneTrajectoryPositionSubs=nodeHandle.subscribe("drone0/" + DRONE_LOGGER_POSITION_REF_REBROADCAST_SUBSCRIPTION, 1, &OdometryStateReceiver::dronePoseCallback, this);
    DroneTrajectorySpeedsSubs=nodeHandle.subscribe("drone0/" + DRONE_LOGGER_SPEED_REF_REBROADCAST_SUBSCRIPTION, 1, &OdometryStateReceiver::droneSpeedsCallback, this);
    DroneTrajectoryTjReferenceSubs=nodeHandle.subscribe("drone0/" + DRONE_LOGGER_TRAJECTORY_REF_REBROADCAST_SUBSCRIPTION, 1, &OdometryStateReceiver::dronePositionTrajectoryRefCommandCallback, this);

}


void OdometryStateReceiver::droneArucoEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    DronePoseMsgs=*msg;

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


void OdometryStateReceiver::droneArucoEyeObservationCallback(const droneMsgsROS::obsVector::ConstPtr &msg)
{

    // TODO
    return;

}

void OdometryStateReceiver::droneGMREstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg)
{
    DronePoseMsgs=*msg;

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

void OdometryStateReceiver::droneTrajectoryControllerControlModeCallback(const droneMsgsROS::droneTrajectoryControllerControlMode::ConstPtr &msg)
{
   /* std::stringstream result_ss;
    switch (msg->command) {
    case droneMsgsROS::droneTrajectoryControllerControlMode::SPEED_CONTROL:
        result_ss << "command:" << "SPEED";
        break;
    case droneMsgsROS::droneTrajectoryControllerControlMode::POSITION_CONTROL:
        result_ss << "command:" << "POSITION";
        break;
    case droneMsgsROS::droneTrajectoryControllerControlMode::TRAJECTORY_CONTROL:
        result_ss << "command:" << "TRAJECTORY";
        break;
    case droneMsgsROS::droneTrajectoryControllerControlMode::UNKNOWN_CONTROL_MODE:
        result_ss << "command:" << "UNKNOWN";
    default:
        break;
    }
    return result_ss.str();*/
}

void OdometryStateReceiver::dronePositionTrajectoryRefCommandCallback(const droneMsgsROS::dronePositionTrajectoryRefCommand::ConstPtr &msg)
{
   /* std::ostringstream xmat_trajectoryLogMsgStrm; xmat_trajectoryLogMsgStrm.str(std::string());
    std::ostringstream ymat_trajectoryLogMsgStrm; ymat_trajectoryLogMsgStrm.str(std::string());
    std::ostringstream zmat_trajectoryLogMsgStrm; zmat_trajectoryLogMsgStrm.str(std::string());
    int num_checkpoints = msg->droneTrajectory.size();

    if ( num_checkpoints == 0) {
        xmat_trajectoryLogMsgStrm << "[]";
        ymat_trajectoryLogMsgStrm << "[]";
        zmat_trajectoryLogMsgStrm << "[]";
    } else {
        xmat_trajectoryLogMsgStrm << "[";
        ymat_trajectoryLogMsgStrm << "[";
        zmat_trajectoryLogMsgStrm << "[";

        for (int i=0; i<num_checkpoints; i++ ) {
            xmat_trajectoryLogMsgStrm << msg->droneTrajectory[i].x;
            ymat_trajectoryLogMsgStrm << msg->droneTrajectory[i].y;
            zmat_trajectoryLogMsgStrm << msg->droneTrajectory[i].z;
            if (i < num_checkpoints-1) {
                xmat_trajectoryLogMsgStrm << ";";
                ymat_trajectoryLogMsgStrm << ";";
                zmat_trajectoryLogMsgStrm << ";";
            } else {
                xmat_trajectoryLogMsgStrm << "]";
                ymat_trajectoryLogMsgStrm << "]";
                zmat_trajectoryLogMsgStrm << "]";
            }
        }
    }

    std::stringstream result_ss;
    result_ss <<  "x:" << xmat_trajectoryLogMsgStrm.str()
              << " y:" << ymat_trajectoryLogMsgStrm.str()
              << " z:" << zmat_trajectoryLogMsgStrm.str();
    result_ss << " is_periodic:" << (int)msg->is_periodic
              << " initial_checkpoint:" << msg->initial_checkpoint;
    return result_ss.str();*/
}



OdometryStateReceiver::~OdometryStateReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
	wait();
}



void OdometryStateReceiver::run() {
    ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
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


