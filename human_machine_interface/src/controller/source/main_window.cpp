/*
  MainWindow
  Main window template and pop-up windows signals handlers.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

#include "../include/main_window.h"
#include "../../../../human_machine_interface-build/ui_mainwindow.h"
#include <qwt/qwt.h>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_text.h>
#include "qt4/QtGui/qwidget.h"
#include "qt4/QtGui/qevent.h"
#include <iostream>
#include <qt4/Qt/qpointer.h>
#include <qt4/Qt/qlabel.h>
#include <qt4/Qt/qfiledialog.h>
#include <qt4/Qt/qpixmap.h>
#include <qt4/Qt/qsize.h>
#include <qt4/Qt/qapplication.h>
#include <qt4/Qt/qdesktopwidget.h>
using namespace std;

MainWindow::MainWindow(int argc, char** argv,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //initialize ui member
{
    ui->setupUi(this);// connects all ui's triggers


    //Initialize views.
    errorCounter=0;
    ignore_resize=0;
    resize=0;
    num_of_auto_ops=2;
    max_osg_frame=0;


    ui->tabManager->setCurrentIndex(0); // ensure the first tab is showing

    connection = new Connection(this,argc,argv);
    processView = new ProcessMonitor(this,connection->graphReceiver);
    ui->gridPerformance->addWidget(processView,0,0);
    paramPlot = new ParameterTemporalSeries(this,connection->telemetryReceiver,connection->odometryReceiver);
    ui->gridParameters->addWidget(paramPlot,0,0);



    // Redimensionamos el QOSGWidget al tamaño de los frames que queremos renderizar.
     osg_sphere= new SphereView(ui->sphereScene->buddy(),connection->telemetryReceiver);
     osg_sphere->resize(320, 450);
     osg_uav= new VehicleView(ui->vehicleScene->buddy(),connection->telemetryReceiver);
     osg_uav->resize(320, 450);

     QDesktopWidget desktop;
     int desktopHeight=desktop.geometry().height();
     int desktopWidth=desktop.geometry().width();
     qDebug() << desktopHeight;
     qDebug() << desktopWidth;

     if(desktopHeight<=1024){ // UI design 1
       osg_uav->resize(320, 300);
       osg_sphere->resize(320, 250);
       ui->tab_dynamicView->setMaximumSize(QSize(350, 240));
       delete ui->panel_vehicle; // destroy the default panels
       delete ui->panel_sphere;
     }

      this->current_time = new QTime(0,0,0);



    // Mostraremos un nuevo frame cada 1 ms.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
    timer->start(1);



    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    ui->gridCamera->addWidget(widget,0,0);
    setSignalHandlers();

    setWindowIcon(QIcon(":/images/images/drone-icon.png"));
    this->setWindowTitle(QString::fromUtf8("Human Machine Interface"));

    setTimerInterval(1000);// 1 second = 1000
    //Initialize threads
    //usercommander.init();
    //collector.init();

    flightTimer = new QTimer(this);
    flightTimer->start(1000);

   old_height=this->height();
   initializeCameraView();
}


// reconstruir interfaz para dispositivo portatil
void MainWindow::resizeEvent(QResizeEvent* event)
{

  /* QMainWindow::resizeEvent(event);
   if((ignore_resize % num_of_auto_ops) == 0&&old_height!=this->height()){
       if(ui->sphereScene->size().height()>=ui->vehicleScene->size().height()){
          osg_uav->resize(ui->sphereScene->size());
          osg_sphere->resize(ui->sphereScene->size());
       }
       if(ui->sphereScene->size().height()<=ui->vehicleScene->size().height()){
           osg_sphere->resize(ui->vehicleScene->size());
            osg_sphere->resize(320, (int)(ui->sphereScene->size().height()-resize));
            osg_uav->resize(320,(int)(ui->sphereScene->size().height()-resize));
            qDebug()<<"isMinimized";
           osg_uav->resize(ui->vehicleScene->size());
       }
    ignore_resize = 0;
   }
   if(old_height>this->height()){
              resize++;
   }

   ignore_resize++;
   old_height=this->height();*/
}

void MainWindow::show_frame()
{
  /*  if(this->isMaximized()&&max_osg_frame!=1){

        qDebug()<<"MAX";
        if(ui->sphereScene->size().height()>ui->vehicleScene->size().height()){
            osg_uav->resize(ui->sphereScene->size());
            osg_sphere->resize(ui->sphereScene->size());
        }
        if(ui->sphereScene->size().height()<ui->vehicleScene->size().height()){
            osg_sphere->resize(ui->vehicleScene->size());
            osg_uav->resize(ui->vehicleScene->size());
        }
    }

    if(max_osg_frame==1)
        max_osg_frame=0;
    max_osg_frame++;*/

    // Get the frame and visualize with a pixmap in a QLabel.
     ui->sphereScene->setPixmap(osg_sphere->renderPixmap(0,0,true));
     ui->vehicleScene->setPixmap(osg_uav->renderPixmap(0,0,true));

}


