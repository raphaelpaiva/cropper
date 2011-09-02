#ifndef APPEND_H
#define APPEND_H

#include "command.h"

class Append : public Command
{
public:
    Append() {name = "append";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // APPEND_H
