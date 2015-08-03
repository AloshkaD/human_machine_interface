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
#include "../include/human_machine_interface/telemetryStateReceiver.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

telemetryStateReceiver::telemetryStateReceiver(){}


void telemetryStateReceiver::openGeneralSubscriptions(ros::NodeHandle nodeHandle){

    //Commands
    DronePitchRollCmdSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_COMMAND_DRONE_COMMAND_PITCH_ROLL, 1, &telemetryStateReceiver::dronePitchRollCmdCallback, this); //command/pitch_roll
    DroneDAltitudeCmdSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_COMMAND_DRONE_COMMAND_DALTITUDE, 1, &telemetryStateReceiver::droneDAltitudeCmdCallback, this);//command/dAltitude
    DroneDYawCmdSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_COMMAND_DRONE_COMMAND_DYAW, 1, &telemetryStateReceiver::droneDYawCmdCallback, this);//command/dYaw
    DroneHLCmdSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_COMMAND_DRONE_HL_COMMAND, 1, &telemetryStateReceiver::droneHLCallback, this);//command/high_level
    //DroneLLCmdSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_COMMAND_DRONE_LL_AUTOPILOT_COMMAND, 1, &telemetryStateReceiver::droneLLCallback, this);//command/low_level

    //Sensor
    ImuSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_IMU, 1, &telemetryStateReceiver::imuCallback, this);
    TemperatureSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_TEMPERATURE, 1, &telemetryStateReceiver::temperatureCallback, this);
    MagnetometerSubs=nodeHandle.subscribe("drone0/"+ DRONE_DRIVER_SENSOR_MAGNETOMETER, 1, &telemetryStateReceiver::magnetometerCallback, this);
    BatterySubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_BATTERY, 1, &telemetryStateReceiver::batteryCallback, this);
    AltitudeSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_ALTITUDE, 1, &telemetryStateReceiver::altitudeCallback, this);
    RotationAnglesSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_ROTATION_ANGLES, 1, &telemetryStateReceiver::rotationAnglesCallback, this);
    GroundSpeedSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_GROUND_SPEED, 1, &telemetryStateReceiver::groundSpeedCallback, this);
    PressureSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_PRESSURE, 1, &telemetryStateReceiver::pressureCallback, this);
    DroneStatusSubs=nodeHandle.subscribe("drone0/" + DRONE_DRIVER_SENSOR_STATUS, 1, &telemetryStateReceiver::droneStatusSensorCallback, this);

    //supervisor
    errorInformerSubs=nodeHandle.subscribe("drone0/process_error_unified_notification", 1, &telemetryStateReceiver::errorInformerCallback,this);
    watchdogSubs=nodeHandle.subscribe("drone0/processes_performance", 1, &telemetryStateReceiver::processPerformanceListCallback,this);


    start();
//    real_time=ros;
}

void telemetryStateReceiver::openSubscriptions_driverPelican(ros::NodeHandle nodeHandle){
    //Commands

    // Asctec Autopilot/Pelican Low-Level Telemetry
   // DronePelicanLLStatusSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LOGGER_LLSTATUS_SUBSCRIBER, 1, &telemetryStateReceiver::pelicanLLStatusCallback, this);
   // DronePelicanIMUCalcSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LOGGER_IMUCALCDATA_SUBSCRIBER, 1, &telemetryStateReceiver::pelicanIMUCalcDataCallback, this);
   // DronePelicanRCDataSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LOGGER_RCDATA_SUBSCRIBER, 1, &telemetryStateReceiver::droneRCDataPelicanCallback, this);//command/low_level
    DronePelicanControlInputSubs=nodeHandle.subscribe("drone0/" + DRONE_PELICAN_LIKE_SIMULATOR_CONTROL_INPUT_SUBSCRIBER, 1, &telemetryStateReceiver::droneInputPelicanCallback, this);//command/low_level
}


void telemetryStateReceiver::openSubscriptions_driverOkto(ros::NodeHandle nodeHandle){	
    //Sensor
  //  optFlowSubs=nodeHandle.subscribe("drone0/" + DRONE_OKTO_LIKE_SIMULATOR_GROUND_SPEED_SENSOR_PUBLISHER, 1, &telemetryStateReceiver::optFlowCallback, this);
    //Commands
    oktoCommandsSubs=nodeHandle.subscribe("drone0/" + DRONE_OKTO_LIKE_SIMULATOR_OKTO_COMMANDS_SUBSCRIBER, 1, &telemetryStateReceiver::oktoCommandsCallback, this);
}


telemetryStateReceiver::~telemetryStateReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
	wait();
}



void telemetryStateReceiver::run() {
    ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}



void telemetryStateReceiver::dronePitchRollCmdCallback(const droneMsgsROS::dronePitchRollCmd::ConstPtr& msg)
{
    DronePitchRollCmdMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received rollCmd from command/pitch_roll: [%f]", msg->rollCmd);
    ROS_INFO("Received pitchCmd from command/pitch_roll: [%f]", msg->pitchCmd);
    Q_EMIT updateStatus();
    return;

}

void telemetryStateReceiver::droneDAltitudeCmdCallback(const droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
    DroneDAltitudeCmdMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from command/dAltitude: [%f]", msg->dAltitudeCmd);
    return;
}

void telemetryStateReceiver::droneDYawCmdCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg)
{
    DroneDYawCmdMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from command/dYaw: [%f]", msg->dYawCmd);

    return;
}

