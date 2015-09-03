/*
  Camera view - show the camera views displayed in a grid
  @author  Yolanda de la Hoz Simón
  @date    06-2015
  @version 1.0
*/

/*****************************************************************************
** Includes
*****************************************************************************/
#include "../include/camera_grid_option.h"
#include "../../../../human_machine_interface-build/ui_cameragridoption.h"
/*****************************************************************************
** Implementation
*****************************************************************************/

CameraGridOption::CameraGridOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraGridOption)
{
    ui->setupUi(this);
}

CameraGridOption::~CameraGridOption()
{
    delete ui;
}
