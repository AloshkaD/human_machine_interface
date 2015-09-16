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
#include <std_msgs/String.h>
#include <string>
#include <sstream>
#include "../include/telemetry_state_receiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

TelemetryStateReceiver::TelemetryStateReceiver(){
    subscriptions_complete = false;
}


void TelemetryStateReceiver::openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace){
    if (!nodeHandle.getParam("drone_driver_command_drone_command_pitch_roll", drone_driver_command_drone_command_pitch_roll))
     drone_driver_command_drone_command_pitch_roll = "command/pitch_roll";

   if (!nodeHandle.getParam("drone_driver_command_drone_command_daltitude", drone_driver_command_drone_command_daltitude))
     drone_driver_command_drone_command_daltitude ="command/dAltitude";

   if (!nodeHandle.getParam("drone_driver_command_drone_command_dyaw", drone_driver_command_drone_command_dyaw))
     drone_driver_command_drone_command_dyaw = "command/dYaw";

   if (!nodeHandle.getParam("drone_driver_command_drone_hl_command", drone_driver_command_drone_hl_command))
     drone_driver_command_drone_hl_command = "command/high_level";

   if (!nodeHandle.getParam("drone_driver_sensor_imu", drone_driver_sensor_imu))
     drone_driver_sensor_imu = "imu";

   if (!nodeHandle.getParam("drone_driver_sensor_temperature", drone_driver_sensor_temperature))
     drone_driver_sensor_temperature = "temperature";

   if (!nodeHandle.getParam("drone_driver_sensor_magnetometer", drone_driver_sensor_magnetometer))
     drone_driver_sensor_magnetometer = "magnetometer";

   if (!nodeHandle.getParam("drone_driver_sensor_battery", drone_driver_sensor_battery))
     drone_driver_sensor_battery = "battery";

   if (!nodeHandle.getParam("drone_driver_sensor_altitude", drone_driver_sensor_altitude))
     drone_driver_sensor_altitude = "altitude";

   if (!nodeHandle.getParam("drone_driver_sensor_rotation_angles", drone_driver_sensor_rotation_angles))
     drone_driver_sensor_rotation_angles = "rotation_angles";

   if (!nodeHandle.getParam("drone_driver_sensor_ground_speed", drone_driver_sensor_ground_speed))
     drone_driver_sensor_ground_speed = "ground_speed";

   if (!nodeHandle.getParam("drone_driver_sensor_pressure", drone_driver_sensor_pressure))
     drone_driver_sensor_pressure = "pressure";

   if (!nodeHandle.getParam("drone_driver_sensor_status", drone_driver_sensor_status))
     drone_driver_sensor_status = "status";

   if (!nodeHandle.getParam("drone_pelican_like_simulator_control_input_subscriber", drone_pelican_like_simulator_control_input_subscriber))
     drone_pelican_like_simulator_control_input_subscriber = "drone_pelican_like_simulator_control_input_subscriber";

   if (!nodeHandle.getParam("drone_okto_like_simulator_okto_commands_subscriber", drone_okto_like_simulator_okto_commands_subscriber))
     drone_okto_like_simulator_okto_commands_subscriber = "drone_okto_like_simulator_okto_commands_subscriber";


   //Commands
   drone_pitchRoll_cmd_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_command_drone_command_pitch_roll, 1, &TelemetryStateReceiver::dronePitchRollCmdCallback, this); //command/pitch_roll
   drone_dAltitude_cmd_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_command_drone_command_daltitude, 1, &TelemetryStateReceiver::droneDAltitudeCmdCallback, this);//command/dAltitude
   drone_dYaw_cmd_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_command_drone_command_dyaw, 1, &TelemetryStateReceiver::droneDYawCmdCallback, this);//command/dYaw
   drone_HLCmd_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_command_drone_hl_command, 1, &TelemetryStateReceiver::droneHLCallback, this);//command/high_level
   //DroneLLCmdSubs=nodeHandle.subscribe(ros::this_node::getNamespace() + "/" + drone_driver_command_drone_ll_autopilot_command, 1, &telemetryStateReceiver::droneLLCallback, this);//command/low_level

   //Sensor
   imu_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_imu, 1, &TelemetryStateReceiver::imuCallback, this);
   temperature_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_temperature, 1, &TelemetryStateReceiver::temperatureCallback, this);
   magnetometer_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_magnetometer, 1, &TelemetryStateReceiver::magnetometerCallback, this);
   battery_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_battery, 1, &TelemetryStateReceiver::batteryCallback, this);
   altitude_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_altitude, 1, &TelemetryStateReceiver::altitudeCallback, this);
   rotation_angles_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_rotation_angles, 1, &TelemetryStateReceiver::rotationAnglesCallback, this);
   ground_speed_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_ground_speed, 1, &TelemetryStateReceiver::groundSpeedCallback, this);
   pressure_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_pressure, 1, &TelemetryStateReceiver::pressureCallback, this);
   drone_status_subs=nodeHandle.subscribe(rosnamespace + "/" + drone_driver_sensor_status, 1, &TelemetryStateReceiver::droneStatusSensorCallback, this);


   // Asctec Autopilot/Pelican Low-Level Telemetry
  // DronePelicanLLStatusSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LOGGER_LLSTATUS_SUBSCRIBER, 1, &telemetryStateReceiver::pelicanLLStatusCallback, this);
  // DronePelicanIMUCalcSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LOGGER_IMUCALCDATA_SUBSCRIBER, 1, &telemetryStateReceiver::pelicanIMUCalcDataCallback, this);
  // DronePelicanRCDataSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LOGGER_RCDATA_SUBSCRIBER, 1, &telemetryStateReceiver::droneRCDataPelicanCallback, this);//command/low_level
  // DronePelicanControlInputSubs=nodeHandle.subscribe(ros::this_node::getNamespace() + "/" + drone_pelican_like_simulator_control_input_subscriber, 1, &telemetryStateReceiver::droneInputPelicanCallback, this);//command/low_level


   //Sensor
   // optFlowSubs=nodeHandle.subscribe("drone0/" + DRONE_OKTO_LIKE_SIMULATOR_GROUND_SPEED_SENSOR_PUBLISHER, 1, &telemetryStateReceiver::optFlowCallback, this);
   //Commands
   // oktoCommandsSubs=nodeHandle.subscribe(ros::this_node::getNamespace() + "/" + drone_okto_like_simulator_okto_commands_subscriber, 1, &telemetryStateReceiver::oktoCommandsCallback, this);
   subscriptions_complete = true;
   // real_time=ros;
}


