/**
  alarm.cpp
  Purpose: Makes alarms work
*/

#include "Headers/alarm.h"
#include "ui_alarm.h"
#include <QtMultimedia/QSound>


Alarm::Alarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alarm)
{
    ui->setupUi(this);
    sound = new QString;
    //makes timer
    timer = new QTimer(this);
    timer->setInterval(1000);

    //connects signals to slots
    connect(timer, SIGNAL(timeout()), this, SLOT(Alrm()));
    connect(ui->remove_btn, SIGNAL(clicked()), this, SLOT(Remove()));

    //start timers
    timer->start();
}

Alarm::~Alarm()
{
    delete ui;
}

//sets received time
void Alarm::setTime(const QString& time)
{
    ui->time_label->setText(time);
}

//receives time
QString Alarm::getTime()
{
    return ui->time_label->text();
}

//gets music
QString Alarm::getMusic()
{
    return ui->label->text();
}

//sets music
void Alarm::setMusic(const QString& music)
{
    ui->label->hide();
    ui->label->setText(music);
}

//describes how alarm is working
void Alarm::Alrm()
{
    if(ui->time_label->text() == QTime::currentTime().toString())
    {
        //calls the warning dialog that the alarm went off
        QMessageBox msg;
        QSound::play(getMusic());
        msg.warning(this, tr("ALARM"), ui->time_label->text(), QMessageBox::Ok);
        msg.setStyleSheet("color: white");
        this->close();
    }
}

//removes alarm
void Alarm::Remove()
{
    timer->stop();
    this->close();
}


