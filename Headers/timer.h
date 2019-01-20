/**
  timer.h
  Purpose: Makes timers work
*/

#ifndef TIMER_H
#define TIMER_H

#include <QtWidgets>
#include <QTimer>
#include <QMessageBox>
#include <QLCDNumber>

namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

    /**
     * sets received hours
     *
     * @brief setHours
     * @param hours
     */
    void setHours(const int& hours);

    /**
     * sets received minutes
     *
     * @brief setMin
     * @param mins
     */
    void setMin(const int& mins);

    /**
     * sets received seconds
     *
     * @brief setSec
     * @param secs
     */
    void setSec(const int& secs);

public slots:

    /**
     * describes how timer is working
     *
     * @brief Tmr
     */
    void Tmr();

    /**
     * removes timer
     *
     * @brief Remove
     */
    void Remove();

    /**
     *starts timer
     *
     * @brief Start
     */
    void Start();

    /**
     * stops timer
     *
     * @brief Stop
     */
    void Stop();

private:
    Ui::Timer *ui;
    QTimer *timer;
};

#endif // TIMER_H
