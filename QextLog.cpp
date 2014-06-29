#include "QextLog.h"

/**
   @brief QextLog::QextLog
 */
QextLog::QextLog()
{
    type = QtDebugMsg;
    context = "";
    message = "";
}

/**
   @brief QextLog::QextLog
   @param type
   @param context
   @param message
 */
QextLog::QextLog(QtMsgType type, const QString &context, const QString &message)
{
    this->type = type;
    this->context = context;
    this->message = message;
}

/**
   @brief QextLog::QextLog
   @param other
 */
QextLog::QextLog(const QextLog &other)
{
    this->type = other.type;
    this->context = other.context;
    this->message = other.message;
}

/**
   @brief QextLog::operator =
   @param other
   @return
 */
QextLog& QextLog::operator = (const QextLog& other)
{
    this->type = other.type;
    this->context = other.context;
    this->message = other.message;
    return *this;
}

