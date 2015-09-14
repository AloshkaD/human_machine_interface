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

#ifndef HumanMachineInterface_TELEMETRY_H_
#define HumanMachineInterface_TELEMETRY_H_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
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

#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qthread.h>
#include <qt4/QtCore/QtDebug>
#include <qt4/Qt/qstringlistmodel.h>


/*****************************************************************************
** Class
*****************************************************************************/

class TelemetryStateReceiver: public QObject{
    Q_OBJECT
public:
         TelemetryStateReceiver();
	virtual ~ TelemetryStateReceiver();

        bool ready(); 
        QString description;
        QString node_name;
        QString error_type;
        QString hostname;
        QString location;
        QString ns;
        QString action;





        QStringList fieldsMsgs;
        droneMsgsROS::dronePitchRollCmd dronePitchRollCmdMsgs;
        droneMsgsROS::droneDAltitudeCmd droneDAltitudeCmdMsgs;
        droneMsgsROS::droneDYawCmd droneDYawCmdMsgs;
        droneMsgsROS::dronePose dronePoseMsgs;




        geometry_msgs::Vector3Stamped magnetometerMsgs;
        droneMsgsROS::battery batteryMsgs;
        droneMsgsROS::droneAltitude altitudeMsgs;
        geometry_msgs::Vector3Stamped rotationAnglesMsgs;
        droneMsgsROS::vector2Stamped groundSpeedMsgs;
        sensor_msgs::Imu imuMsgs;
        droneMsgsROS::droneStatus droneStatusMsgs;
        droneMsgsROS::droneCommand droneCommandMsgs;
        sensor_msgs::FluidPressure fluidPressure;
        sensor_msgs::Temperature temperature;

        float time;

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

Q_SIGNALS:
	    void loggingUpdated();
        void parameterReceived();
        void updateStatus();



private:
        bool subscriptions_complete;

        int init_argc;
        int real_time;
        char** init_argv;

        std::string drone_driver_command_drone_command_pitch_roll;
        std::string drone_driver_command_drone_command_daltitude;
        std::string drone_driver_command_drone_command_dyaw;
        std::string drone_driver_command_drone_hl_command;
        std::string drone_driver_sensor_imu;
        std::string drone_driver_sensor_temperature;
        std::string drone_driver_sensor_magnetometer;
        std::string drone_driver_sensor_battery;
        std::string drone_driver_sensor_altitude;
        std::string drone_driver_sensor_rotation_angles;
        std::string drone_driver_sensor_ground_speed;
        std::string drone_driver_sensor_pressure;
        std::string drone_driver_sensor_status;
        std::string supervisor_process_error_unified_notification;
        std::string supervisor_processes_performance;
        std::string drone_pelican_like_simulator_control_input_subscriber;
        std::string drone_okto_like_simulator_okto_commands_subscriber;


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

        QStringListModel logging_model;
};


#endif /* HumanMachineInterface_TELEMETRY_H_ */
