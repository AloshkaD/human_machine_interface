#ifndef CAMERAONEOPTION_HPP
#define CAMERAONEOPTION_HPP

#include <QWidget>
#include "imagesreceiver.h"


namespace Ui {
class cameraoneoption;
}

class cameraoneoption : public QWidget
{
    Q_OBJECT

public:
    explicit cameraoneoption(QWidget *parent = 0,imagesReceiver* imgReceiver=0);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    ~cameraoneoption();


public Q_SLOTS:

    void updateImage(const QPixmap* image);
private:
    Ui::cameraoneoption *ui;
    imagesReceiver* imageReceiver;
    QPixmap pix;
};

#endif // CAMERAONEOPTION_HPP
