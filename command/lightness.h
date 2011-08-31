#ifndef LIGHTNESS_H
#define LIGHTNESS_H

#include "command.h"

class Lightness : public Command
{
public:
    Lightness(){name = "lightness";}
    void run(QStringList args) throw(CommandException);
    QString usage();


};

#endif // LIGHTNESS_H
