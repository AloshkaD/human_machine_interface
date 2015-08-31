#ifndef CAMERADISPLAYOPTION_H
#define CAMERADISPLAYOPTION_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "imagesreceiver.h"


namespace Ui {
class cameradisplayoption;
}

class cameradisplayoption : public QWidget
{
    Q_OBJECT

public:
    explicit cameradisplayoption(QWidget *parent = 0,imagesReceiver* imgReceiver=0);
    ~cameradisplayoption();
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
    Ui::cameradisplayoption *ui;
    imagesReceiver* imageReceiver;

};

#endif // CAMERADISPLAYOPTION_H
