#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "command.h"

class GrayScale : public Command
{
public:
    GrayScale() {name = "grayScale";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // GRAYSCALE_H
