#ifndef CAMERAMAINOPTION_H
#define CAMERAMAINOPTION_H

#include <QWidget>
#include "images_receiver.h"


namespace Ui {
class cameraMainOption;
}

class CameraOneOption : public QWidget
{
    Q_OBJECT

public:
    explicit CameraOneOption(QWidget *parent = 0,ImagesReceiver* imgReceiver=0);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    int current_image;
    ~CameraOneOption();


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
    Ui::cameraMainOption *ui;
    ImagesReceiver* imageReceiver;
    QPixmap pix;
};

#endif // CAMERAONEOPTION_HPP