void MainWindow::setTimerInterval(double ms)
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

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::setSignalHandlers()
{
    connect(connection, SIGNAL(rosShutdown()), this, SLOT(close())); //Close the app.
    connect(connection,SIGNAL(connectionEstablish( )),this, SLOT(testConnection()));
    connect(connection->telemetryReceiver, SIGNAL(parameterReceived()), this, SLOT(updateStatusBar( )));
    //connect(connection->telemetryReceiver, SIGNAL( parameterReceived( )), this, SLOT(show_frame()));
    connect(ui->takeoffButton,SIGNAL(clicked()),this, SLOT(onStartButton()));
    connect(ui->landButton,SIGNAL(clicked()),this, SLOT(onLandButton()));
    connect(ui->resetButton,SIGNAL(clicked()),this, SLOT(onResetCommandButton()));
    connect(ui->hoverButton,SIGNAL(clicked()),this, SLOT(onHoverButton()));
    connect(ui->emergencyStop_Button,SIGNAL(clicked()),this, SLOT(onEmergencyStopButton()));
    connect(ui->oneCameraButton, SIGNAL(clicked()), this, SLOT(displayOneCamera()));
    connect(ui->mainCameraButton, SIGNAL(clicked()), this, SLOT(displayMainGridCamera()));
    connect(ui->fourCameraButton, SIGNAL(clicked()), this, SLOT(displayFourGridCamera()));
    connect(ui->saveImageButton, SIGNAL(clicked()), this, SLOT(saveCurrentCameraView()));
    connect(connection->graphReceiver, SIGNAL( errorInformerReceived( )), this, SLOT( incrementErrorsCounter( )));

}

void MainWindow::saveCurrentCameraView(){
  disconnect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
  Q_EMIT saveImage(camera_view_manager);
  connect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
}

void MainWindow::initializeCameraView(){
    camera_view_manager=0;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    ui->gridCamera->addWidget(widget,0,0);
    oneoption= new CameraOneOption(this,connection->imgReceiver);
    ui->gridCamera->addWidget(oneoption,0,0);

}

void MainWindow::displayOneCamera()
{
        camera_view_manager=0;
        QWidget* widget = new QWidget();
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        ui->gridCamera->addWidget(widget,0,0);
         if(!isOpen_oneCameraView) oneoption= new CameraOneOption(this,connection->imgReceiver);
        ui->gridCamera->addWidget(oneoption,0,0);
        isOpen_oneCameraView=true;
}
void MainWindow::displayMainGridCamera(){
        camera_view_manager=1;
        QWidget* widget = new QWidget();
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ui->gridCamera->addWidget(widget,0,0);
        if(!isOpen_mainCameraView)
            mainoption= new CameraDisplayOption(this,connection->imgReceiver);
        ui->gridCamera->addWidget(mainoption,0,0);
        isOpen_mainCameraView=true;
}

void MainWindow::displayFourGridCamera(){
  if(!isOpen_fourCameraView){
    camera_view_manager=3;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    ui->gridCamera->addWidget(widget,0,0);
    fourCamera= new fourCameraOption(this);
    ui->gridCamera->addWidget(fourCamera,0,0);
    isOpen_fourCameraView=true;
  }
}


void MainWindow::close()
{
    this->~MainWindow();
}
void MainWindow::showNoMasterMessage() {
    QMessageBox msgBox;
    msgBox.setText("roscore node could have not been initialized");
    msgBox.exec();
}


void MainWindow::flightTime()
{
    this->current_time->setHMS(this->current_time->addSecs(+1).hour(),this->current_time->addSecs(+1).minute(),this->current_time->addSecs(+1).second());
    QString text = this->current_time->toString();
    ui->value_FligthTime->setText(text);
}


void MainWindow::incrementErrorsCounter()
{
    errorCounter++;
    ui->value_Errors->setText(QString::number(errorCounter));
}

