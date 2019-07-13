#ifndef NOTIFY_H
#define NOTIFY_H

#include <QString>

class Notify
{
public:
    Notify();
    QString title;
    QString message;
    Notify(QString, QString);
};

#endif // NOTIFY_H
