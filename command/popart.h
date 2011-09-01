#ifndef POPART_H
#define POPART_H

#include "command.h"

class PopArt : public Command
{
public:
    PopArt() {name = "popArt";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // POPART_H
