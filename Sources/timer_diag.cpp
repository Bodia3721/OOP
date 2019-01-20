/**
  timer_diag.cpp
  Purpose: Sets time in timers
*/

#include "Headers/timer_diag.h"
#include "ui_timer_diag.h"

Timer_diag::Timer_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer_diag)
{
    ui->setupUi(this);
    //connects signals to slots
    connect(ui->Add_btn, SIGNAL(clicked()), SLOT(accept()));
}

Timer_diag::~Timer_diag()
{
    delete ui;
}

//receives inputed hours
int Timer_diag::getHours()
{
    int h = ui->spinBox_h->value();
    return h;
}

//receives inputed minutes
int Timer_diag::getMin()
{
    int m = ui->spinBox_m->value();
    return m;
}

//receives inputed seconds
int Timer_diag::getSec()
{
    int s = ui->spinBox_s->value();
    return s;
}


