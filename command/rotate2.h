#ifndef ROTATE2_H
#define ROTATE2_H

#include "command.h"


class Rotate2 : public Command
{
public:
    Rotate2() {name = "rotateLeft";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // ROTATE2_H
