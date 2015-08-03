/**
 * @file /include/GroundControlSystem/sceneManager.hpp
 *
 * @brief Launch a ROS node thread to communicate the interface with rviz.
 *
 * @date March 2015
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef GroundControlSystem_SCENEMANAGER_HPP_
#define GroundControlSystem_SCENEMANAGER_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>


/*****************************************************************************
** Class
*****************************************************************************/

class SceneManager : public QThread {
    Q_OBJECT
public:
	SceneManager(int argc, char** argv );
	virtual ~SceneManager();
	bool init();

Q_SIGNALS:
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
};


#endif /* GroundControlSystem_SCENEMANAGER_HPP_ */
