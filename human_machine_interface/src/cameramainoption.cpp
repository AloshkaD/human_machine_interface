#include "../include/human_machine_interface/cameramainoption.h"
#include "../../human_machine_interface-build/ui_cameramainoption.h"
#include <QDebug>

cameramainoption::cameramainoption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cameramainoption)
{
    ui->setupUi(this);
    currentCamera=0; // Widget clicked.
    mainCamera=1; // Main widget as main camera image.

    connect(ui->imageCamera1, SIGNAL(clicked()), this, SLOT(changeCamera1()));
    connect(ui->imageCamera2, SIGNAL(clicked()), this, SLOT(changeCamera2()));
    connect(ui->imageCamera3, SIGNAL(clicked()), this, SLOT(changeCamera3()));
    connect(ui->imageCamera4, SIGNAL(clicked()), this, SLOT(changeCamera4()));
    connect(ui->imageCamera5, SIGNAL(clicked()), this, SLOT(changeCamera5()));
    connect(ui->imageCamera6, SIGNAL(clicked()), this, SLOT(changeCamera6()));

}

void cameramainoption::swapWidgets(QPushButton* imageToSwap, QString titleToSwap){

    QString mainTitle;
    int row, col, col_span, row_span;
    int index = ui->gridLayout->indexOf(imageToSwap); //position of the imageCamera2

    if(index != -1)
    {
        ui->gridLayout->getItemPosition(index, &row, &col, &col_span, &row_span);
        qDebug() << "Clicked Item is at:" << row << col
                 << "spanning" << row_span << col_span;
    }
    switch(mainCamera)
    {
     case 1:{
     mainTitle="Camera 1"; // main image title
     ui->gridLayout->addWidget(ui->imageCamera1,row,col,row_span,col_span); // Swap main widget in the widget position clicked.
     break;
     }
     case 2:{
     mainTitle="Camera 2"; // main image title
     ui->gridLayout->addWidget(ui->imageCamera2,row,col,row_span,col_span);
     break;
     }
     case 3:{
     mainTitle="Camera 3"; // main image title
     ui->gridLayout->addWidget(ui->imageCamera3,row,col,row_span,col_span);
     break;
     }
     case 4:{
     mainTitle="Camera 4"; // main image title
     ui->gridLayout->addWidget(ui->imageCamera4,row,col,row_span,col_span);
     break;
     }
     case 5:{
     mainTitle="Camera 5"; // main image title
     ui->gridLayout->addWidget(ui->imageCamera5,row,col,row_span,col_span);
     break;
     }
     case 6:{
     mainTitle="Camera 6"; // main image title
     ui->gridLayout->addWidget(ui->imageCamera6,row,col,row_span,col_span);
     break;
     }

    }

    ui->gridLayout->addWidget(imageToSwap,1,0,3,2); // add the button to the main grid
    ui->title_1->setText(titleToSwap);// add title to the main grid

    if(row==1 && col==0)
    ui->title_1->setText(mainTitle); // add the title to the position grid
    if(row==1 && col==2)
    ui->title_2->setText(mainTitle);
    if(row==3 && col==2)
    ui->title_3->setText(mainTitle);
    if(row==5 && col==2)
    ui->title_4->setText(mainTitle);
    if(row==5 && col==1)
    ui->title_5->setText(mainTitle);
    if(row==5 && col==0)
    ui->title_6->setText(mainTitle);

}

void cameramainoption::changeCamera1(){
    QString titleToSwap = "Camera 1";
    this->swapWidgets(ui->imageCamera1,titleToSwap);
    mainCamera=1; // Update this camera as the main camera.
}

void cameramainoption::changeCamera2(){
     QString titleToSwap = "Camera 2";
     this->swapWidgets(ui->imageCamera2,titleToSwap);
     mainCamera=2;
}

void cameramainoption::changeCamera3(){
    QString titleToSwap = "Camera 3";
    this->swapWidgets(ui->imageCamera3,titleToSwap);
    mainCamera=3;
}

void cameramainoption::changeCamera4(){
    QString titleToSwap = "Camera 4";
    this->swapWidgets(ui->imageCamera4,titleToSwap);
    mainCamera=4;
}
void cameramainoption::changeCamera5(){
    QString titleToSwap = "Camera 5";
    this->swapWidgets(ui->imageCamera5,titleToSwap);
    mainCamera=5;
}
void cameramainoption::changeCamera6(){
    QString titleToSwap = "Camera 6";
    this->swapWidgets(ui->imageCamera6,titleToSwap);
    mainCamera=6;
}


cameramainoption::~cameramainoption()
{
    delete ui;
}
