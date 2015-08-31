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

#ifndef GroundControlSystem_COLLECTOR_HPP_
#define GroundControlSystem_COLLECTOR_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QString>
#include <vector>
#include "std_msgs/String.h"
#include "std_msgs/Float32MultiArray.h"
#include "geometry_msgs/Point.h"
#include "droneMsgsROS/droneDYawCmd.h"
#include "droneMsgsROS/droneStatus.h"
#include "droneMsgsROS/droneDAltitudeCmd.h"
#include "droneMsgsROS/dronePitchRollCmd.h"
#include "droneMsgsROS/droneCommand.h"
#include "droneMsgsROS/droneSpeeds.h"
#include "droneMsgsROS/AliveSignal.h"
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
#include "communication_definition.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/FluidPressure.h"
#include "sensor_msgs/Temperature.h"
//Magnetometer and RotationAngles
#include "geometry_msgs/Vector3Stamped.h"

//Battery
#include "droneMsgsROS/battery.h"

//Altitude
#include "droneMsgsROS/droneAltitude.h"

#include "droneMsgsROS/dronePose.h"
//Ground Speed
#include "droneMsgsROS/vector2Stamped.h"
#include <QThread>
#include <qt4/QtCore/QtDebug>
#include <QString>
#include <QStringListModel>


/*****************************************************************************
** Class
*****************************************************************************/

class telemetryStateReceiver: public QThread {
    Q_OBJECT
public:
         telemetryStateReceiver();
	virtual ~ telemetryStateReceiver();

        void run();
        QString description;
        QString node_name;
        QString error_type;
        QString hostname;
        QString location;
        QString ns;
        QString action;



        droneMsgsROS::ProcessDescriptorList listProcessState;

        droneMsgsROS::ProcessDescriptor node_container;

        QStringList fieldsMsgs;
        droneMsgsROS::dronePitchRollCmd DronePitchRollCmdMsgs;
        droneMsgsROS::droneDAltitudeCmd DroneDAltitudeCmdMsgs;
        droneMsgsROS::droneDYawCmd DroneDYawCmdMsgs;
        droneMsgsROS::dronePose DronePoseMsgs;




        geometry_msgs::Vector3Stamped MagnetometerMsgs;
        droneMsgsROS::battery BatteryMsgs;
        droneMsgsROS::droneAltitude AltitudeMsgs;
        geometry_msgs::Vector3Stamped RotationAnglesMsgs;
        droneMsgsROS::vector2Stamped GroundSpeedMsgs;
        sensor_msgs::Imu ImuMsgs;
        droneMsgsROS::droneStatus droneStatusMsgs;
        droneMsgsROS::droneCommand DroneCommandMsgs;
        sensor_msgs::FluidPressure fluidPressure;
        sensor_msgs::Temperature temperature;

        float time;
        double supervisorStateTime;

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
    void openGeneralSubscriptions(ros::NodeHandle nodeHandle);
    void openSubscriptions_driverPelican(ros::NodeHandle nodeHandle);
    void openSubscriptions_driverOkto(ros::NodeHandle nodeHandle);


Q_SIGNALS:
	void loggingUpdated();
        void rosShutdown();
        void parameterReceived();
        void updateStatus();
        void supervisorStateReceived( );
        void errorInformerReceived();


private:

	int init_argc;
        int real_time;
	char** init_argv;


        ros::Subscriber droneStatusSubs;
        void droneStatusSensorCallback(const droneMsgsROS::droneStatus::ConstPtr& msg);

        ros::Subscriber MagnetometerSubs;
        void magnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

        ros::Subscriber BatterySubs;
        void batteryCallback(const droneMsgsROS::battery::ConstPtr& msg);

        ros::Subscriber AltitudeSubs;
        void altitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg);

        ros::Subscriber RotationAnglesSubs;
        void rotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

        ros::Subscriber GroundSpeedSubs;
        void groundSpeedCallback(const droneMsgsROS::vector2Stamped::ConstPtr& msg);

        ros::Subscriber ImuSubs;
        void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);

        ros::Subscriber dronePositionSubs;
        void dronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg);

        ros::Subscriber DroneHLCmdSubs;
        void droneLLCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg);

        ros::Subscriber DroneLLCmdSubs;
        void droneHLCallback(const droneMsgsROS::droneCommand::ConstPtr& msg);

        ros::Subscriber TemperatureSubs;
        void temperatureCallback(const  sensor_msgs::Temperature::ConstPtr& msg);

        ros::Subscriber DroneInputSubs;
        void  droneInputPelicanCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber optFlowSubs;
        void  optFlowCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber oktoCommandsSubs;
        void  oktoCommandsCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber PressureSubs;
        void  pressureCallback(const sensor_msgs::FluidPressure::ConstPtr& msg);

        ros::Subscriber DroneStatusSubs;
        void  statusSensorCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber DronePitchRollCmdSubs;
        void dronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg);

        ros::Subscriber DroneDAltitudeCmdSubs;
        void droneDAltitudeCmdCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber DroneDYawCmdSubs;
        void droneDYawCmdCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg);

        ros::Subscriber DroneCommandSubs;

        ros::Subscriber DronePelicanLLStatusSubs;

        ros::Subscriber DronePelicanIMUCalcSubs;

        ros::Subscriber DronePelicanRCDataSubs;

        ros::Subscriber DronePelicanControlInputSubs;

        ros::Subscriber watchdogSubs;

        ros::Subscriber errorInformerSubs;


        void errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg);
        void processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg);

        QStringListModel logging_model;
};


#endif /* GroundControlSystem_QNODE_HPP_ */
