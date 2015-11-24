#include "../include/human_machine_interface/supervisor.h"
#include <stdlib.h>


mockROSmessages::mockROSmessages(QObject *parent)
{
    setTimerInterval(10000);// 1 second = 1000

}
void mockROSmessages::setTimerInterval(double ms)
{
    d_interval = qRound(ms);

    if ( d_timerId >= 0 )
    {
        killTimer(d_timerId);
        d_timerId = -1;
    }
    if (d_interval >= 0 )
        d_timerId = startTimer(d_interval);
}

void mockROSmessages::timerEvent(QTimerEvent *e){
    int error = rand()%25;
    switch(error)
    {
      case 1:
      supervisorMessage.text="Camera 3 has been restarted.";
      supervisorMessage.process="camera_processor";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 2:
      supervisorMessage.text="Camera 2 has been stopped.";
      supervisorMessage.process="camera_processor";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 3:
      supervisorMessage.text="Color segmentation has failed.";
      supervisorMessage.process="grid_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=4; //ERROR
      break;

      case 4:
      supervisorMessage.text="Bot detection initialization has failed.";
      supervisorMessage.process="robot_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=4;
      break;

      case 5:
      supervisorMessage.text="Robot detector has been stopped.";
      supervisorMessage.process="robot_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 6:
      supervisorMessage.text="Tracker has been stopped.";
      supervisorMessage.process="robot_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 7:
      supervisorMessage.text="Bot detection could not be initialized.";
      supervisorMessage.process="robot_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=3;
      break;

      case 8:
      supervisorMessage.text="Bot identification has stopped.";
      supervisorMessage.process="robot_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=4;
      break;


      case 9:
      supervisorMessage.text="Bot labelling could not be initialized.";
      supervisorMessage.process="robot_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=4; //ERROR
      break;


      case 10:
      supervisorMessage.text="Grid detection could not be initialized.";
      supervisorMessage.process="grid_detector";
      supervisorMessage.topic="";
      supervisorMessage.severity=4; //ERROR
      break;


      case 11:
      supervisorMessage.text="Prediction time to reach the zone has failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=4;
      break;


      case 12:
      supervisorMessage.text="Pole do not allow follow predicted trayectory.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=3; //Warning
      break;

      case 13:
      supervisorMessage.text="UAV lost the target.";
      supervisorMessage.process="mission_planner";
      supervisorMessage.topic="";
      supervisorMessage.severity=3; //Warning
      break;

      case 14:
      supervisorMessage.text="Driver camera 1 has been restarted.";
      supervisorMessage.process="camera_driver";
      supervisorMessage.topic="";
      supervisorMessage.severity=1; //Info
      break;

      case 15:
      supervisorMessage.text="Initialization camera has failed.";
      supervisorMessage.process="camera_driver";
      supervisorMessage.topic="";
      supervisorMessage.severity=4;
      break;

      case 16:
      supervisorMessage.text="Camera initialization message is empty.";
      supervisorMessage.process="camera_driver";
      supervisorMessage.topic="";
      supervisorMessage.severity=4;
      break;


      case 17:
      supervisorMessage.text="Driver camera process abort execution.";
      supervisorMessage.process="camera_driver";
      supervisorMessage.topic="";
      supervisorMessage.severity=4;
      break;

      case 18:
      supervisorMessage.text="The land zone is occupied.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 19:
      supervisorMessage.text="Low battery";
      supervisorMessage.process="pilot_driver";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 20:
      supervisorMessage.text="Current touch ground robot failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 21:
      supervisorMessage.text="Current action getClose has failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 22:
      supervisorMessage.text="Current action getClose has failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 23:
      supervisorMessage.text="Current action LandBack has failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 24:
      supervisorMessage.text="Current action landFront has failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      case 25:
      supervisorMessage.text="Current action hover has failed.";
      supervisorMessage.process="flight_controller";
      supervisorMessage.topic="";
      supervisorMessage.severity=1;
      break;

      default:
        ;
    }
}
