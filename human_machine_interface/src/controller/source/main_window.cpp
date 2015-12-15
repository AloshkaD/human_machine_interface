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
#include "ui_mainwindow.h"
#include "qt4/QtGui/qwidget.h"
#include "qt4/QtGui/qevent.h"
#include <qt4/Qt/qpointer.h>
#include <qt4/Qt/qcombobox.h>
#include <qt4/Qt/qlabel.h>
#include <qt4/Qt/qfiledialog.h>
#include <qt4/Qt/qpixmap.h>
#include <qt4/Qt/qsize.h>
#include <qt4/Qt/qapplication.h>
#include <qt4/Qt/qdesktopwidget.h>
#include <qt4/Qt/qwidgetaction.h>
#include <qt4/Qt/qmenu.h>
#include <qt4/Qt/qlist.h>
#include <qt4/Qt/qstring.h>
#include <qt4/QtCore/QObject>


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


/*!********************************************************************************************************************
 *  \class      MainWindow
 *  \brief      This is the class that sets the grid for main window.
 *  \details    In this class, main elements of the main window are set and initialized.
 *
 *********************************************************************************************************************/


MainWindow::MainWindow(int argc, char** argv,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //initialize ui member
{
    ui->setupUi(this);// connects all ui's triggers

    std::cout << "laura " << std::endl;
    setWindowIcon(QIcon(":/images/images/drone-icon.png"));
    setWindowTitle(QString::fromUtf8("Human Machine Interface"));

    ignore_resize=0;
    resize=0;
    num_of_auto_ops=2;
    max_osg_frame=0;
    error_counter=0;// counter error for performance_monitor
    is_laptop_design=false;
    is_initial_controlmode=false;

    //ui->tab_manager->setCurrentIndex(0); // ensure the first tab is showing

    //Initialize views
    connection = new Connection(this,argc,argv);
    process_view = new PerformanceMonitorViewer(this,connection->graph_receiver,connection->usercommander);

    ui->grid_performance->addWidget(process_view,0,0);
    param_plot = new ParameterTemporalSeries(this,connection->telemetry_receiver,connection->odometry_receiver);
    ui->grid_parameters->addWidget(param_plot,0,0);
    osg_sphere= new SphereView(ui->sphere_scene->buddy(),connection->telemetry_receiver);
    osg_sphere->resize(320, 350);    // Resize the QOSGWidget to the size of frames to render
    osg_uav= new VehicleView(ui->vehicle_scene->buddy(),connection->telemetry_receiver);
    osg_uav->resize(320, 350);
    controlpanel = new ControlPanel(this, connection);
    ui->grid_controlpanel->addWidget(controlpanel,0,0);
    behaviourviewer = new BehaviourViewer(this, connection->graph_receiver, connection->usercommander);
    ui->grid_behavior->addWidget(behaviourviewer,0,0);

    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    ui->grid_camera->addWidget(widget,0,0);
    initializeCameraView();

    timer = new QTimer(this); // Shows new frames rate -> 1 ms.
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView())); // OSG frames
    timer->start(1);

    setSignalHandlers(); // triggers

    is_laptop_design=setLaptopDesign();

    old_height=this->height();
    is_init_takeoff_context_menu=false;
}


/*!********************************************************************************************************************
 *  \brief      This method is where the main window takes the name of the running process.
 *********************************************************************************************************************/

char* MainWindow::getProcessName(const char* process_name_temp)//TODO::Comprobar si existe namespace.
{
    char output[10012];
    strncpy(output, process_name_temp, sizeof(output));
    output[sizeof(output) - 1] = 0;
    char* process_name = strtok(output, "/");
    process_name = strtok(NULL, "/");
    return process_name;
}


/*!********************************************************************************************************************
 *  \brief      This method detects whether the HMI is running on a laptop or in a computer.
 *********************************************************************************************************************/
