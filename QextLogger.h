#ifndef QEXTLOGGER_H
#define QEXTLOGGER_H

#include "QextLogBuffer.h"
#include "QextLoggingThread.h"
#include <QFile>
#include <iostream>

#include <Logger4Qt.h>

/**
   @brief The QextLogger class
 */
class QextLogger
{
private:
    static QList<Logger4Qt*> loggerList;

public:
    static void setupMessageHandler();
    static void releaseMessageHandler();
    static void handleMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    static registerLogger(Logger4Qt* logger);
    static releaseLogger(Logger4Qt* logger);
};

#endif
