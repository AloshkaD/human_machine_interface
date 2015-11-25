/*!*******************************************************************************************
 *  \file       images_receiver.h
 *  \brief      ImagesReceiver definition file.
 *  \details    This file includes the ImagesReceiver class declaration. To obtain more
 *              information about it's definition consult the images_receiver.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/

#ifndef IMAGESRECEIVER_H
#define IMAGESRECEIVER_H

/*****************************************************************************
** Includes
*****************************************************************************/
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include "communication_definition.h"

#include <qt4/Qt/qthread.h>
#include <qt4/Qt/qstring.h>
#include <qt4/Qt/qstringlistmodel.h>
class ImagesReceiver : public QObject{
    Q_OBJECT

public:
    ImagesReceiver();
    virtual ~ImagesReceiver();

    


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
        void onControlModeChange(QString key);
        bool ready(); 


Q_SIGNALS:
        void Update_Image(const QPixmap* image, int id_camera);
        void loggingUpdated();



private:
        bool subscriptions_complete;

        std::string drone_console_interface_sensor_bottom_camera;
        std::string drone_console_interface_sensor_front_camera;
        
        QPixmap px;
        ros::MultiThreadedSpinner threadSpin;
        image_transport::Subscriber image_bottom_sub_;
        image_transport::Subscriber image_front_sub_;
        void imagesBottomReceptionCallback(const sensor_msgs::ImageConstPtr& msg);
        void imagesFrontReceptionCallback(const sensor_msgs::ImageConstPtr& msg);
        QImage cvtCvMat2QImage(const cv::Mat & image);
        QStringListModel logging_model;
};


#endif // IMAGESRECEIVER_H