void MainWindow::updateStatusBar()
{

   if (connection->connectStatus){



   switch(connection->telemetryReceiver->droneStatusMsgs.status)
   {
               case droneMsgsROS::droneStatus::UNKNOWN:
                   ui->value_currentGoal->setText("Unknown"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::INITED:
                   ui->value_currentGoal->setText("Init"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::LANDED:
                   ui->value_currentGoal->setText("Landed"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::FLYING:
                   ui->value_currentGoal->setText("Flying"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::HOVERING:
                   ui->value_currentGoal->setText("Hovering"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::TAKING_OFF:
                   ui->value_currentGoal->setText("Taking off"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::LANDING:
                   ui->value_currentGoal->setText("Landing"); //refresh();
                   break;
               case droneMsgsROS::droneStatus::LOOPING:
                   ui->value_currentGoal->setText("Looping"); //refresh();
   }


   if(connection->telemetryReceiver->batteryMsgs.batteryPercent<=25.0){
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::WindowText,Qt::red);
    ui->value_battery->setPalette(*palette);
   }

   ui->value_battery->setText(QString::number(connection->telemetryReceiver->batteryMsgs.batteryPercent) +  "%");

   ui->valueSphere_X->setText(QString::number(((double)((int)(connection->odometryReceiver->DronePoseMsgs.x*100)))/100) + "  m");
   ui->valueSphere_Y->setText(QString::number(((double)((int)(connection->odometryReceiver->DronePoseMsgs.y*100)))/100) + "  m");
   ui->valueSphere_Z->setText(QString::number(((double)((int)(connection->odometryReceiver->DronePoseMsgs.z*100)))/100) + "  m");
   ui->valueSphere_yaw->setText(QString::number(((double)((int)(connection->telemetryReceiver->rotationAnglesMsgs.vector.z*100)))/100) + "  deg");
   ui->valueSphere_roll->setText(QString::number(((double)((int)(connection->telemetryReceiver->rotationAnglesMsgs.vector.x*100)))/100) + "  deg");
   ui->valueSphere_pitch->setText(QString::number(((double)((int)(connection->telemetryReceiver->rotationAnglesMsgs.vector.y*100)))/100) + "  deg");


// vehicle

   ui->valueVehicle_X->setText(QString::number(((double)((int)(connection->odometryReceiver->DronePoseMsgs.x*100)))/100) + "  m");
   ui->valueVehicle_Y->setText(QString::number(((double)((int)(connection->odometryReceiver->DronePoseMsgs.y*100)))/100) + "  m");
   ui->valueVehicle_Z->setText(QString::number(((double)((int)(connection->odometryReceiver->DronePoseMsgs.z*100)))/100) + "  m");
   ui->valueVehicle_Yaw->setText(QString::number(((double)((int)(connection->telemetryReceiver->rotationAnglesMsgs.vector.z*100)))/100) + "  deg");
   ui->valueVehicle_pitch->setText(QString::number(((double)((int)(connection->telemetryReceiver->rotationAnglesMsgs.vector.x*100)))/100) + "  deg");
   ui->valueVehicle_roll->setText(QString::number(((double)((int)(connection->telemetryReceiver->rotationAnglesMsgs.vector.y*100)))/100) + "  deg");

   }
}


void MainWindow::showConnectionEstablished() {
    QMessageBox msgBox;
    msgBox.setText("The connection has been established succesfully.");
    msgBox.exec();
}


void MainWindow::testConnection() {
    if (!connection->connectStatus){
        cout << "roscore node could have not been initialized" << '\n';
        showNoMasterMessage();
    }else{
        //showConnectionEstablished();
        ui->value_wifi->setText("Connected");

        connect(flightTimer, SIGNAL(timeout()), this, SLOT(flightTime()));
    }
}


void MainWindow::on_actionAbout_Human_Machine_Interface_triggered()
{
    QMessageBox::about(this, tr("About ..."),tr("<h2>Human Machine Interface</h2><p>Universidad Politecnica de Madrid</p><p>The Human Machine Interface allows operators or users of the system to bi-directionally communicate with each aerial robotic agent.</p>"));
}

void MainWindow::on_actionContents_triggered()
{
    QMessageBox::about(this, tr("Contents ..."),tr("<h2>Human Machine Interface</h2><p>Universidad Politecnica de Madrid</p><p>...</p>"));
}

void MainWindow::on_actionUser_Commands_Manual_triggered()
{
    QMessageBox::about(this, tr("Manual Control Guided ..."),tr("<h2>Human Machine Interface</h2><p>Keyboard Bindings List</p><p>TAKE_OFF = t</p><p>LAND = y</p><p>EMERGENCY_STOP = space</p><p>HOVER = h</p><p>MOVE = m</p><p>RESET_COMMANDS= s</p><p>MOVE_UPWARDS = q</p><p>MOVE_DOWNWARDS = a</p><p>TURN_COUNTER_CLOCKWISE = z</p><p>TURN_CLOCKWISE = x</p><p>SET_YAW_REFERENCE_TO_0 = backslash</p><p>MOVE_FORWARD = up </p><p>MOVE_BACK = down</p><p>MOVE_RIGHT = right</p><p>MOVE_LEFT = left</p>"));
}


void MainWindow::on_actionCommunication_Console_triggered()
{
    consoleView = new CommunicationConsole(this,connection->imgReceiver,connection->telemetryReceiver);
    consoleView->setWindowTitle("Communicaton Console");
    consoleView->show();
}


void MainWindow::on_actionOpen_perception_configuration_triggered()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
    file_name = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("All files (*.*)"));
    QMessageBox::information(this,tr("File Name"),file_name);
    connect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
}


void MainWindow::on_actionNew_connection_triggered()
{
    connection->setWindowTitle("New Connection");
    connection->show();
}


void MainWindow::on_actionParameter_Temporal_Series_triggered()
{
    paramPlot = new ParameterTemporalSeries(this,connection->telemetryReceiver);
    paramPlot->setWindowTitle("Parameter Temporal Series");
    //paramPlot->parameterTemporalSeries-
    paramPlot->show();

}

// Control Mode
/*
void MainWindow::onControlModeChange(){
   std::stringstream key;
   key << "tab";
   usercommander.msg.type = key.str();
   usercommander.publish();
}

// User commands in GUI
*/

void MainWindow::onStartButton(){ // TAKE OFF
    qDebug()<<"TAKE OFF PRESS BUTTON";
    connection->usercommander->order = 1;
    connection->usercommander->publish_takeoff();

}
void MainWindow::onLandButton(){ // LAND
    qDebug()<<"LAND PRESS BUTTON";
    connection->usercommander->order = 3;
    connection->usercommander->publish_land();

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //connection->odometryReceiver->shutdown();
    //connection->telemetryReceiver->shutdown();
    //writeSettings();
    QMainWindow::closeEvent(event);
}

void MainWindow::onResetCommandButton(){ // RESET COMMANDS
    qDebug()<<"RESET PRESS BUTTON";
    connection->usercommander->order = 5;
    connection->usercommander->publish_reset();
}

void MainWindow::onHoverButton(){ // HOVER

    qDebug()<<"HOVER PRESS BUTTON";
    connection->usercommander->order = 2;
    connection->usercommander->publish_hover();

}

void MainWindow::onEmergencyStopButton(){ // EMERGENCY STOP

    qDebug()<<"EMERGENCY STOP PRESS BUTTON";
    connection->usercommander->order = 5;
    connection->usercommander->publish_emergencyStop();

}
/*
void MainWindow::onHoverButton(){ // HOVER
    std::stringstream key;
    key << "h";
    usercommander.msg.type  = key.str();
    usercommander.publish();

}
void MainWindow::onEmergencyStopButton(){ // EMERGENCY STOP
    std::stringstream key;
    key << "del";
    usercommander.msg.type  = key.str();
    usercommander.publish();

}
void MainWindow::onLandButton(){ // LAND
    std::stringstream key;
    key << "y";
    usercommander.msg.type  = key.str();
    usercommander.publish();

}
void MainWindow::onYawZeroButton(){ // YAW ZERO
    std::stringstream key;
    key << "z";
    usercommander.msg.type  = key.str();
    usercommander.publish();

}
void MainWindow::onResetCommandButton(){ // RESET COMMANDS
    std::stringstream key;
    key << "x";
    usercommander.msg.type  = key.str();
    usercommander.publish();

}
 */
// User commands in the keyboard
void MainWindow::keyPressEvent(QKeyEvent *e){
 /*   std::stringstream key;
    switch(e->key())
    {
      case Qt::Key_8:
        qDebug()<<"RIGHT PRESS BUTTON";
        connection->usercommander->order = 7;
        connection->usercommander->publish_LLCommand();
      break;

      case Qt::Key_4:
      key << "left";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;

      case Qt::Key_2:
      key << "down";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;

      case Qt::Key_6:
      key << "right";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;

    default:
     MainWindow::keyPressEvent(e);

      case Qt::Key_W:
      key << "w";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;

      case Qt::Key_S:
      key << "s";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;

      case Qt::Key_A:
      key << "a";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;

      case Qt::Key_D:
      key << "d";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;


      case Qt::Key_Q:
      key << "q";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;


      case Qt::Key_E:
      key << "e";
      usercommander.msg.type  = key.str();
      break;


      case Qt::Key_H: //hover
      key << "h";
      usercommander.msg.type  = key.str();
      usercommander.publish();
      break;


      default:
       usercommander.msg.type  = "";
       usercommander.publish();
       MainWindow::keyPressEvent(e);*/

    }



