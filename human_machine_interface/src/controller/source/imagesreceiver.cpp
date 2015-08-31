/*
  imagesReceiver
  Launch a ROS node to subscribe images sent by image_transport topic.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/



#include "../include/imagesreceiver.h"

/*****************************************************************************
** Implementation
*****************************************************************************/

imagesReceiver::imagesReceiver(){}


void imagesReceiver::openSubscriptions(ros::NodeHandle nodeHandle){
    // Topic communications
    image_transport::ImageTransport it_(nodeHandle);
    image_bottom_sub_ = it_.subscribe("drone0/" + DRONE_CONSOLE_INTERFACE_SENSOR_BOTTOM_CAMERA, 1,&imagesReceiver::imagesBottomReceptionCallback, this);
    image_front_sub_ = it_.subscribe("drone0/" + DRONE_CONSOLE_INTERFACE_SENSOR_FRONT_CAMERA, 1,&imagesReceiver::imagesFrontReceptionCallback, this);
    start();
//    real_time=ros;
}


QImage imagesReceiver::cvtCvMat2QImage(const cv::Mat & image){
    QImage qtemp;
        if(!image.empty() && image.depth() == CV_8U)
        {
            const unsigned char * data = image.data;
            qtemp = QImage(image.cols, image.rows, QImage::Format_RGB32);
            for(int y = 0; y < image.rows; ++y, data += image.cols*image.elemSize())
            {
                for(int x = 0; x < image.cols; ++x)
                {
                    QRgb * p = ((QRgb*)qtemp.scanLine (y)) + x;
                    *p = qRgb(data[x * image.channels()+2], data[x * image.channels()+1], data[x * image.channels()]);
                }
            }
        }
        else if(!image.empty() && image.depth() != CV_8U)
        {
            printf("Wrong image format, must be 8_bits\n");
        }
        return qtemp;
}




void imagesReceiver::run() {
    ros::spin();
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void imagesReceiver::imagesBottomReceptionCallback(const sensor_msgs::ImageConstPtr& msg){
    //(const std_msgs::String::ConstPtr &msg) {
    //	ROS_INFO("I heard: [%s]", msg->data.c_str());
        cv_bridge::CvImagePtr cv_bottom_image;
          try
            {
              cv_bottom_image = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);

            }
            catch (cv_bridge::Exception& e)
            {
              ROS_ERROR("cv_bridge exception: %s", e.what());
              return;
            }
            px = QPixmap::fromImage(cvtCvMat2QImage(cv_bottom_image->image));


        //cv::imshow("Bottom Image",cv_bottom_image->image);
        //cv::waitKey(1);

        logging_model.insertRows(0,1);
        std::stringstream logging_msg;
        logging_msg << "[ INFO] [" << ros::Time::now() << "]: I heard: " << "camera";
        QVariant new_row(QString(logging_msg.str().c_str()));
        logging_model.setData(logging_model.index(0),new_row);
        Q_EMIT Update_Image2(&px);
}

void imagesReceiver::imagesFrontReceptionCallback(const sensor_msgs::ImageConstPtr& msg){
    //(const std_msgs::String::ConstPtr &msg) {
    //	ROS_INFO("I heard: [%s]", msg->data.c_str());
        cv_bridge::CvImagePtr cv_front_image;
          try
            {
              cv_front_image = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);

            }
            catch (cv_bridge::Exception& e)
            {
              ROS_ERROR("cv_bridge exception: %s", e.what());
              return;
            }
            px = QPixmap::fromImage(cvtCvMat2QImage(cv_front_image->image));


       // cv::imshow("Front Image",cv_front_image->image);
       // cv::waitKey(1);

        logging_model.insertRows(0,1);
        std::stringstream logging_msg;
        logging_msg << "[ INFO] [" << ros::Time::now() << "]: I heard: " << "camera";
        QVariant new_row(QString(logging_msg.str().c_str()));
        logging_model.setData(logging_model.index(0),new_row);
        Q_EMIT Update_Image1(&px);
}


void imagesReceiver::log( const LogLevel &level, const std::string &msg) {
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


imagesReceiver::~imagesReceiver() {
    if(ros::isStarted()) {
      ros::shutdown(); // Kill all open subscriptions, publications, service calls, and service servers.
      ros::waitForShutdown();
    }
    wait();
}

