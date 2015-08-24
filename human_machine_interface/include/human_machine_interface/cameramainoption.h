#ifndef CAMERAMAINOPTION_H
#define CAMERAMAINOPTION_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include "imagesreceiver.h"


namespace Ui {
class cameramainoption;
}

class cameramainoption : public QWidget
{
    Q_OBJECT

public:
    explicit cameramainoption(QWidget *parent = 0,imagesReceiver* imgReceiver=0);
    ~cameramainoption();
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
    void receiveImages();




private:
    Ui::cameramainoption *ui;
    imagesReceiver* imageReceiver;
};

#endif // CAMERAMAINOPTION_H
