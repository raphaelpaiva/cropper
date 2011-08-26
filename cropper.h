#ifndef CROPPER_H
#define CROPPER_H

#include <QString>
#include <QStringList>
#include <QtGui/QImage>

#include "command.h"

class Cropper : public Command
{
public:
    Cropper() {name = "crop";}
    QImage crop(QString filename, int x1, int y1, int x2, int y2);
    void run(QStringList args) throw(CommandException);
};

#endif // CROPPER_H
