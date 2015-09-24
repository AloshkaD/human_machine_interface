/*!*******************************************************************************************
 *  \file       parameter_temporal_series.h
 *  \brief      ParameterTemporalSeries definition file.
 *  \details    This file includes the ParameterTemporalSeries class declaration. To obtain more
 *              information about it's definition consult the parameter_temporal_series.cpp file.
 *  \author     Yolanda de la Hoz Simon
 *  \copyright  Copyright 2015 UPM. All right reserved. Released under license BSD-3.
 ********************************************************************************************/
#ifndef PARAMETERTEMPORALSERIES_H
#define PARAMETERTEMPORALSERIES_H

#include <QDockWidget>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include <QTreeWidget>
#include <QString>
#include "data_plot.h"
#include "telemetry_state_receiver.h"
#include "odometry_state_receiver.h"

namespace Ui {
class parameterTemporalSeries;
}

class ParameterTemporalSeries : public QWidget
{
    Q_OBJECT

    void initTree(QMap<QString, QStringList> topic_list, QTreeWidget *tree);
    void initParameterList(QStringList list, QTreeWidget *tree);
    void addRootTree(QString name, QStringList list, QTreeWidget *tree);
    void addChildTree(QTreeWidgetItem *parent, QStringList list, QString description);
    void setSignalHandlers();

public:
    explicit ParameterTemporalSeries(QWidget *parent = 0, TelemetryStateReceiver *telemetryReceiver=0,OdometryStateReceiver* odometryReceiver=0);
    void resizeEvent(QResizeEvent * event);
    ~ParameterTemporalSeries();

    QStringList telemetry;
    QStringList ekf;
    QStringList controller;
    QStringList arucoSlam;
    DataPlot *plot;

public Q_SLOTS:
    void onTextFilterChange(const QString &arg1);
    void onShowUnits(bool click);
    void onStopButton();
    void updateParametersValue();

private:
    Ui::parameterTemporalSeries *ui;
    QStringList paramsTelemetry;
    TelemetryStateReceiver* telem_receiver;
    OdometryStateReceiver* odometry;
    QMap<QString,QStringList> parameters;
};

#endif // PARAMETERTEMPORALSERIES_H
