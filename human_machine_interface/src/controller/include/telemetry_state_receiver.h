/*!*******************************************************************************************
 *  \file       telemetry_state_receiver.h
 *  \brief      UserCommander definition file.
 *  \details    This file includes the TelemetryStateReceiver class declaration. To obtain more
 *              information about it's definition consult the telemetry_state_receiver.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef HumanMachineInterface_TELEMETRY_H_
#define HumanMachineInterface_TELEMETRY_H_

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
        droneMsgsROS::dronePitchRollCmd drone_pitchRoll_cmd_msgs;
        droneMsgsROS::droneDAltitudeCmd drone_dAltitude_cmd_msgs;
        droneMsgsROS::droneDYawCmd drone_dyaw_cmd_msgs;
        droneMsgsROS::dronePose drone_pose_msgs;




        geometry_msgs::Vector3Stamped magnetometer_msgs;
        droneMsgsROS::battery battery_msgs;
        droneMsgsROS::droneAltitude altitude_msgs;
        geometry_msgs::Vector3Stamped rotation_angles_msgs;
        droneMsgsROS::vector2Stamped ground_speed_msgs;
        sensor_msgs::Imu imu_msgs;
        droneMsgsROS::droneStatus drone_status_msgs;
        droneMsgsROS::droneCommand drone_command_msgs;
        sensor_msgs::FluidPressure fluid_pressure;
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
    void printImuCallback(const sensor_msgs::Imu::ConstPtr& msg);
    void printDronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg);
    void printRotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);
    void printMagnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);
    void printAltitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg);
    void printDronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg);

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

        ros::Subscriber magnetometer_subs;
        void magnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

        ros::Subscriber battery_subs;
        void batteryCallback(const droneMsgsROS::battery::ConstPtr& msg);

        ros::Subscriber altitude_subs;
        void altitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg);

        ros::Subscriber rotation_angles_subs;
        void rotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg);

        ros::Subscriber ground_speed_subs;
        void groundSpeedCallback(const droneMsgsROS::vector2Stamped::ConstPtr& msg);

        ros::Subscriber imu_subs;
        void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);

        ros::Subscriber dronePositionSubs;
        void dronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg);

        ros::Subscriber drone_HLCmd_subs;
        void droneLLCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg);

        ros::Subscriber DroneLLCmdSubs;
        void droneHLCallback(const droneMsgsROS::droneCommand::ConstPtr& msg);

        ros::Subscriber temperature_subs;
        void temperatureCallback(const  sensor_msgs::Temperature::ConstPtr& msg);

        ros::Subscriber drone_input_subs;
        void  droneInputPelicanCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber opt_flow_subs;
        void  optFlowCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber okto_commands_subs;
        void  oktoCommandsCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber pressure_subs;
        void  pressureCallback(const sensor_msgs::FluidPressure::ConstPtr& msg);

        ros::Subscriber drone_status_subs;
        void  statusSensorCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber drone_pitchRoll_cmd_subs;
        void dronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg);

        ros::Subscriber drone_dAltitude_cmd_subs;
        void droneDAltitudeCmdCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg);

        ros::Subscriber drone_dYaw_cmd_subs;
        void droneDYawCmdCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg);

        ros::Subscriber drone_command_subs;

        ros::Subscriber drone_pelicanLL_status_subs;

        ros::Subscriber drone_pelican_IMUCalc_subs;

        ros::Subscriber drone_pelicanRCData_subs;

        ros::Subscriber drone_pelicanControl_input_subs;

        QStringListModel logging_model;
};


#endif /* HumanMachineInterface_TELEMETRY_H_ */
