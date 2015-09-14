/*
  imagesReceiver
  Launchs a ROS node to subscribe and process images.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/


/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/images_receiver.h"

/*****************************************************************************
** Implementation
*****************************************************************************/

ImagesReceiver::ImagesReceiver(){
    subscriptions_complete = false;
}


void ImagesReceiver::openSubscriptions(ros::NodeHandle nodeHandle, std::string rosnamespace){
    
    if (!nodeHandle.getParam("drone_console_interface_sensor_bottom_camera", drone_console_interface_sensor_bottom_camera))
      drone_console_interface_sensor_bottom_camera = "camera/bottom/image_raw";

    if (!nodeHandle.getParam("drone_console_interface_sensor_front_camera", drone_console_interface_sensor_front_camera))
      drone_console_interface_sensor_front_camera = "camera/front/image_raw";

    // Topic communications
    image_transport::ImageTransport it_(nodeHandle);
    image_bottom_sub_ = it_.subscribe(rosnamespace + "/" + drone_console_interface_sensor_bottom_camera, 1,&ImagesReceiver::imagesBottomReceptionCallback, this);
    image_front_sub_ = it_.subscribe(rosnamespace + "/" +  drone_console_interface_sensor_front_camera, 1,&ImagesReceiver::imagesFrontReceptionCallback, this);
    //start();
    //    real_time=ros;
    subscriptions_complete = true;
}


bool ImagesReceiver::ready() {
    if (!subscriptions_complete)
        return false;
    return true; //Used this way instead of "return subscriptions_complete" due to preserve add more conditions
}

ImagesReceiver::~ImagesReceiver() {}

QImage ImagesReceiver::cvtCvMat2QImage(const cv::Mat & image){
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
        printf("Wrong image format\n");
    }
    return qtemp;
}


void ImagesReceiver::imagesBottomReceptionCallback(const sensor_msgs::ImageConstPtr& msg){

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



        log(Info,std::string("Received bottom camera images"));
        Q_EMIT Update_Image(&px,2);
}

void ImagesReceiver::imagesFrontReceptionCallback(const sensor_msgs::ImageConstPtr& msg){

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

        log(Info,std::string("Received front camera images"));
        Q_EMIT Update_Image(&px,1);
}


void ImagesReceiver::log( const LogLevel &level, const std::string &msg) {
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




