#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt4/QtOpenGL/QGLWidget>
#include <qt4/QtGui/QMessageBox>
#include <qt4/QtGui/QMainWindow>
#include <qt4/QtCore/QTime>
#include <qt4/QtCore/QTimer>
#include "connection.h"
#include "communicationconsole.h"
#include "odometryStateReceiver.h"
#include "usercommander.h"
#include "parametertemporalseries.h"
#include "processmonitor.h"
#include "sphereview.h"
#include "cameradisplayoption.h"
#include "cameraoneoption.h"
#include "fourcameraoption.h"
#include "sphereview.h"
#include "uavScene.h"
#include "string"


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
    uavScene *osg_uav;
    QTimer *timer;
    QTime *current_time;
    int batteryCount;
    int batteryText;
    int timerSecond;
    int timerMinutes;
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



private Q_SLOTS:
   void show_frame();

public Q_SLOTS:
    void on_actionNew_connection_triggered();
    void on_actionParameter_Temporal_Series_triggered();
    void on_actionAbout_Ground_Control_System_triggered();
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
    void show_vehicle();
    void onStartButton();
    void onLandButton();
    void onResetCommandButton();
    void onHoverButton();
    void onEmergencyStopButton();
    void keyPressEvent(QKeyEvent *e); 
    void initializeCameraView();
    void closeEvent(QCloseEvent *event);
    void flightTime();
    void saveCurrentCameraView();



    void close();



Q_SIGNALS:
        void loggingUpdated();
        void rosShutdown();
        void parameterReceived();
        void updateStatus();
        void saveImage(const int);

protected:
    virtual void timerEvent(QTimerEvent *e);
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;
    Connection *connection;
    cameradisplayoption *mainoption;
    cameraoneoption *oneoption;
    fourCameraOption *fourCamera;
    processMonitor *processView;
    parameterTemporalSeries *paramPlot;
    CommunicationConsole *consoleView;
    int d_interval; // timer in ms
    int d_timerId;
};

#endif // MAINWINDOW_H
