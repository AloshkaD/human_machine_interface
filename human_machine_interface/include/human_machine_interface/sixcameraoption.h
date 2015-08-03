#ifndef SIXCAMERAOPTION_H
#define SIXCAMERAOPTION_H

#include <QWidget>

namespace Ui {
class sixCameraOption;
}

class sixCameraOption : public QWidget
{
    Q_OBJECT

public:
    explicit sixCameraOption(QWidget *parent = 0);
    ~sixCameraOption();

private:
    Ui::sixCameraOption *ui;
};

#endif // SIXCAMERAOPTION_H
