#ifndef SCALE_H
#define SCALE_H

#include "command.h"
#include <QStringList>
#include <QImage>

class Scale : public Command
{
public:
    Scale() {name = "scale";}

    void run(QStringList args);
    QImage scale(QString sourcefile, int width, int height);
};

#endif // SCALE_H
