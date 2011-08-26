#ifndef RESIZE_H
#define RESIZE_H

#include "command.h"
#include <QStringList>
#include <QImage>

class Resize : public Command
{
public:
    Resize() {name = "resize";}

    void run(QStringList args) throw(CommandException);
    QImage resize(QImage original, int width, int height);
};

#endif // SCALE_H
