#ifndef CAMERAGRIDOPTION_H
#define CAMERAGRIDOPTION_H

#include <QWidget>

namespace Ui {
class CameraGridOption;
}

class CameraGridOption : public QWidget
{
    Q_OBJECT

public:
    explicit CameraGridOption(QWidget *parent = 0);
    ~CameraGridOption();

private:
    Ui::CameraGridOption *ui;
};

#endif 
