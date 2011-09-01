#ifndef CRAZY_H
#define CRAZY_H

#include "command.h"

class Crazy : public Command
{
public:
    Crazy() {name = "crazy";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // CRAZY_H
