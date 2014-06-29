#ifndef QEXTMESSAGEHANDLER_H
#define QEXTMESSAGEHANDLER_H

#include <QObject>
#include <QString>

/**
   @brief The QextMessageHandler class
 */
class QextMessageHandler {
private:
    QextMessageHandler();

public:
    static QextMessageHandler& instance();
    static void release();
    static void handleMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

#endif // QEXTMESSAGEHANDLER_H
