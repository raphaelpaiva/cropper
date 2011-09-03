#ifndef FLIPVERTICAL_H
#define FLIPVERTICAL_H

#include "command.h"

class FlipVertical : public Command
{
public:
    FlipVertical() {name = "flipV";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // FLIPVERTICAL_H
