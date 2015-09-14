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
    QPixmap pixmap1;
    QPixmap pixmap2;
    QPixmap pixmap3;
    QPixmap pixmap4;
    QString getCurrentCamera(int pos);
    void swapWidgets(QPushButton* imageToSwap, QString titleToSwap);
    void createPixmapsButton();
    int current_camera;
    int mainCamera;




public Q_SLOTS:
    void changeCameraPosition(int id_camera);
    void updateImage(const QPixmap* image, int id_camera);

    void saveCameraImages(const int camera_view_manager);




private:
    Ui::cameraDisplayOption *ui;
    ImagesReceiver* imageReceiver;

};

#endif // CAMERADISPLAYOPTION_H
