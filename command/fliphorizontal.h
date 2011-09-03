#ifndef FLIPHORIZONTAL_H
#define FLIPHORIZONTAL_H

#include "command.h"

class FlipHorizontal : public Command
{
public:
    FlipHorizontal() {name = "flipH";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // FLIPHORIZONTAL_H
