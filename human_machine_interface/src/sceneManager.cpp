/*
  SceneManager
  Launch a ROS node thread to communicate the interface with rviz.
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
#include "../include/human_machine_interface/sceneManager.h"


/*****************************************************************************
** Implementation
*****************************************************************************/

SceneManager::SceneManager(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
	{}

SceneManager::~SceneManager() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
	wait();
}

bool SceneManager::init() {
    ros::init(init_argc,init_argv,"sceneManager");// ros node started.
    if ( ! ros::master::check() ) {// Check if roscore has been initialized.
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	start();
	return true;
}





