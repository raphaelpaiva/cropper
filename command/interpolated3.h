#ifndef INTERPOLATED3_H
#define INTERPOLATED3_H

#include "command.h"

class Interpolated3 : public Command
{
public:
    Interpolated3() {name = "scale3x";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // INTERPOLATED3_H
