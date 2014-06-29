#ifndef LOGGER4QT_H
#define LOGGER4QT_H

#include <QObject>
#include <QextLog.h>

#include <QDateTime>

/**
   @brief The Logger4Qt class
 */
class Logger4Qt : public QObject
{
    Q_OBJECT
private:
    bool loggingTime;
    bool loggingContext;
    bool loggingType;
    QString dateTimeFormat; //default is dd/MM/yyyy hh:mm.ss
    //QString logFormat;

protected:
    virtual QString stringLog(const QextLog& log/*, const QString& arg_logFormat = ""*/,
                              const QString& arg_dateTimeFormat = "");

public:
    Logger4Qt(QObject* parent = 0);
    virtual ~Logger4Qt();
    void setDateTimeFormat(const QString& format) { dateTimeFormat = format; }
    void setLogFormat(const QString& format) { logFormat = format; }
    bool isLoggingTime() const { return loggingTime; }
    void setLoggingTime(bool logging) { loggingTime = logging; }
    bool isLoggingContext() const { return loggingContext; }
    void setLoggingContext(bool logging) { loggingContext = logging; }
    bool isLoggingType() const { return loggingType; }
    void setLoggingType(bool logging) { loggingType = logging; }

public slots:
    virtual void onNewLog(QextLog) = 0;
};

#endif // LOGGER4QT_H