void telemetryStateReceiver::droneHLCallback(const droneMsgsROS::droneCommand::ConstPtr& msg)
{
    DroneCommandMsgs=*msg;
    Q_EMIT parameterReceived();
    return;
}

void telemetryStateReceiver::droneLLCallback(const droneMsgsROS::droneDYawCmd::ConstPtr& msg)
{
    DroneDYawCmdMsgs=*msg;
    Q_EMIT parameterReceived();
    return;
}


void telemetryStateReceiver::imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
    ImuMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from IMU angular velocity x: [%f]", msg->angular_velocity.x);
    ROS_INFO("Received description from IMU angular velocity y: [%f]", msg->angular_velocity.y);
    ROS_INFO("Received description from IMU angular velocity z: [%f]", msg->angular_velocity.z);
    ROS_INFO("Received description from IMU angular velocity covariance: [%f]", msg->angular_velocity_covariance);
    ROS_INFO("Received description from IMU linear acceleration: [%f]", msg->linear_acceleration);
    ROS_INFO("Received description from IMU linear acceleration covariance: [%f]", msg->linear_acceleration_covariance);
    ROS_INFO("Received description from IMU orientation x: [%f]", msg->orientation.x);
    ROS_INFO("Received description from IMU orientation y: [%f]", msg->orientation.y);
    ROS_INFO("Received description from IMU orientation z: [%f]", msg->orientation.z);
    ROS_INFO("Received description from IMU orientation w: [%f]", msg->orientation.w);
    ROS_INFO("Received description from IMU orientation covariance: [%f]", msg->orientation_covariance);
    return;
}

void telemetryStateReceiver::magnetometerCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
{
    MagnetometerMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from Magnetometer sensor vector x: [%f]", msg->vector.x);
    ROS_INFO("Received description from Magnetometer sensor vector y: [%f]", msg->vector.y);
    ROS_INFO("Received description from Magnetometer sensor vector z: [%f]", msg->vector.z);
    return;
}

void telemetryStateReceiver::batteryCallback(const droneMsgsROS::battery::ConstPtr& msg)
{
    BatteryMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from Battery percent: [%f]", msg->batteryPercent);
    return;
}

void telemetryStateReceiver::altitudeCallback(const droneMsgsROS::droneAltitude::ConstPtr& msg)
{
    AltitudeMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received description from Altitude: [%f]", msg->altitude);
    ROS_INFO("Received description from Altitude speed: [%f]", msg->altitude_speed);
    return;
}

void telemetryStateReceiver::droneStatusSensorCallback(const droneMsgsROS::droneStatus::ConstPtr& msg)
{
    droneStatusMsgs=*msg; // status type
    Q_EMIT parameterReceived();
    return;
}

void telemetryStateReceiver::rotationAnglesCallback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)
{
    RotationAnglesMsgs=*msg;
    Q_EMIT parameterReceived();
    ROS_INFO("Received roll from drone0/rotation_angles: [%f]", msg->vector.x);
    ROS_INFO("Received pitch from drone0/rotation_angles: [%f]", msg->vector.y);
    ROS_INFO("Received yaw from drone0/rotation_angles: [%f]", msg->vector.z);
    return;
}

void telemetryStateReceiver::dronePositionCallback(const droneMsgsROS::dronePose::ConstPtr& msg)
{
    DronePoseMsgs=*msg;
    Q_EMIT parameterReceived();
  /*  ROS_INFO("Received position x: [%f]", msg->x);
    ROS_INFO("Received posistion y: [%f]", msg->y);
    ROS_INFO("Received position z: [%f]", msg->z);
    ROS_INFO("Received position pitch: [%f]", msg->pitch);
    ROS_INFO("Received position roll: [%f]", msg->roll);
    ROS_INFO("Received position yaw: [%f]", msg->yaw);*/
    return;
}

void telemetryStateReceiver::groundSpeedCallback(const droneMsgsROS::vector2Stamped::ConstPtr& msg)
{
    GroundSpeedMsgs=*msg;
    Q_EMIT parameterReceived();
 /*   ROS_INFO("Received x speed from drone0/ground_speed: [%f]", msg->vector.x);
    ROS_INFO("Received y speed from drone0/ground_speed: [%f]", msg->vector.y);*/
    return;
}

void telemetryStateReceiver::errorInformerCallback(const droneMsgsROS::ProcessError::ConstPtr& msg){

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

void telemetryStateReceiver::processPerformanceListCallback(const droneMsgsROS::ProcessDescriptorList::ConstPtr& msg){


    listProcessState=*msg;
    qDebug() << "ASDADSJADANDFALKSDNKLSN";


    for(unsigned int i = 0; i < msg->process_list.size(); i = i + 1)
    {
     node_container= msg->process_list.at(i);
     node_container.name;
     ROS_INFO("ENRIQUE MENSAJE RECIBIDO!!!!!: [%d]",  node_container.current_state.state);
    }

    Q_EMIT supervisorStateReceived();

}




void telemetryStateReceiver::temperatureCallback(const  droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
}


void telemetryStateReceiver::pressureCallback(const  droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
}

void telemetryStateReceiver::statusSensorCallback(const  droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
}

void telemetryStateReceiver::droneInputPelicanCallback(const  droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
}

void telemetryStateReceiver::optFlowCallback(const  droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
}

void telemetryStateReceiver::oktoCommandsCallback(const  droneMsgsROS::droneDAltitudeCmd::ConstPtr& msg)
{
}

void telemetryStateReceiver::log( const LogLevel &level, const std::string &msg) {
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