bool MainWindow::setLaptopDesign()
{
    // UI design laptop
    QDesktopWidget desktop;
    int desktop_height=desktop.geometry().height();
    int desktop_width=desktop.geometry().width();
    qDebug() << desktop_height;
    qDebug() << desktop_width;

    if(desktop_height<=1024)
    {
        osg_uav->resize(320, 300);
        osg_sphere->resize(320, 250);
        ui->tab_dynamic_view->setMaximumSize(QSize(350, 280));
        delete ui->panel_vehicle; // destroy the default panels
        delete ui->panel_sphere;
        return true;
    }
    return false;
}


/*!********************************************************************************************************************
 *  \brief      This method is in charge for the resizig of the event dynamic panel.
 *********************************************************************************************************************/
void MainWindow::resizeEventDynamicView(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    if((ignore_resize % num_of_auto_ops) == 0&&old_height!=this->height()){
        if(ui->sphere_scene->size().height()>=ui->vehicle_scene->size().height()){
            osg_uav->resize(ui->sphere_scene->size());
            osg_sphere->resize(ui->sphere_scene->size());
        }
        if(ui->sphere_scene->size().height()<=ui->vehicle_scene->size().height()){
            osg_sphere->resize(ui->vehicle_scene->size());
            osg_sphere->resize(320, (int)(ui->sphere_scene->size().height()-resize));
            osg_uav->resize(320,(int)(ui->sphere_scene->size().height()-resize));
            osg_uav->resize(ui->vehicle_scene->size());
        }
        ignore_resize = 0;
    }
    if(old_height>this->height())
        resize++;

    ignore_resize++;
    old_height=this->height();
}


/*!********************************************************************************************************************
 *  \brief      This method is in charge for the update of the event dynamic panel.
 *********************************************************************************************************************/
void MainWindow::updateDynamicView()
{
    // Get the frame and visualize with a pixmap in a QLabel.
    ui->sphere_scene->setPixmap(osg_sphere->renderPixmap(0,0,true));
    ui->vehicle_scene->setPixmap(osg_uav->renderPixmap(0,0,true));

}


/*!********************************************************************************************************************
 *  \brief      This method is in charge for the timer interval: initializes and maintains/updates.
 *********************************************************************************************************************/
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

/*!********************************************************************************************************************
 *  \brief      This method is where all the signals interruptions are handled.
 *********************************************************************************************************************/
void MainWindow::setSignalHandlers()
{
    connect(connection, SIGNAL(rosShutdown()), this, SLOT(close())); //Close the app.

    connect(param_plot->plot,SIGNAL(disconnectUpdateDynamicsView()),this, SLOT(disconnectDynamicsView()));
    connect(param_plot->plot,SIGNAL(connectUpdateDynamicsView()),this, SLOT(connectDynamicsView()));
    connect(connection->telemetry_receiver, SIGNAL(parameterReceived()), this, SLOT(updateDynamicsPanel( )));

    //connect(connection->telemetryReceiver, SIGNAL( parameterReceived( )), this, SLOT(show_frame()));

    //connect(ui->yaw_zero_button,SIGNAL(clicked()),this, SLOT(onYawZeroButton()));
    connect(ui->one_camera_button, SIGNAL(clicked()), this, SLOT(displayOneCamera()));
    connect(ui->main_camera_button, SIGNAL(clicked()), this, SLOT(displayMainGridCamera()));
    connect(ui->four_camera_button, SIGNAL(clicked()), this, SLOT(displayFourGridCamera()));
    connect(ui->save_image_button, SIGNAL(clicked()), this, SLOT(saveCurrentCameraView()));
   
    connect(connection->usercommander, SIGNAL( managerStatusReceived( )), this, SLOT( setInitialControlMode( )));
    //connect(ui->tabManager, SIGNAL(clicked()), this, SLOT(openTab()));

    disconnect(ui->main_camera_button, SIGNAL(clicked()), this, SLOT(displayMainGridCamera()));
    disconnect(ui->four_camera_button, SIGNAL(clicked()), this, SLOT(displayFourGridCamera()));

}

/*!********************************************************************************************************************
 *  \brief      This method is where the dynamics view panel disconnects.
 *********************************************************************************************************************/
void MainWindow::disconnectDynamicsView(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView()));
}

