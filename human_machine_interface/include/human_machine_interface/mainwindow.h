#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qt4/QtOpenGL/QGLWidget"
#include "qt4/QtGui/QMessageBox"
#include "qt4/QtGui/QMainWindow"
#include "qt4/QtCore/QTime"
#include "qt4/QtCore/QTimer"
#include "connection.h"
#include "perceptionview.h"
#include "odometryStateReceiver.h"
#include "usercommander.h"
#include "parametertemporalseries.h"
#include "dinamicsview.h"
#include "processmonitor.h"
#include "sphereview.h"
#include "cameramainoption.h"
#include "cameraoneoption.h"
#include "fourcameraoption.h"
#include "gridcameraoption.h"
#include "sixcameraoption.h"
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



private Q_SLOTS:
   void show_frame();

public Q_SLOTS:
    void on_actionNew_connection_triggered();
    void on_action3D_Perception_View_triggered();
    void on_actionParameter_Temporal_Series_triggered();
    void on_actionAbout_Ground_Control_System_triggered();
    void on_actionContents_triggered();
    void on_actionUser_Commands_Manual_triggered();
    void showNoMasterMessage();
    void showConnectionEstablished();
    void setSignalHandlers();
    void updateStatusBar();
    void testConnection();
    void displayOneCamera();
    void displayMainGridCamera();
    void displayFourGridCamera();
    void displaySixGridCamera();
    void displayGridCamera();
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
  /*  void onControlModeChange();
    void onHoverButton();


    void onYawZeroButton();
    void onResetCommandButton();
  */

    void close();



Q_SIGNALS:
        void loggingUpdated();
        void rosShutdown();
        void parameterReceived();
        void updateStatus();

protected:
    virtual void timerEvent(QTimerEvent *e);
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;
    PerceptionView *percept;
    dinamicsView *dinamic;
    Connection *connection;
    cameramainoption *mainoption;
    cameraoneoption *oneoption;
    fourCameraOption *fourCamera;
    gridCameraOption *gridCamera;
    sixCameraOption *sixCamera;
    processMonitor *processView;
    parameterTemporalSeries *paramPlot;
    int d_interval; // timer in ms
    int d_timerId;
};

#endif // MAINWINDOW_H
