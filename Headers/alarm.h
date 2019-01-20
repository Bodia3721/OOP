/**
  alarm.h
  Purpose: Makes alarms work
*/

#ifndef ALARM_H
#define ALARM_H

#include <QtWidgets>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QSound>
#include <QDebug>

namespace Ui {
class Alarm;
}

class Alarm : public QWidget
{
    Q_OBJECT

public:
    explicit Alarm(QWidget *parent = nullptr);
    ~Alarm();

    /**
     * sets received time
     *
     * @brief setTime
     * @param time
     */
    void setTime(const QString& time);

    /**
     * receives time
     *
     * @brief getTime
     * @return
     */
    QString getTime();

    /**
     * sets music
     *
     * @brief setMusic
     * @param music
     */
    void setMusic(const QString& music);

    /**
     * gets music
     *
     * @brief getMusic
     * @return url of music
     */
    QString getMusic();

public slots:
    /**
     * describes how alarm is working
     *
     * @brief Alrm
     */
    void Alrm();

    /**
     *removes alarm
     *
     * @brief Remove
     */
    void Remove();



private:
    Ui::Alarm *ui;
    QTimer *timer;
    QString *sound;
};

#endif // ALARM_H