/*!********************************************************************************************************************
 *  \brief      This method is where the dynamics view panel connects.
 *
 *********************************************************************************************************************/
void MainWindow::connectDynamicsView(){
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView()));
}

/*!********************************************************************************************************************
 *  \brief      This method is where the camera view is saved.
 *********************************************************************************************************************/
void MainWindow::saveCurrentCameraView()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView()));
    Q_EMIT saveImage(camera_view_manager);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView()));
}

/*!********************************************************************************************************************
 *  \brief      This method is where the camera view is initialized.
 *********************************************************************************************************************/
void MainWindow::initializeCameraView()
{
    camera_view_manager=0;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    ui->grid_camera->addWidget(widget,0,0);
    one_option= new CameraMainOption(this,connection->img_receiver);
    ui->grid_camera->addWidget(one_option,0,0);

}

/*!********************************************************************************************************************
 *  \brief      This method is where one camera is displayed.
 *********************************************************************************************************************/
void MainWindow::displayOneCamera()
{
    camera_view_manager=0;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

    ui->grid_camera->addWidget(widget,0,0);
    if(!is_open_one_camera_view) one_option= new CameraMainOption(this,connection->img_receiver);
    ui->grid_camera->addWidget(one_option,0,0);
    is_open_one_camera_view=true;
}

/*!********************************************************************************************************************
 *  \brief      This method is where the main camera grid is displayed.
 *********************************************************************************************************************/
void MainWindow::displayMainGridCamera()
{
    camera_view_manager=1;
    QWidget* widget = new QWidget();
    widget->setAutoFillBackground(false);
    widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    ui->grid_camera->addWidget(widget,0,0);
    if(!is_open_main_camera_view)
        mainoption= new CameraDisplayOption(this,connection->img_receiver);
    ui->grid_camera->addWidget(mainoption,0,0);
    is_open_main_camera_view=true;
}

/*!********************************************************************************************************************
 *  \brief      This method is where four cameras are displayed.
 *********************************************************************************************************************/
void MainWindow::displayFourGridCamera()
{
    if(!is_open_four_camera_view){
        camera_view_manager=3;
        QWidget* widget = new QWidget();
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        ui->grid_camera->addWidget(widget,0,0);
        fourCamera= new CameraGridOption(this,connection->img_receiver);
        ui->grid_camera->addWidget(fourCamera,0,0);
        is_open_four_camera_view=true;
    }
}

/*!********************************************************************************************************************
 *  \brief      This method is where the dynamics panel is updated.
 *
 *********************************************************************************************************************/

void MainWindow::updateDynamicsPanel()
{
    if(connection->connect_status&&!is_laptop_design){
        // sphere
        ui->value_sphere_x->setText(QString::number(((double)((int)(connection->odometry_receiver->drone_pose_msgs.x*100)))/100) + "  m");
        ui->value_sphere_y->setText(QString::number(((double)((int)(connection->odometry_receiver->drone_pose_msgs.y*100)))/100) + "  m");
        ui->value_sphere_z->setText(QString::number(((double)((int)(connection->odometry_receiver->drone_pose_msgs.z*100)))/100) + "  m");
        ui->value_sphere_yaw->setText(QString::number(((double)((int)(connection->telemetry_receiver->rotation_angles_msgs.vector.z*100)))/100) + "  deg");
        ui->value_sphere_roll->setText(QString::number(((double)((int)(connection->telemetry_receiver->rotation_angles_msgs.vector.x*100)))/100) + "  deg");
        ui->value_sphere_pitch->setText(QString::number(((double)((int)(connection->telemetry_receiver->rotation_angles_msgs.vector.y*100)))/100) + "  deg");
        // vehicle
        ui->value_vehicle_x->setText(QString::number(((double)((int)(connection->odometry_receiver->drone_pose_msgs.x*100)))/100) + "  m");
        ui->value_vehicle_y->setText(QString::number(((double)((int)(connection->odometry_receiver->drone_pose_msgs.y*100)))/100) + "  m");
        ui->value_vehicle_z->setText(QString::number(((double)((int)(connection->odometry_receiver->drone_pose_msgs.z*100)))/100) + "  m");
        ui->value_vehicle_yaw->setText(QString::number(((double)((int)(connection->telemetry_receiver->rotation_angles_msgs.vector.z*100)))/100) + "  deg");
        ui->value_vehicle_pitch->setText(QString::number(((double)((int)(connection->telemetry_receiver->rotation_angles_msgs.vector.x*100)))/100) + "  deg");
        ui->value_vehicle_roll->setText(QString::number(((double)((int)(connection->telemetry_receiver->rotation_angles_msgs.vector.y*100)))/100) + "  deg");
    }
}






