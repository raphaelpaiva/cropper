#ifndef SCALE_H
#define SCALE_H

#include <QStringList>

#include "resize.h"

class Scale : public Resize
{
public:
    Scale() {name = "scale";}
    void run(QStringList args);
};

#endif // SCALE_H
