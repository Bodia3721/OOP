/**
  timer.cpp
  Purpose: Makes timers work
*/

#include "Headers/timer.h"
#include "ui_timer.h"


Timer::Timer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    //makes QTimer
    timer = new QTimer(this);
    timer->setInterval(1000);

    //connects signals to slots
    connect(timer, SIGNAL(timeout()), this, SLOT(Tmr()));
    connect(ui->start_btn, SIGNAL(clicked()), this, SLOT(Start()));
    connect(ui->stop_btn, SIGNAL(clicked()), this, SLOT(Stop()));
    connect(ui->remove_btn, SIGNAL(clicked()), this, SLOT(Remove()));

    //starts QTimer
    timer->start();
}

Timer::~Timer()
{
    delete ui;
}

//sets received hours
void Timer::setHours(const int &hours)
{
    ui->lcdNumber_h->display(hours);
    ui->lcdNumber_h->setPalette(Qt::magenta);
}

//sets received minutes
void Timer::setMin(const int &mins)
{
    ui->lcdNumber_m->display(mins);
    ui->lcdNumber_m->setPalette(Qt::magenta);
}

//sets received seconds
void Timer::setSec(const int &secs)
{
    ui->lcdNumber_s->display(secs);
    ui->lcdNumber_s->setPalette(Qt::magenta);
}

//describes how timer is working
void Timer::Tmr()
{
    int h = ui->lcdNumber_h->value();
    int m = ui->lcdNumber_m->value();
    int s = ui->lcdNumber_s->value();

    if(h == 0 && m == 0 && s == 0)
    {
        timer->stop();
        //calls the warning dialog that the timer went off
        QMessageBox msg;
        QApplication::beep();
        msg.warning(this, tr("TIMEOUT"), tr("<font color = white>YOUR TIMER HAS JUST FINISHED ITS WORK</font>"), QMessageBox::Ok);
        msg.setStyleSheet("QMessageBox{background: rgb(255,0,0);  border: none;font-family: Arial; font-style: normal;  font-size: 15pt; color: #000000 ; }");
        this->close();
    }
    else
    if(s == 0 && m == 0)
    {
        ui->lcdNumber_s->display(59);
        ui->lcdNumber_m->display(59);
        ui->lcdNumber_h->display(ui->lcdNumber_h->value()-1);
    }
    else
    if(s == 0)
    {
        ui->lcdNumber_s->display(59);
        ui->lcdNumber_m->display(ui->lcdNumber_m->value()-1);
    }
    else
    {
       ui->lcdNumber_s->display(ui->lcdNumber_s->value() - 1);
    }
}

//removes timer
void Timer::Remove()
{
    timer->stop();
    this->close();
}

//starts timer
void Timer::Start()
{
    timer->start();
}

//stops timer
void Timer::Stop()
{
    timer->stop();
}
