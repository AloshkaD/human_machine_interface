/*
  MainWindow
  Main window template and pop-up windows signals handlers.
  @author  Yolanda de la Hoz Simón
  @date    03-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/main_window.h"
#include "../.././../../../src-build/human_machine_interface/ui_mainwindow.h"
#include "qt4/QtGui/qwidget.h"
#include "qt4/QtGui/qevent.h"
#include <iostream>
#include <qt4/Qt/qpointer.h>
#include <qt4/Qt/qcombobox.h>
#include <qt4/Qt/qlabel.h>
#include <qt4/Qt/qfiledialog.h>
#include <qt4/Qt/qpixmap.h>
#include <qt4/Qt/qsize.h>
#include <qt4/Qt/qapplication.h>
#include <qt4/Qt/qdesktopwidget.h>

//Define step commands
#define CTE_COMMAND_YAW    0.40
#define CTE_COMMAND_PITCH  0.33
#define CTE_COMMAND_ROLL   0.33
#define CTE_COMMAND_HEIGHT 0.50


// Define controller commands define constants
#define CONTROLLER_CTE_COMMAND_SPEED        ( 1.00 )
#define CONTROLLER_STEP_COMMAND_POSITTION   ( 0.25 )
#define CONTROLLER_STEP_COMMAND_ALTITUDE    ( 0.25 )
#define CONTROLLER_STEP_COMMAND_YAW         ( 10.0 * (M_PI/180.0) )


using namespace std;
/*****************************************************************************
** Implementation
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //initialize ui member
{
    ui->setupUi(this);// connects all ui's triggers

    setWindowIcon(QIcon(":/images/images/drone-icon.png"));
    this->setWindowTitle(QString::fromUtf8("Human Machine Interface"));

    ignore_resize=0;
    resize=0;
    num_of_auto_ops=2;
    max_osg_frame=0;
    errorCounter=0;// counter error for performance_monitor
    designLaptop=false;

    ui->tabManager->setCurrentIndex(0); // ensure the first tab is showing

    // Initilialize views
    connection = new Connection(this,argc,argv);
    processView = new PerformanceMonitor(this,connection->graphReceiver);
    ui->gridPerformance->addWidget(processView,0,0);
    paramPlot = new ParameterTemporalSeries(this,connection->telemetryReceiver,connection->odometryReceiver);
    ui->gridParameters->addWidget(paramPlot,0,0);
    osg_sphere= new SphereView(ui->sphereScene->buddy(),connection->telemetryReceiver);
    osg_sphere->resize(320, 450);    // Resize the QOSGWidget to the size of frames to render
    osg_uav= new VehicleView(ui->vehicleScene->buddy(),connection->telemetryReceiver);
    osg_uav->resize(320, 450);

    timer = new QTimer(this); // Shows new frames rate -> 1 ms.
    connect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
    timer->start(1);

    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    ui->gridCamera->addWidget(widget,0,0);
    initializeCameraView();
    setSignalHandlers(); // triggers


    // UI design laptop

    QDesktopWidget desktop;
    int desktopHeight=desktop.geometry().height();
    int desktopWidth=desktop.geometry().width();
    qDebug() << desktopHeight;
    qDebug() << desktopWidth;

    if(desktopHeight<=1024){
        designLaptop=true;
        osg_uav->resize(320, 300);
        osg_sphere->resize(320, 250);
        ui->tab_dynamicView->setMaximumSize(QSize(350, 280));
        delete ui->panel_vehicle; // destroy the default panels
        delete ui->panel_sphere;
    }

    this->current_time = new QTime(0,0,0);
    setTimerInterval(1000);// 1 second = 1000

    flightTimer = new QTimer(this);
    flightTimer->start(1000);

    old_height=this->height();

}


void MainWindow::resizeEventDynamicView(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    if((ignore_resize % num_of_auto_ops) == 0&&old_height!=this->height()){
        if(ui->sphereScene->size().height()>=ui->vehicleScene->size().height()){
            osg_uav->resize(ui->sphereScene->size());
            osg_sphere->resize(ui->sphereScene->size());
        }
        if(ui->sphereScene->size().height()<=ui->vehicleScene->size().height()){
            osg_sphere->resize(ui->vehicleScene->size());
            osg_sphere->resize(320, (int)(ui->sphereScene->size().height()-resize));
            osg_uav->resize(320,(int)(ui->sphereScene->size().height()-resize));
            osg_uav->resize(ui->vehicleScene->size());
        }
        ignore_resize = 0;
    }
    if(old_height>this->height()){
        resize++;
    }

    ignore_resize++;
    old_height=this->height();
}

void MainWindow::show_frame()
{
    /*  if(this->isMaximized()&&max_osg_frame!=1){

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
    ui->sphereScene->setPixmap(osg_sphere->renderPixmap(0,0,false));
    ui->vehicleScene->setPixmap(osg_uav->renderPixmap(0,0,false));

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


void MainWindow::setSignalHandlers()
{
    connect(connection, SIGNAL(rosShutdown()), this, SLOT(close())); //Close the app.
    connect(connection,SIGNAL(connectionEstablish( )),this, SLOT(testConnection()));
    connect(connection->telemetryReceiver, SIGNAL(parameterReceived()), this, SLOT(updateStatusBar( )));
    //connect(connection->telemetryReceiver, SIGNAL( parameterReceived( )), this, SLOT(show_frame()));
    connect(ui->takeoffButton,SIGNAL(clicked()),this, SLOT(onStartButton()));
    connect(ui->landButton,SIGNAL(clicked()),this, SLOT(onLandButton()));
    //connect(ui->resetButton,SIGNAL(clicked()),this, SLOT(onResetCommandButton()));
    connect(ui->hoverButton,SIGNAL(clicked()),this, SLOT(onHoverButton()));
    //connect(ui->emergencyStop_Button,SIGNAL(clicked()),this, SLOT(onEmergencyStopButton()));
    connect(ui->oneCameraButton, SIGNAL(clicked()), this, SLOT(displayOneCamera()));
    connect(ui->mainCameraButton, SIGNAL(clicked()), this, SLOT(displayMainGridCamera()));
    connect(ui->fourCameraButton, SIGNAL(clicked()), this, SLOT(displayFourGridCamera()));
    connect(ui->saveImageButton, SIGNAL(clicked()), this, SLOT(saveCurrentCameraView()));
    connect(ui->selection_mode, SIGNAL(currentIndexChanged(int)), this, SLOT(onControlModeChange(int)));
    connect(connection->graphReceiver, SIGNAL( errorInformerReceived( )), this, SLOT( incrementErrorsCounter( )));

    disconnect(ui->mainCameraButton, SIGNAL(clicked()), this, SLOT(displayMainGridCamera()));
    disconnect(ui->fourCameraButton, SIGNAL(clicked()), this, SLOT(displayFourGridCamera()));
}

void MainWindow::saveCurrentCameraView()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
    Q_EMIT saveImage(camera_view_manager);
    connect(timer, SIGNAL(timeout()), this, SLOT(show_frame()));
}

void MainWindow::initializeCameraView()
{
    camera_view_manager=0;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    ui->gridCamera->addWidget(widget,0,0);
    oneoption= new CameraMainOption(this,connection->imgReceiver);
    ui->gridCamera->addWidget(oneoption,0,0);

}

void MainWindow::displayOneCamera()
{
    camera_view_manager=0;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    ui->gridCamera->addWidget(widget,0,0);
    if(!isOpen_oneCameraView) oneoption= new CameraMainOption(this,connection->imgReceiver);
    ui->gridCamera->addWidget(oneoption,0,0);
    isOpen_oneCameraView=true;
}
void MainWindow::displayMainGridCamera()
{
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

void MainWindow::displayFourGridCamera()
{
    if(!isOpen_fourCameraView){
        camera_view_manager=3;
        QWidget* widget = new QWidget();
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        ui->gridCamera->addWidget(widget,0,0);
        fourCamera= new CameraGridOption(this);
        ui->gridCamera->addWidget(fourCamera,0,0);
        isOpen_fourCameraView=true;
    }
}



void MainWindow::showNoMasterMessage()
{
    QMessageBox msgBox;
    msgBox.setText("roscore node could have not been initialized");
    msgBox.exec();
}


void MainWindow::flightTime()
{
    /*this->current_time->setHMS(this->current_time->addSecs(+1).hour(),this->current_time->addSecs(+1).minute(),this->current_time->addSecs(+1).second());
    QString text = this->current_time->toString();
    ui->value_FligthTime->setText(text);*/
}


