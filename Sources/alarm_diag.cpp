/**
  alarm_diag.cpp
  Purpose: Sets time in alarms
*/

#include "Headers/alarm_diag.h"
#include "ui_alarm_diag.h"

Alarm_diag::Alarm_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alarm_diag)
{
    ui->setupUi(this);
    //connects signals to slots
    connect(ui->Add_btn, SIGNAL(clicked()), SLOT(accept()));
}

Alarm_diag::~Alarm_diag()
{
    delete ui;
}

//receives inputed hours
int Alarm_diag::getHours()
{
    int h = ui->spinBox_h->value();
    return h;
}

//receives inputed minutes
int Alarm_diag::getMin()
{
    int m = ui->spinBox_m->value();
    return m;
}

//receives inputed seconds
int Alarm_diag::getSec()
{
    int s = ui->spinBox_s->value();
    return s;
}

//returns inputed time
QTime Alarm_diag::alrm()
{
    QTime t(getHours(), getMin(), getSec());
    return t;
}

//receives inputed music
QString Alarm_diag::Add_music()
{
    if(ui->radioButton->isChecked())
    {
    qDebug() << "music 1 was chosen";
    return "music/electronic.wav";
    }
    else if(ui->radioButton_2->isChecked())
    {
    qDebug() << "music 2 was chosen";
    return "music/startrek.wav";
    }
    else if(ui->radioButton_3->isChecked())
    {
    qDebug() << "music 3 was chosen";
    return "music/emergency.wav";
    }
    else if(ui->radioButton_4->isChecked())
    {
    qDebug() << "music 4 was chosen";
    return "music/strange_laugh.wav";
    }
    else
    {
    qDebug() << "music 5 was chosen";
    return "music/submarine_alarm.wav";
    }
}