TelemetryStateReceiver::~TelemetryStateReceiver() {}



bool TelemetryStateReceiver::ready() {
    if (!subscriptions_complete)
        return false;
    return true; //Used this way instead of "return subscriptions_complete" due to preserve add more conditions
}



void TelemetryStateReceiver::dronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg)
{
    drone_pitchRoll_cmd_msgs=*msg;
    //printDronePitchRollCmdCallback(msg);
    return;

}

void TelemetryStateReceiver::printDronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg)
{
    log(Info,std::string("Received rollCmd from command/roll: ")+ boost::lexical_cast<std::string>(msg->rollCmd) );
    log(Info,std::string("Received rollCmd from command/pitch: ")+ boost::lexical_cast<std::string>(msg->rollCmd) );
    return;

}

void TelemetryStateReceiver::imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
    imu_msgs=*msg;
    Q_EMIT parameterReceived();
   // printImuCallback(msg);
    return;
}
void TelemetryStateReceiver::printImuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
    log(Info,std::string("Received description from IMU angular velocity x:  ")+ boost::lexical_cast<std::string>(msg->angular_velocity.x) );
    log(Info,std::string("Received description from IMU angular velocity y:   ")+ boost::lexical_cast<std::string>(msg->angular_velocity.y) );
    log(Info,std::string("Received description from IMU angular velocity z:  ")+ boost::lexical_cast<std::string>(msg->angular_velocity.z) );
    //log(Info,std::string("Received description from IMU angular velocity covariance: ")+ boost::lexical_cast<std::string>(msg->angular_velocity_covariance) );
    log(Info,std::string("Received description from IMU linear acceleration: ")+ boost::lexical_cast<std::string>(msg->linear_acceleration) );
    //log(Info,std::string("Received description from IMU linear acceleration covariance: ")+ boost::lexical_cast<std::string>(msg->linear_acceleration_covariance) );
    log(Info,std::string("Received description from IMU orientation x: ")+ boost::lexical_cast<std::string>(msg->orientation.x) );
    log(Info,std::string("Received description from IMU orientation y:  ")+ boost::lexical_cast<std::string>(msg->orientation.y) );
    log(Info,std::string("Received description from IMU orientation z:  ")+ boost::lexical_cast<std::string>(msg->orientation.z) );
    log(Info,std::string("Received description from IMU orientation w:  ")+ boost::lexical_cast<std::string>(msg->orientation.w) );
   //log(Info,std::string("Received description from IMU orientation covariance: ")+ boost::lexical_cast<std::string>(msg->orientation_covariance) );
    return;
}

void TelemetryStateReceiver::magnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
{
    magnetometer_msgs=*msg;
    Q_EMIT parameterReceived();
    //printMagnetometerCallback(msg);
    return;
}

void TelemetryStateReceiver::printMagnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
{
    log(Info,std::string("Received description from Magnetometer sensor vector x:  ")+ boost::lexical_cast<std::string>(msg->vector.x) );
    log(Info,std::string("Received description from Magnetometer sensor vector y:   ")+ boost::lexical_cast<std::string>(msg->vector.y) );
    log(Info,std::string("Received description from Magnetometer sensor vector z:  ")+ boost::lexical_cast<std::string>(msg->vector.z) );
    return;
}

void TelemetryStateReceiver::batteryCallback(const droneMsgsROS::battery::ConstPtr& msg)
{
    battery_msgs=*msg;
    Q_EMIT parameterReceived();
    //log(Info,std::string("Received description from Battery percent:   ")+ boost::lexical_cast<std::string>(msg->batteryPercent) );
    //ROS_INFO("Received description from Battery percent: [%f]", msg->batteryPercent);
    return;
}

