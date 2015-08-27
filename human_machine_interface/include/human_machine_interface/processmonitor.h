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
#include "supervisor.h"
#include "telemetryStateReceiver.h"

namespace Ui {
class processMonitor;
}

class processMonitor : public QWidget
{
    Q_OBJECT

    int row;
    bool initializedTable;

public:
    explicit processMonitor(QWidget *parent = 0, telemetryStateReceiver *collector=0);
    /*void updateTableInfo();
    void initTree(QMap<QString, QStringList> algorithmsList, QTreeWidget *tree);
    void initParameterList(QStringList list, QTreeWidget *tree);
    void addRootTree(QString name, QStringList list, QTreeWidget *tree);
    void addChildTree(QTreeWidgetItem *parent, QStringList list, QString description);*/
    void setSignalHandlers();

            droneMsgsROS::ProcessDescriptor node_container;

    ~processMonitor();



public Q_SLOTS:
    /*void onTextFilterChange(const QString &arg1);
    void filterTableInfo();
    void onCustomContextMenuRequested(const QPoint& pos);
    void showContextMenu(QTreeWidgetItem* item, const QPoint& globalPos);*/
    void onSupervisorStateReceived();
        void initProcessViewerTable();


private:
    Ui::processMonitor *ui;
    QMap<QString,QStringList> processList;
    QStringList listProcess;


    supervisor *supervisorNode;
    telemetryStateReceiver* node;
};

#endif // PROCESSMONITOR_H
