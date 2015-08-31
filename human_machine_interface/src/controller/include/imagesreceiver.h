#ifndef IMAGESRECEIVER_H
#define IMAGESRECEIVER_H

/*****************************************************************************
** Includes
*****************************************************************************/
#include <QThread>
#include <QString>
#include <QStringListModel>
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "communication_definition.h"
#include <sensor_msgs/image_encodings.h>

class imagesReceiver : public QThread {
    Q_OBJECT

public:
    imagesReceiver();
    virtual ~imagesReceiver();

    void run();

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
        void openSubscriptions(ros::NodeHandle nodeHandle);


Q_SIGNALS:
        void Update_Image1(const QPixmap* image);
        void Update_Image2(const QPixmap* image);
        void loggingUpdated();
        void rosShutdown();



private:
        QPixmap px;
        image_transport::Subscriber image_bottom_sub_;
        image_transport::Subscriber image_front_sub_;
        void imagesBottomReceptionCallback(const sensor_msgs::ImageConstPtr& msg);
        void imagesFrontReceptionCallback(const sensor_msgs::ImageConstPtr& msg);
        QImage cvtCvMat2QImage(const cv::Mat & image);
        QStringListModel logging_model;
};


#endif // IMAGESRECEIVER_H
