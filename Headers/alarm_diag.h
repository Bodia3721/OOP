/**
  alarm_diag.h
  Purpose: Sets time in alarms
*/

#ifndef ALARM_DIAG_H
#define ALARM_DIAG_H
#include <QDialog>
#include <QTime>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Alarm_diag;
}

class Alarm_diag : public QDialog
{
    Q_OBJECT

public:
    explicit Alarm_diag(QWidget *parent = nullptr);
    ~Alarm_diag();
public slots:

    /**
     * receives inputed hours
     *
     * @brief getHours
     * @return received hours
     */
    int getHours();

    /**
     * receives inputed minutes
     *
     * @brief getMin
     * @return received minutes
     */
    int getMin();

    /**
     * receives inputed seconds
     *
     * @brief getSec
     * @return received seconds
     */
    int getSec();

    /**
     * returns inputed time
     *
     * @brief alrm
     * @return inputed time
     */
    QTime alrm();

    /**
     * receives inputed music
     *
     * @brief Add_music
     * @return url of music
     */
    QString Add_music();

private:
    Ui::Alarm_diag *ui;
};

#endif // ALARM_DIAG_H
