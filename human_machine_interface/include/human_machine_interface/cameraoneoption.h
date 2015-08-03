#ifndef CAMERAONEOPTION_HPP
#define CAMERAONEOPTION_HPP

#include <QWidget>

namespace Ui {
class cameraoneoption;
}

class cameraoneoption : public QWidget
{
    Q_OBJECT

public:
    explicit cameraoneoption(QWidget *parent = 0);
    ~cameraoneoption();

private:
    Ui::cameraoneoption *ui;
};

#endif // CAMERAONEOPTION_HPP
