#include "../include/fourcameraoption.h"
#include "../../../../human_machine_interface-build/ui_fourcameraoption.h"

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
