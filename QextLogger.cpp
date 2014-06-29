#include "QextLogger.h"

/**
   @brief QextLogger::setupMessageHandler
 */
void QextLogger::setupMessageHandler()
{
    qInstallMessageHandler(handleMessage); // install le message handler
}

/**
   @brief QextLogger::releaseMessageHandler
 */
void QextLogger::releaseMessageHandler()
{
    qInstallMessageHandler(0);
}

/**
   @brief QextMessageHandler::handleMessage
   @param type
   @param context
   @param msg
 */
void QextLogger::handleMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //QByteArray localMsg = msg.toLocal8Bit();
    QString strContext;
    strContext.sprintf("%s:%u, %s", context.file, context.line, context.function);
    if(type == QtFatalMsg) {
        abort();
    }
    qLogBuffer()->addMessage(type, strContext, msg);
}

/**
   @brief QextLogger::registerLogger
   @param logger
 */
void QextLogger::registerLogger(Logger4Qt *logger)
{
    if(!logger) return;
    QObject::connect(qLogger(), SIGNAL(newLog(QextLog)), logger, SLOT(onNewLog(QextLog)));
    loggerList.append(logger);
}

/**
   @brief QextLogger::releaseLogger
   @param logger
 */
void QextLogger::releaseLogger(Logger4Qt *logger)
{
    QObject::disconnect(qLogger(), SIGNAL(newLog(QextLog)), logger, SLOT(onNewLog(QextLog)));
    for(int i = 0; i < loggerList.count(); i++) {
        if(loggerList.at(i) == logger) {
            delete loggerList.takeAt(i);
            return;
        }
    }
}
