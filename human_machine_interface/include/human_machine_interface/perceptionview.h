#ifndef PERCEPTIONVIEW_H
#define PERCEPTIONVIEW_H

#include <QDockWidget>
#include "odometryStateReceiver.h"
namespace Ui {
class perceptionView;
}
namespace rviz
{
class Display;
class RenderPanel;
class VisualizationManager;
class ViewManager;
class VisualizationFrame;
}
class PerceptionView : public QDockWidget
{
    Q_OBJECT

public:
    explicit PerceptionView(QWidget *parent = 0, QString* file_name =0);
    ~PerceptionView();

private:
    Ui::perceptionView *ui;
    rviz::VisualizationManager* manager_;
    rviz::ViewManager* view_man;
    rviz::RenderPanel* render_panel_;
    rviz::VisualizationFrame* frame_;
    rviz::Display* grid_;
};

#endif // PERCEPTIONVIEW_H