void TelemetryStateReceiver::altitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg)
{
    altitude_msgs=*msg;
    Q_EMIT parameterReceived();
    //printAltitudeCallback(msg);
    return;
}

void TelemetryStateReceiver::printAltitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg)
{
    log(Info,std::string("Received description from  Altitude percent:   ")+ boost::lexical_cast<std::string>(msg->altitude) );
    log(Info,std::string("Received description from  Altitude speed percent:   ")+ boost::lexical_cast<std::string>(msg->altitude_speed) );
    return;
}

void TelemetryStateReceiver::droneStatusSensorCallback(const droneMsgsROS::droneStatus::ConstPtr& msg)
{
    drone_status_msgs=*msg; // status type
    Q_EMIT parameterReceived();
    return;
}

void TelemetryStateReceiver::rotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
{
    rotation_angles_msgs=*msg;
    Q_EMIT parameterReceived();
    //printRotationAnglesCallback(msg);
    return;
}

void TelemetryStateReceiver::printRotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
{
    log(Info,std::string("Received roll from drone0/rotation_angles:   ")+ boost::lexical_cast<std::string>(msg->vector.x) );
    log(Info,std::string("Received pitch from drone0/rotation_angles:   ")+ boost::lexical_cast<std::string>(msg->vector.y) );
    log(Info,std::string("Received yaw from drone0/rotation_angles:   ")+ boost::lexical_cast<std::string>(msg->vector.z) );
    return;
}
void TelemetryStateReceiver::dronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg)
{
    drone_pose_msgs=*msg;
    Q_EMIT parameterReceived();
    //printDronePositionCallback(msg);
    return;
}

void TelemetryStateReceiver::printDronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg)
{
    log(Info,std::string("Received position x:")+ boost::lexical_cast<std::string>(msg->x) );
    log(Info,std::string("Received posistion y:")+ boost::lexical_cast<std::string>(msg->y) );
    log(Info,std::string("Received position z:")+ boost::lexical_cast<std::string>(msg->z) );
    log(Info,std::string("Received position pitch:")+ boost::lexical_cast<std::string>(msg->pitch) );
    log(Info,std::string("Received position roll:")+ boost::lexical_cast<std::string>(msg->roll) );
    log(Info,std::string("Received position yaw:")+ boost::lexical_cast<std::string>(msg->yaw) );
}
void TelemetryStateReceiver::groundSpeedCallback(const droneMsgsROS::vector2Stamped::ConstPtr& msg)
{
    ground_speed_msgs=*msg;
    Q_EMIT parameterReceived();
    //log(Info,std::string("Received x speed from drone0/ground_speed:")+ boost::lexical_cast<std::string>(msg->vector.x) );
    //log(Info,std::string("Received y speed from drone0/ground_speed:")+ boost::lexical_cast<std::string>(msg->vector.y) );
    return;
}

void TelemetryStateReceiver::temperatureCallback(const  sensor_msgs::Temperature::ConstPtr& msg)
{
    temperature=*msg;
    // log(Info,std::string("Received temperature from drone0/temperature:")+ boost::lexical_cast<std::string>(msg->temperature) );
    // log(Info,std::string("Received variance from drone0/temperature:")+ boost::lexical_cast<std::string>(msg->variance) );
}

void TelemetryStateReceiver::pressureCallback(const sensor_msgs::FluidPressure::ConstPtr& msg)
{
    fluid_pressure=*msg;
   // log(Info,std::string("Received fluid_pressure from drone0/pressure:")+ boost::lexical_cast<std::string>(msg->fluid_pressure) );
   // log(Info,std::string("Received variance from drone0/pressure:")+ boost::lexical_cast<std::string>(msg->variance) );
}


void TelemetryStateReceiver::droneDAltitudeCmdCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
    drone_dAltitude_cmd_msgs=*msg;
    Q_EMIT parameterReceived();
    //log(Info,std::string("Received dAltitude command from command/dAltitude:")+ boost::lexical_cast<std::string>(msg->dAltitudeCmd));
    return;
}

void TelemetryStateReceiver::droneDYawCmdCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg)
{
    drone_dyaw_cmd_msgs=*msg;
    Q_EMIT parameterReceived();
     //log(Info,std::string("Received dYaw command from command/dYaw:")+ boost::lexical_cast<std::string>(msg->dYawCmd));
    return;
}

void TelemetryStateReceiver::droneHLCallback(const droneMsgsROS::droneCommand::ConstPtr& msg)
{
    drone_command_msgs=*msg;
    Q_EMIT parameterReceived();
    //log(Info,std::string("Received command:")+ boost::lexical_cast<std::string>(msg->command));
    return;
}

void TelemetryStateReceiver::droneLLCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg)
{
    drone_dyaw_cmd_msgs=*msg;
    Q_EMIT parameterReceived();
    return;
}

void TelemetryStateReceiver::log( const LogLevel &level, const std::string &msg) {
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