void MainWindow::incrementErrorsCounter()
{
    if (connection->connectStatus){
        errorCounter++;
        ui->value_Errors->setText(QString::number(errorCounter));
    }
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

        if(!designLaptop){

            // sphere
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
}

void MainWindow::testConnection()
{
    if (!connection->connectStatus){
        cout << "roscore node could have not been initialized" << '\n';
        showNoMasterMessage();
    }else{
        showConnectionEstablished();
        ui->value_wifi->setText("Connected");

        connect(flightTimer, SIGNAL(timeout()), this, SLOT(flightTime()));
    }
}

// Pop-up windows///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::showConnectionEstablished()
{
    QMessageBox msgBox;
    msgBox.setText("The connection has been established succesfully.");
    msgBox.exec();
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
    /*consoleView = new CommunicationConsole(this,connection->imgReceiver,connection->telemetryReceiver);
    consoleView->setWindowTitle("Communicaton Console");
    consoleView->show();*/
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
{/*
    paramPlot = new ParameterTemporalSeries(this,connection->telemetryReceiver,connection->odometryReceiver);
    paramPlot->setWindowTitle("Parameter Temporal Series");

    QDialog* secondWindow = new QDialog(paramPlot);
    secondWindow->show();
    secondWindow->raise();
    secondWindow->activateWindow();*/
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    //connection->odometryReceiver->shutdown();
    //connection->telemetryReceiver->shutdown();
    //writeSettings();
    QMainWindow::closeEvent(event);
}

// User commands in GUI//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Control Mode
void MainWindow::onControlModeChange(int key){
    std::cout<<key<<std::endl;
    if (connection->connectStatus){
        switch(key)
        {
        case(1):
            std::cout<<"Changing to Control Mode Position"<<std::endl;
            connection->usercommander->sendCommandInPositionControlMode(0.0, 0.0, 0.0);
            break;
        case(2):
            std::cout<<"Changing to Control Mode Altitude"<<std::endl;
            connection->usercommander->sendCommandInMovingManualAltitudMode(0.0,0.0,0.0,0.0);
            break;
        case(3):
            std::cout<<"Changing to Control Mode Speed"<<std::endl;
            connection->usercommander->sendCommandInSpeedControlMode(0.0, 0.0);
            break;
        }
    }
}



void MainWindow::onStartButton(){
    std::cout<<"Take Off pressed buttom"<<std::endl;
    if (connection->connectStatus)
        connection->usercommander->publish_takeoff();

}


void MainWindow::onLandButton(){
    std::cout<<"Land pressed buttom"<<std::endl;
    if (connection->connectStatus)
        connection->usercommander->publish_land();

}


void MainWindow::onHoverButton(){
    std::cout<<"Hover pressed buttom"<<std::endl;
    if (connection->connectStatus)
        connection->usercommander->publish_hover();
}


// User commands in Keyboard///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::keyPressEvent(QKeyEvent *e){
    std::stringstream key;
    if (connection->connectStatus){
        switch(e->key())
        {
        case Qt::Key_8:
            std::cout<<"Right pressed buttom"<<std::endl;
            if(  connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, CTE_COMMAND_ROLL, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(0.0, CONTROLLER_STEP_COMMAND_POSITTION, 0.0);
            break;

        case Qt::Key_4:
            std::cout<<"Left pressed buttom"<<std::endl;
            if(  connection->usercommander->getDroneManagerStatus().status == droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, -CTE_COMMAND_ROLL, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(0.0, -CONTROLLER_STEP_COMMAND_POSITTION, 0.0);
            break;

        case Qt::Key_2:
            std::cout<<"Down pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(-CTE_COMMAND_PITCH, 0.0, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(-CONTROLLER_STEP_COMMAND_POSITTION, 0.0, 0.0);
            break;

        case Qt::Key_6:
            std::cout<<"Up pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(CTE_COMMAND_PITCH, 0.0, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(CONTROLLER_STEP_COMMAND_POSITTION, 0.0, 0.0);
            break;

        case Qt::Key_J:
            std::cout<<"Up x speed  pressed buttom"<<std::endl;
            connection->usercommander->sendCommandInSpeedControlMode(CONTROLLER_CTE_COMMAND_SPEED, 0.0);
            break;

        case Qt::Key_N:
            std::cout<<"Down x speed  pressed buttom"<<std::endl;
            connection->usercommander->sendCommandInSpeedControlMode(-CONTROLLER_CTE_COMMAND_SPEED, 0.0);
            break;

        case Qt::Key_B:
            std::cout<<"Up y speed  pressed buttom"<<std::endl;
            connection->usercommander->sendCommandInSpeedControlMode(0.0, -CONTROLLER_CTE_COMMAND_SPEED);
            break;

        case Qt::Key_M:
            std::cout<<"Up y speed  pressed buttom"<<std::endl;
            connection->usercommander->sendCommandInSpeedControlMode(0.0, CONTROLLER_CTE_COMMAND_SPEED);
            break;


        case Qt::Key_Q:
            std::cout<<"Height + pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, 0.0, CTE_COMMAND_HEIGHT, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(0.0, 0.0, CONTROLLER_STEP_COMMAND_ALTITUDE);
            break;


        case Qt::Key_A:
            std::cout<<"Height -  pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, 0.0, -CTE_COMMAND_HEIGHT, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(0.0, 0.0, -CONTROLLER_STEP_COMMAND_ALTITUDE);
            break;

        case Qt::Key_Z:
            std::cout<<"Yaw counter-clockwise pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, 0.0, 0.0, -CTE_COMMAND_YAW);
            else
                connection->usercommander->sendYawCommandInPositionControlMode(-CONTROLLER_STEP_COMMAND_YAW);
            break;


        case Qt::Key_X:
            std::cout<<"Yaw clockwise pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, 0.0, 0.0, CTE_COMMAND_YAW);
            else
                connection->usercommander->sendYawCommandInPositionControlMode(CONTROLLER_STEP_COMMAND_YAW);
            break;

        }
    }
}


void MainWindow::close()
{
    this->~MainWindow();
}


MainWindow::~MainWindow()
{
    delete ui;

}




