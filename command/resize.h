#ifndef RESIZE_H
#define RESIZE_H

#include "command.h"
#include <QStringList>

class Resize : public Command
{
public:
    Resize() {name = "resize";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // SCALE_H
