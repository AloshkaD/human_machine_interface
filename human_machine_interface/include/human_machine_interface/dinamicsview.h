#ifndef DINAMICSVIEW_H
#define DINAMICSVIEW_H


#include <QWidget>
#include "odometryStateReceiver.h"
namespace Ui {
class  dinamicsView;
}
namespace rviz
{
class Display;
class RenderPanel;
class VisualizationManager;
class ViewManager;
class VisualizationFrame;
}
class dinamicsView : public QWidget
{
    Q_OBJECT


public:
    explicit  dinamicsView(QWidget *parent = 0);
    ~ dinamicsView();

private:
    Ui:: dinamicsView *ui;
    rviz::VisualizationManager* manager_;
    rviz::ViewManager* view_man;
    rviz::RenderPanel* render_panel_;
    rviz::VisualizationFrame* frame_;
    rviz::Display* grid_;
};

#endif // DINAMICSVIEW_H