// Pop-up windows///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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
    QMessageBox::about(this, tr("Manual Control Guided ..."),tr("<h2>Human Machine Interface</h2><p>Keyboard Bindings List</p><p>TAKE_OFF = t</p><p>LAND = y</p><p>EMERGENCY_STOP = space</p><p>HOVER = h</p><p>MOVE = m</p><p>RESET_COMMANDS= s</p><p>MOVE_UPWARDS = q</p><p>MOVE_DOWNWARDS = a</p><p>TURN_COUNTER_CLOCKWISE = z</p><p>TURN_CLOCKWISE = x</p><p>SET_YAW_REFERENCE_TO_0 = backslash</p><p>MOVE_FORWARD = up </p><p>MOVE_BACK = down</p><p>MOVE_RIGHT = right</p><p>MOVE_LEFT = left</p><p>UP_SPEED X = J</p><p>DOWN_SPEED X = N</p><p>DOWN_SPEED Y = B</p><p>UP_SPEED Y = M</p>"));
}


void MainWindow::on_actionCommunication_Console_triggered()
{
    /*consoleView = new CommunicationConsole(this,connection->imgReceiver,connection->telemetryReceiver);
    consoleView->setWindowTitle("Communicaton Console");
    consoleView->show();*/
}


void MainWindow::on_actionOpen_perception_configuration_triggered()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView()));
    file_name = QFileDialog::getOpenFileName(this,tr("Open File"), "/home", tr("All files (*.*)"));
    QMessageBox::information(this,tr("File Name"),file_name);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDynamicView()));
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


// User commands in Keyboard///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*!********************************************************************************************************************
 *  \brief      This method is the responsible for handling all the interruption signals.
 *  \details    The signals handled are the user keyboard commands.
 *********************************************************************************************************************/

