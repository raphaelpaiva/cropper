#ifndef CROPPER_H
#define CROPPER_H

#include <QStringList>

#include "command.h"

class Cropper : public Command
{
public:
    Cropper() {name = "crop";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // CROPPER_H
