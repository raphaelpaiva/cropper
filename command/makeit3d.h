#ifndef MAKEIT3D_H
#define MAKEIT3D_H

#include "command.h"

class MakeIt3d : public Command
{
public:
    MakeIt3d(){name = "makeIt3d";}

    void run(QStringList args) throw(CommandException);
    QString usage();


};

#endif // MAKEIT3D_H
