/**
  mainwindow.cpp
  Purpose: shows and operates with timers and alarms

  @author inmistlosted
  @version 1.1
*/

#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setAttribute(Qt::WA_QuitOnClose);
    alarm_diag = new Alarm_diag(this);
    tmr_diag = new Timer_diag(this);

//connects signals to slots
    connect(ui->custom_btn, SIGNAL(clicked()), this, SLOT(Add_Custom_Timers()));
    connect(ui->add_alarm_btn, SIGNAL(clicked()), this, SLOT(Open_alarm()));
    connect(ui->add_timer_btn, SIGNAL(clicked()), this, SLOT(Open_timer()));
    connect(alarm_diag, SIGNAL(accepted()), this, SLOT(Add_Alarm()));
    connect(tmr_diag, SIGNAL(accepted()), this, SLOT(Add_Timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//calls a dialog window for inputing time for alarms
void MainWindow::Open_alarm()
{

    alarm_diag->open();
}

//adds alarm
void MainWindow::Add_Alarm()
{
    qDebug() << "Addind new alarm";
    alarm = new Alarm(this);
    alarm->setTime(alarm_diag->alrm().toString());
    alarm->setMusic(alarm_diag->Add_music());
    ui->alarm_Layout->addWidget(alarm);
}

//calls a dialog window for inputing time for timers
void MainWindow::Open_timer()
{

    tmr_diag->open();
}

//adds timer
void MainWindow::Add_Timer()
{
    qDebug() << "Addind new timer";
    tmr = new Timer(this);
    tmr->setHours(tmr_diag->getHours());
    tmr->setMin(tmr_diag->getMin());
    tmr->setSec(tmr_diag->getSec());
    ui->timer_Layout->addWidget(tmr);
}

//adds custom timers
void MainWindow::Add_Custom_Timers()
{
    qDebug() << "Addind custom timers";
    tmr1 = new Timer(this);
    tmr2 = new Timer(this);
    tmr3 = new Timer(this);
    tmr4 = new Timer(this);
    tmr5 = new Timer(this);

    tmr1->setHours(0);
    tmr1->setMin(5);
    tmr1->setSec(0);
    ui->timer_Layout->addWidget(tmr1);

    tmr2->setHours(0);
    tmr2->setMin(10);
    tmr2->setSec(0);
    ui->timer_Layout->addWidget(tmr2);

    tmr3->setHours(0);
    tmr3->setMin(15);
    tmr3->setSec(0);
    ui->timer_Layout->addWidget(tmr3);

    tmr4->setHours(0);
    tmr4->setMin(30);
    tmr4->setSec(0);
    ui->timer_Layout->addWidget(tmr4);

    tmr5->setHours(1);
    tmr5->setMin(0);
    tmr5->setSec(0);
    ui->timer_Layout->addWidget(tmr5);
}

