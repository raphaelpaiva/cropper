#ifndef SEPIA_H
#define SEPIA_H

#include "command.h"

class Sepia : public Command
{
public:
    Sepia() {name = "sepia";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};


#endif // SEPIA_H
