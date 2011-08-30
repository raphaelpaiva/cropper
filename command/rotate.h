#ifndef ROTATE_H
#define ROTATE_H

#include "command.h"

class Rotate : public Command
{
public:
    Rotate() {name = "rotate";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // ROTATE_H
