#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QStringList>

class Command
{
public:
    Command();
    virtual void run(QStringList args)=0;
    QString name;
};

#endif // COMMAND_H
