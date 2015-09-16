#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <QWidget>
#include <QDockWidget>

#include <QTableWidgetItem>
#include <QString>
#include <QTime>
#include "droneMsgsROS/ProcessError.h"
#include "droneMsgsROS/ProcessDescriptor.h"
#include "droneMsgsROS/ProcessDescriptorList.h"
#include "ros_graph_receiver.h"

namespace Ui {
class performanceMonitor;
}

class PerformanceMonitor : public QWidget
{
    Q_OBJECT

    int row;
    int error_counter;
    bool initialized_table;
    bool is_display_stopped;

public:
    explicit PerformanceMonitor(QWidget *parent = 0, RosGraphReceiver *collector=0);
    /*void updateTableInfo();
    void initTree(QMap<QString, QStringList> algorithmsList, QTreeWidget *tree);
    void initParameterList(QStringList list, QTreeWidget *tree);
    void addRootTree(QString name, QStringList list, QTreeWidget *tree);
    void addChildTree(QTreeWidgetItem *parent, QStringList list, QString description);*/
    void setSignalHandlers();
    char* getProcessName(const char* process_name);
    void updateProcessState(droneMsgsROS::ProcessDescriptor node_container, int rowProcessViewer);

            droneMsgsROS::ProcessDescriptor node_container;

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


private:
    Ui::performanceMonitor *ui;
    QMap<QString,QStringList> processList;
    QStringList listProcess;


    RosGraphReceiver* node;
};

#endif // PROCESSMONITOR_H

