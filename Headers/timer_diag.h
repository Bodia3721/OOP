/**
  timer_diag.h
  Purpose: Sets time in timers
*/

#ifndef TIMER_DIAG_H
#define TIMER_DIAG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class Timer_diag;
}

class Timer_diag : public QDialog
{
    Q_OBJECT

public:
    explicit Timer_diag(QWidget *parent = nullptr);
    ~Timer_diag();

public slots:
    /**
     * receives hours
     *
     * @brief getHours
     * @return received hours
     */
    int getHours();

    /**
     * receives seconds
     *
     * @brief getMin
     * @return received minutes
     */
    int getMin();

    /**
     * returns inputed time
     *
     * @brief alrm
     * @return inputed time
     */
    int getSec();

private:
    Ui::Timer_diag *ui;
};

#endif // TIMER_DIAG_H