void MainWindow::keyPressEvent(QKeyEvent *e){
    std::stringstream key;
    if(connection->mission_planner_receiver->is_autonomous_mode_active)
        connection->mission_planner_receiver->deactivateAutonomousMode();

    if (connection->connect_status){
        switch(e->key())
        {
        case Qt::Key_T:
            std::cout<<"Take off pressed buttom"<<std::endl;
            //onTakeOffButton();
            break;

        case Qt::Key_Y:
            std::cout<<"Land pressed buttom"<<std::endl;
            //onLandButton();
            break;

        case Qt::Key_H:
            std::cout<<"Hover pressed buttom"<<std::endl;
            //onHoverButton();
            break;

        case Qt::Key_Right:
            std::cout<<"Right pressed buttom"<<std::endl;
            if(  connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, CTE_COMMAND_ROLL, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(0.0, CONTROLLER_STEP_COMMAND_POSITTION, 0.0);
            break;

        case Qt::Key_Left:
            std::cout<<"Left pressed buttom"<<std::endl;
            if(  connection->usercommander->getDroneManagerStatus().status == droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(0.0, -CTE_COMMAND_ROLL, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(0.0, -CONTROLLER_STEP_COMMAND_POSITTION, 0.0);
            break;

        case Qt::Key_Down:
            std::cout<<"Down pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(-CTE_COMMAND_PITCH, 0.0, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(-CONTROLLER_STEP_COMMAND_POSITTION, 0.0, 0.0);
            break;

        case Qt::Key_Up:
            std::cout<<"Up pressed buttom"<<std::endl;
            if(connection->usercommander->getDroneManagerStatus().status ==  droneMsgsROS::droneManagerStatus::MOVING_MANUAL_ALTITUD)
                connection->usercommander->sendCommandInMovingManualAltitudMode(CTE_COMMAND_PITCH, 0.0, 0.0, 0.0);
            else
                connection->usercommander->sendCommandInPositionControlMode(CONTROLLER_STEP_COMMAND_POSITTION, 0.0, 0.0);
            break;

        case Qt::Key_1:
            std::cout<<"1 looping  pressed buttom"<<std::endl;
            connection->usercommander->sendCommandForLooping();
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
            std::cout<<"Down y speed  pressed buttom"<<std::endl;
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

        case Qt::Key_Space:
            std::cout<<"Space pressed buttom"<<std::endl;
            //onEmergencyStopButton();
        }
    }
}


// Processes instances management///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::close()
{
    this->~MainWindow();
}


/*!********************************************************************************************************************
 *  \brief      This method is the destructor of the main window.
 *********************************************************************************************************************/
MainWindow::~MainWindow()
{
    connection->WriteSettings();
    connection->shutdownThread();
    //QMainWindow::closeEvent(event);
    //this->~MainWindow();
    delete ui;
}

/*!********************************************************************************************************************
 *  \brief      This method ensures there is only one running instance of the main window.
 *********************************************************************************************************************/
bool MainWindow::uniqueApplication()
{
    pid_t mypid = getpid();

    FILE *fp;

    /* Open the command for reading. */
    char command [256];
    char output[1024];
    sprintf(command, "/bin/ps -p %d l", mypid);
    fp = popen(command, "r");
    if (fp == NULL) {
        perror(" popen: ");
        return false;
    }

    /* Read the output a line at a time - output it. */
    fgets(output, sizeof(output)-1, fp);
    if (fgets(output, sizeof(output)-1, fp) == NULL) {
        perror("Fgets. It may failed to get a second line: ");
        return false;
    }


    char* chars_array = strtok(output, " \t");
    std::string output_ps[32];
    int iterador = 0;

    while( chars_array != NULL )
    {
        output_ps[iterador++] = std::string(chars_array);
        chars_array = strtok(NULL, " ");
    }

    strncpy(output, output_ps[12].c_str(), sizeof(output));
    output[sizeof(output) - 1] = 0; // For safety

    char* chars_array_name = strtok(output, "/");
    std::string output_process_name[32];
    int iterador_name = 0;

    while( chars_array_name != NULL )
    {
        output_process_name[iterador_name++] = std::string(chars_array_name);
        chars_array_name = strtok(NULL, "/");
    }

    const char * process_name = output_process_name[iterador_name-1].c_str();


    sprintf(command, "/bin/pidof %s", process_name);

    // Check instances that share the process name
    fp = popen(command, "r");
    if (fp == NULL) {
        perror(" popen: ");
        return false;
    }


    // Read the output a line at a time - output it.
    if (fgets(output, sizeof(output)/sizeof(char), fp) == NULL) {
        perror("Fgets 2" );
        return false;
    }

    // close
    pclose(fp);

    chars_array = strtok(output, " \t");
    std::string process_pids[10];
    char process_pids_output[512];
    sprintf(process_pids_output," ");
    int instances = 0;

    while( chars_array != NULL and instances < sizeof(process_pids)/sizeof(std::string) )
    {
        process_pids[instances++] = chars_array;
        sprintf(process_pids_output, "%s %s", process_pids_output, chars_array);
        chars_array = strtok(NULL, " ");
    }


    if (instances > 1)
    {
        // Temporaly redirect to cout but it has to be launched in cerr!!! Until fix the opengl bug
        std::cerr << "It is NOT ALLOWED to use more than one instance." << std::endl;
        std::cerr << "The main instance PID is: " << process_pids[instances-1];
        std::cerr << "Ending this instance with PID: " << mypid << std::endl;
        return false;
    }
    else
    {
        //Redirect the standard error temporally
        freopen( "standard_error.txt", "w", stderr );
        //freopen( "standard_output.txt", "w", stdout );
        return true;
    }
}
