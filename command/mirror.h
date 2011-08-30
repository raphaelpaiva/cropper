#ifndef MIRROR_H
#define MIRROR_H

#include "command.h"

class Mirror : public Command
{
public:
    Mirror() {name = "mirror";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // MIRROR_H
