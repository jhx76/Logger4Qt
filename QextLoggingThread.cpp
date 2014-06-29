#include "QextLoggingThread.h"

/**
   @brief QextLoggingThread::QextLoggingThread
   @param parent
 */
QextLoggingThread::QextLoggingThread(QObject* parent) : QThread(parent)
{
    qDebug() << "Starting log manager...";
}

/**
   @brief QextLoggingThread::instance
   @return
 */
QextLoggingThread& QextLoggingThread::instance()
{
    static QextLoggingThread singleton;
    return singleton;
}

/**
   @brief QextLoggingThread::run
 */
void QextLoggingThread::run()
{
    setReading(true);
    while(isReading()) {
        if(!qLogBuffer()->isEmpty())
            emit newLog(qLogBuffer()->takeFirstMessage());
    }
}
