#ifndef INTERPOLATEDSCALE_H
#define INTERPOLATEDSCALE_H

#include "command.h"

class InterpolatedScale : public Command
{
public:
    InterpolatedScale() {name = "scale2x";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // INTERPOLATEDSCALE_H
