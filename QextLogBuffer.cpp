#include "QextLogBuffer.h"

/**
   @brief QextLogBuffer::singleton
 */
QextLogBuffer *QextLogBuffer::singleton = NULL;

/**
   @brief QextLogBuffer::QextLogBuffer
 */
QextLogBuffer::QextLogBuffer() : QList<QextLog>()
{

}

/**
   @brief QextLogBuffer::~QextLogBuffer
 */
QextLogBuffer::~QextLogBuffer()
{

}

/**
   @brief QextLogBuffer::instance
   @return
 */
QextLogBuffer* QextLogBuffer::instance()
{
    if(singleton == NULL) {
        singleton = new QextLogBuffer();
    }
    return singleton;
}

/**
   @brief QextLogBuffer::release
 */
void QextLogBuffer::release()
{
    if(singleton != NULL) {
        delete singleton;
        singleton = NULL;
    }
}

/**
   @brief QextLogBuffer::addMessage
   @param msg
 */
void QextLogBuffer::addMessage(const QextLog& log)
{
    mutex.lock();
    append(log);
    mutex.unlock();
}

/**
   @brief QextLogBuffer::addMessage
   @param type
   @param context
   @param message
 */
void QextLogBuffer::addMessage(QtMsgType type, const QString &context, const QString &message)
{
    QextLog log(type, context, message);
    addMessage(log);
}

/**
   @brief QextLogBuffer::takeFirstMessage
   @return
 */
QextLog QextLogBuffer::takeFirstMessage()
{
    mutex.lock();
    QextLog log;
    if(!isEmpty()) {
        log = takeFirst();
    }
    mutex.unlock();
    return log;
}
