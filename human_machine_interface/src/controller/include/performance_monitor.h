#ifndef PROCESSMONITOR_H
#define PERFORMANCEMONITOR_H

#include <QWidget>
#include <QDockWidget>

#include <QTableWidgetItem>
#include <QString>
#include <QTime>
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ProcessDescriptor.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
#include "ros_graph_receiver.h"
#include "user_commander.h"

namespace Ui {
class PerformanceMonitor;
}

class PerformanceMonitor : public QWidget
{
    Q_OBJECT

    int row;
    int error_counter;
    bool initialized_table;
    bool is_display_stopped;

public:
    explicit PerformanceMonitor(QWidget *parent = 0, RosGraphReceiver *collector=0,UserCommander *usercommander=0);
    /*void updateTableInfo();
    void initTree(QMap<QString, QStringList> algorithmsList, QTreeWidget *tree);
    void initParameterList(QStringList list, QTreeWidget *tree);
    void addRootTree(QString name, QStringList list, QTreeWidget *tree);
    void addChildTree(QTreeWidgetItem *parent, QStringList list, QString description);*/
    void setSignalHandlers();
    char* getProcessName(const char* process_name);
    void updateProcessState(droneMsgsROS::ProcessDescriptor node_container, int rowProcessViewer);
    void onStartModuleClicked();
    void onStopModuleClicked();
    droneMsgsROS::ProcessDescriptor node_container;
    enum processMonitorStates {
        Start,
        Stop,
        Reset
    };

    ~PerformanceMonitor();



public Q_SLOTS:
    /*
    void filterTableInfo();
    */
    void onSupervisorStateReceived();
    void updateProcessViewerTable();
    void onTextFilterChange(const QString &arg1);
    void onCustomContextMenuRequested(const QPoint &pos);
    void showContextMenu(QTableWidgetItem *item, const QPoint& globalPos);
    void onStopClicked();
    void menuSelection(QAction* action);


private:
    Ui::PerformanceMonitor *ui;
    QMap<QString,QStringList> processList;
    QStringList listProcess;
    UserCommander* user_command;
    RosGraphReceiver* supervisor_receiver;
};

#endif // PROCESSMONITOR_H

