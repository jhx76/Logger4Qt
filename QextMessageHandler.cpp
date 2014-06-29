#include "QextMessageHandler.h"
#include "QextLogBuffer.h"

/**
   @brief QextMessageHandler::QextMessageHandler
   @param parent
 */
QextMessageHandler::QextMessageHandler()
{
    qRegisterMetaType<QtMsgType>("QtMsgType");
}

/**
   @brief QextMessageHandler::instance
   @return
 */
QextMessageHandler& QextMessageHandler::instance()
{
    static QextMessageHandler singleton;
    return singleton;
}

/**
   @brief QextMessageHandler::handleMessage
   @param type
   @param context
   @param msg
 */
void QextMessageHandler::handleMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString strContext;
    strContext.sprintf("%s:%u, %s", context.file, context.line, context.function);
    if(type == QtFatalMsg) {
        abort();
    }
    qLogBuffer()->addMessage(type, strContext, msg);
}

