#ifndef CAMERADISPLAYOPTION_H
#define CAMERADISPLAYOPTION_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "images_receiver.h"


namespace Ui {
class cameraDisplayOption;
}

class CameraDisplayOption : public QWidget
{
    Q_OBJECT

public:
    explicit CameraDisplayOption(QWidget *parent = 0,ImagesReceiver* imgReceiver=0);
    ~CameraDisplayOption();
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
        QPixmap pix;
    QString getCurrentCamera(int pos);
    void swapWidgets(QPushButton* imageToSwap, QString titleToSwap);
    void createPixmapsButton();
    int currentCamera;
    int mainCamera;




public Q_SLOTS:

    void changeCamera1();
    void changeCamera2();
    void changeCamera3();
    void changeCamera4();
    void changeCamera5();
    void changeCamera6();
    void updateImage1(const QPixmap* image);
    void updateImage2(const QPixmap* image);
    void updateImage3(const QPixmap* image);
    void updateImage4(const QPixmap* image);
    void updateImage5(const QPixmap* image);
    void updateImage6(const QPixmap* image);

    void saveCameraImages(const int camera_view_manager);




private:
    Ui::cameraDisplayOption *ui;
    ImagesReceiver* imageReceiver;

};

#endif // CAMERADISPLAYOPTION_H
