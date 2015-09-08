#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt4/QtOpenGL/QGLWidget>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtCore/QTime>
#include <qt4/QtCore/QTimer>
#include "connection.h"
#include "communication_console.h"
#include "odometry_state_receiver.h"
#include "user_commander.h"
#include "parameter_temporal_series.h"
#include "performance_monitor.h"
#include "sphere_view.h"
#include "camera_display_option.h"
#include "camera_main_option.h"
#include "camera_grid_option.h"
#include "sphere_view.h"
#include "vehicle_view.h"
#include "string"
#include "droneMsgsROS/droneManagerStatus.h"
#include "droneMsgsROS/droneStatus.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int argc, char** argv,QWidget *parent = 0);
    ~MainWindow();

    SphereView *osg_sphere;
    VehicleView *osg_uav;
    QTimer *timer;
    QTime *current_time;
    int errorCounter;


    QString file_name;
    int ignore_resize;
    int max_osg_frame;
    int num_of_auto_ops;
    int old_height;
    int resize;
    int camera_view_manager;
    bool isOpen_mainCameraView;
    bool isOpen_oneCameraView;
    bool isOpen_fourCameraView;
    bool designLaptop;
    QTimer *flightTimer;

private Q_SLOTS:
   void show_frame();

public Q_SLOTS:
    void on_actionNew_connection_triggered();
    void on_actionParameter_Temporal_Series_triggered();
    void on_actionAbout_Human_Machine_Interface_triggered();
    void on_actionContents_triggered();
    void on_actionCommunication_Console_triggered();
    void on_actionUser_Commands_Manual_triggered();
    void showNoMasterMessage();
    void showConnectionEstablished();
    void setSignalHandlers();
    void updateStatusBar();
    void testConnection();
    void displayOneCamera();
    void displayMainGridCamera();
    void displayFourGridCamera();
    void setTimerInterval(double ms);
    void on_actionOpen_perception_configuration_triggered();
    void onStartButton();
    void onYawZeroButton();
    void onLandButton();
    void onResetCommandButton();
    void onHoverButton();
   // void onEmergencyStopButton();
   // void keyPressEvent(QKeyEvent *e);
    void initializeCameraView();
    void closeEvent(QCloseEvent *event);
    void flightTime();
    void incrementErrorsCounter();
    void saveCurrentCameraView();
    void onControlModeChange(int key);
    void keyPressEvent(QKeyEvent *e);



    void close();



Q_SIGNALS:
        void loggingUpdated();
        void rosShutdown();
        void parameterReceived();
        void updateStatus();
        void saveImage(const int);

protected:
    void resizeEventDynamicView(QResizeEvent* event);

private:
    Ui::MainWindow *ui;
    Connection *connection;
    CameraDisplayOption *mainoption;
    CameraMainOption *oneoption;
    CameraGridOption *fourCamera;
    PerformanceMonitor *processView;
    ParameterTemporalSeries *paramPlot;
    CommunicationConsole *consoleView;
    int d_interval; // timer in ms
    int d_timerId;
};

#endif // MAINWINDOW_H
