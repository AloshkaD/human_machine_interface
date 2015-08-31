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
    int current_image;
    ~cameraoneoption();


public Q_SLOTS:

    void updateImage1(const QPixmap* image);
    void updateImage2(const QPixmap* image);
    void updateImage3(const QPixmap* image);
    void updateImage4(const QPixmap* image);
    void updateImage5(const QPixmap* image);
    void updateImage6(const QPixmap* image);
    void changeRightImage();
    void changeLeftImage();
    void saveCameraImages(const int camera_view_manager);

private:
    Ui::cameraoneoption *ui;
    imagesReceiver* imageReceiver;
    QPixmap pix;
};

#endif // CAMERAONEOPTION_HPP
