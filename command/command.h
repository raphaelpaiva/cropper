#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>
#include <QString>
#include "commandexception.h"

class Command
{
public:
    Command();
    virtual void run(QStringList args) throw(CommandException)=0;
    virtual QString usage()=0;
    QString name;
};

#endif // COMMAND_H
