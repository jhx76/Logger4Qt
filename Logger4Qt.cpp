#include "Logger4Qt.h"

/**
   @brief Logger4Qt::Logger4Qt
   @param parent
 */
Logger4Qt::Logger4Qt(QObject* parent) : QObject(parent)
{
    loggingTime = false;
    loggingContext = false;
    loggingType = false;
    dateTimeFormat = "dd/MM/yyyy hh:mm.ss";
}

/**
   @brief Logger4Qt::~Logger4Qt
 */
Logger4Qt::~Logger4Qt()
{

}

/**
   @brief Logger4Qt::stringLog
   @param log
   @return
 */
QString Logger4Qt::stringLog(const QextLog &log, const QString& arg_logFormat, const QString& arg_dateTimeFormat)
{
    //QString log_format = arg_logFormat.isEmpty() ? logFormat
    //                                             : arg_logFormat;
    QString date_time_format = arg_dateTimeFormat.isEmpty() ? dateTimeFormat
                                                            : arg_dateTimeFormat;

    QString rslt = "";
    if(loggingTime)
        rslt += "At "+QDateTime::currentDateTime().toString(dateTimeFormat)+": ";
    if(loggingContext)
        rslt += "("+log.getContext()+") ";
    if(loggingType) {
        switch(log.getType()) {
        case QtDebugMsg:
            rslt += "Debug: ";
            break;
        case QtWarningMsg:
            rslt += "Warning: ";
            break;
        case QtCriticalMsg:
            rslt += "Critical: ";
            break;
        case QtFatalMsg:
            rslt += "Fatal: ";
            break;
        }
    }
    rslt += log.getMessage();
    return rslt;
}


