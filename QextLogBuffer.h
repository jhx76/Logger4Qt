#ifndef QEXTLOGBUFFER_H
#define QEXTLOGBUFFER_H

//#include <QStringList>

#include <QList>
#include <QString>
#include <QMutex>
#include <QextLog.h>

#define qLogBuffer() QextLogBuffer::instance()

/**
   @brief The QextLogBuffer class
 */
class QextLogBuffer : public QList<QextLog> {
private:
    QMutex mutex;
    static QextLogBuffer* singleton;
    QextLogBuffer();
    virtual ~QextLogBuffer();

public:
    void addMessage(QtMsgType type, const QString& context, const QString& message);
    void addMessage(const QextLog& log);
    QextLog takeFirstMessage();

    static QextLogBuffer* instance();
    static void release();
};

#endif // QEXTLOGBUFFER_H
