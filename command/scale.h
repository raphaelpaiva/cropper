#ifndef SCALE_H
#define SCALE_H

#include <QStringList>

#include "resize.h"

class Scale : public Resize
{
public:
    Scale() {name = "scale";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // SCALE_H
