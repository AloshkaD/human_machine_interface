#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <QWidget>
#include <QDockWidget>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QTreeWidget>
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
    int errorCounter;
    bool initializedTable;

public:
    explicit PerformanceMonitor(QWidget *parent = 0, RosGraphReceiver *collector=0);
    /*void updateTableInfo();
    void initTree(QMap<QString, QStringList> algorithmsList, QTreeWidget *tree);
    void initParameterList(QStringList list, QTreeWidget *tree);
    void addRootTree(QString name, QStringList list, QTreeWidget *tree);
    void addChildTree(QTreeWidgetItem *parent, QStringList list, QString description);*/
    void setSignalHandlers();

            droneMsgsROS::ProcessDescriptor node_container;

    ~PerformanceMonitor();



public Q_SLOTS:
    /*
    void filterTableInfo();
    */
    void onSupervisorStateReceived();
    void initProcessViewerTable();
    void onTextFilterChange(const QString &arg1);
    void onCustomContextMenuRequested(const QPoint& pos);
    void showContextMenu(QTreeWidgetItem* item, const QPoint& globalPos);


private:
    Ui::performanceMonitor *ui;
    QMap<QString,QStringList> processList;
    QStringList listProcess;


    RosGraphReceiver* node;
};

#endif // PROCESSMONITOR_H

