#ifndef INVERTCOLORS_H
#define INVERTCOLORS_H

#include "command.h"

class InvertColors : public Command
{
public:
    InvertColors() {name = "invertColors";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // INVERTCOLORS_H
