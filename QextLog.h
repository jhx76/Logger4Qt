#ifndef QEXTLOG_H
#define QEXTLOG_H

#include <QString>

/**
   @brief The QextLog class
 */
class QextLog {
private:
    QtMsgType type;
    QString context;
    QString message;

public:
    QextLog();
    QextLog(QtMsgType type, const QString& context, const QString& message);
    QextLog(const QextLog& other);
    QextLog& operator=(const QextLog& other);
    QtMsgType getType() const { return type; }
    void setType(QtMsgType type) { this->type = type; }
    const QString& getContext() const { return context; }
    void setContext(const QString& context) { this->context = context; }
    const QString& getMessage() const { return message; }
    void setMessage(const QString& message) { this->message = message; }
};


#endif // QEXTLOG_H
