#include "../include/camera_grid_option.h"
#include "../../../../human_machine_interface-build/ui_cameragridoption.h"

fourCameraOption::fourCameraOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fourCameraButton)
{
    ui->setupUi(this);
}

fourCameraOption::~fourCameraOption()
{
    delete ui;
}
