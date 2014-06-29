#ifndef QEXTLOGGINGTHREAD_H
#define QEXTLOGGINGTHREAD_H

#include <QThread>
#include <QString>
#include <QDebug>

#include "QextLogBuffer.h"

/**
   @brief The QextLoggingThread class
 */
class QextLoggingThread : public QThread
{
    Q_OBJECT
private:
    bool reading;

    QextLoggingThread(QObject* parent = 0);

public:
    static QextLoggingThread& instance();

    void run();
    bool isReading() const { return reading; }
    void setReading(bool b) { reading = b; }

signals:
    void newLog(QextLog);
};

#define qLogger() &QextLoggingThread::instance()

#endif // QEXTLOGGINGTHREAD_H
