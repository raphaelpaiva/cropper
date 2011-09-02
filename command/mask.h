#ifndef MASK_H
#define MASK_H

#include "command.h"

class Mask : public Command
{
public:
    Mask(){name = "mask";}

    void run(QStringList args) throw(CommandException);
    QString usage();


};


#endif // MASK_H
