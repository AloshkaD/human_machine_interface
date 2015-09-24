/*!*******************************************************************************************
 *  \file       odometry_state_receiver.h
 *  \brief      OdometryStateReceiver definition file.
 *  \details    This file includes the OdometryStateReceiver class declaration. To obtain more
 *              information about it's definition consult the odometry_state_receiver.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef HumanMachineInterface_ODOMETRYSTATERECEIVER_H_
#define HumanMachineInterface_ODOMETRYSTATERECEIVER_H_


#include <ros/ros.h>
#include <string>
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"
#include "geometry_msgs/Point.h"
#include "droneMsgsROS/droneSpeeds.h"
#include "droneMsgsROS/AliveSignal.h"
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ErrorType.h"
#include "droneMsgsROS/dronePose.h"
#include "droneMsgsROS/obsVector.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
#include "droneMsgsROS/dronePositionTrajectoryRefCommand.h"
#include "droneMsgsROS/droneTrajectoryControllerControlMode.h"
#include "communication_definition.h"
#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qthread.h>
#include <qt4/QtCore/QtDebug>
#include <qt4/Qt/qstringlistmodel.h>


/*****************************************************************************
** Class
*****************************************************************************/

class OdometryStateReceiver: public QObject{
    Q_OBJECT
public:
        OdometryStateReceiver();
	virtual ~ OdometryStateReceiver();

        void run();
        bool ready();

        droneMsgsROS::droneSpeeds drone_speeds_msgs;
        droneMsgsROS::dronePose drone_pose_msgs;
        droneMsgsROS::droneSpeeds drone_controller_speeds_msgs;
        droneMsgsROS::dronePose drone_controller_pose_msgs;

        std::vector<droneMsgsROS::ProcessDescriptor> list_process_state;


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
        void readParams(ros::NodeHandle nodeHandle);
        void printDroneArucoEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);
        void printDroneArucoEstimatedSpeedCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);
        void printDroneGMREstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);
        void printDroneGMREstimatedSpeedCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);
        void printDronePoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);
        void printDroneSpeedsCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);
        void printDroneSOEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);
        void printDroneSOEstimatedSpeedsCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);

Q_SIGNALS:
        void loggingUpdated();
        void parameterReceived();
        void updateStatus();
        void supervisorStateReceived( );


private:
        bool subscriptions_complete;

        std::string drone_trajectory_controller_pose_subscription_gmr;
        std::string drone_trajectory_controller_speeds_subscription_gmr;
        std::string drone_state_estimator_interface_pose_subscription_lmrt;
        std::string drone_state_estimator_interface_speeds_subscription_lmrt;
        std::string drone_trajectory_planner_pose_subscription;
        std::string drone_trajectory_controller_speeds_subscription_gmr_aruco;
        std::string drone_logger_aruco_eye_observationvec_list;
        std::string drone_logger_position_ref_rebroadcast_subscription;
        std::string drone_logger_speed_ref_rebroadcast_subscription;

	int init_argc;
        int real_time;
        char** init_argv;

        ros::Subscriber DroneGMREstimatedPoseSubs;
        void droneGMREstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);

        ros::Subscriber DroneGMREstimatedSpeedSubs;
        void droneGMREstimatedSpeedCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);

        ros::Subscriber DroneSOEstimatedPoseSubs;
        void droneSOEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);

        ros::Subscriber DroneSOEstimatedSpeedsSubs;
         void droneSOEstimatedSpeedsCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);

        ros::Subscriber DroneArucoEstimatedPoseSubs;
        void droneArucoEstimatedPoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);

        ros::Subscriber DroneArucoEstimatedSpeedSubs;
        void droneArucoEstimatedSpeedCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);

        ros::Subscriber DroneArucoEyeObservationSubs;
        void droneArucoEyeObservationCallback(const droneMsgsROS::obsVector::ConstPtr &msg);

        ros::Subscriber DroneTrajectoryControlSubs;
        void droneTrajectoryControllerControlModeCallback(const droneMsgsROS::droneTrajectoryControllerControlMode::ConstPtr &msg);

        ros::Subscriber DroneTrajectoryPositionSubs;
        void dronePoseCallback(const droneMsgsROS::dronePose::ConstPtr &msg);

        ros::Subscriber DroneTrajectorySpeedsSubs;
        void droneSpeedsCallback(const droneMsgsROS::droneSpeeds::ConstPtr &msg);

        ros::Subscriber DroneTrajectoryTjReferenceSubs;
        void dronePositionTrajectoryRefCommandCallback(const droneMsgsROS::dronePositionTrajectoryRefCommand::ConstPtr &msg);

        void processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg);

        QStringListModel logging_model;

};


#endif /* HumanMachineInterface_ODOMETRYSTATERECEIVER_H_ */
