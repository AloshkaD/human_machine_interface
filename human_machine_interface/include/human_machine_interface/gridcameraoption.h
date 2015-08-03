#ifndef GRIDCAMERAOPTION_HPP
#define GRIDCAMERAOPTION_HPP

#include <QWidget>

namespace Ui {
class gridCameraOption;
}

class gridCameraOption : public QWidget
{
    Q_OBJECT

public:
    explicit gridCameraOption(QWidget *parent = 0);
    ~gridCameraOption();

private:
    Ui::gridCameraOption *ui;
};

#endif // GRIDCAMERAOPTION_HPP
