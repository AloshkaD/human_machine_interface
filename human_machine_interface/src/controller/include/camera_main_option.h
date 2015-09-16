#ifndef CAMERAMAINOPTION_H
#define CAMERAMAINOPTION_H


#include <QWidget>
#include "images_receiver.h"

namespace Ui {
class cameraMainOption;
}

class CameraMainOption : public QWidget
{
    Q_OBJECT

public:
    explicit CameraMainOption(QWidget *parent = 0,ImagesReceiver* imgReceiver=0);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    int current_image;

    ~CameraMainOption();


public Q_SLOTS:


    void updateImage(const QPixmap* image,int id_camera);
    void changeCurrentCamera(int direction);
    void saveCameraImages(const int camera_view_manager);

private:
    Ui::cameraMainOption *ui;
    ImagesReceiver* image_receiver;
    QPixmap pix;
};

#endif // CAMERAONEOPTION_HPP
