#ifndef CROPPER_H
#define CROPPER_H

#include <QString>
#include <QtGui/QImage>

class Cropper
{
public:
    Cropper();
    static QImage crop(QString filename, int x1, int y1, int x2, int y2);
};

#endif // CROPPER_H
