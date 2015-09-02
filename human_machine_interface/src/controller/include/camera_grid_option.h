#ifndef CAMERAGRIDOPTION_H
#define CAMERAGRIDOPTION_H

#include <QWidget>

namespace Ui {
class fourCameraButton;
}

class fourCameraOption : public QWidget
{
    Q_OBJECT

public:
    explicit fourCameraOption(QWidget *parent = 0);
    ~fourCameraOption();

private:
    Ui::fourCameraButton *ui;
};

#endif // FOURCAMERABUTTON_HPP
