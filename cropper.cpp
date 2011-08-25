#include "cropper.h"
#include <QtGui/QImage>
#include <QString>
#include <QStringList>
#include <QDebug>

/**
* args: sourcefile x1 y1 x2 y2 destfile
*/
void Cropper::run(QStringList args)
{
    if (args.size() != 6) {
        qDebug() << "error: crop requires 5 parameters: sourcefile x1 y1 x2 y2 destfile";
        return;
    }

    QString sourcefile = args.at(0);
    int x1             = args.at(1).toInt();
    int y1             = args.at(2).toInt();
    int x2             = args.at(3).toInt();
    int y2             = args.at(4).toInt();
    QString destfile   = args.at(5);

    QImage cropped = crop(sourcefile, x1, y1, x2, y2);

    cropped.save(destfile);
}

QImage Cropper::crop(QString filename, int x1, int y1, int x2, int y2)
{
    int width = x2 - x1;
    int height = y2 - y1;

    QImage original(filename);

    QImage cropped(width, height, original.format());

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            cropped.setPixel(x, y, original.pixel(x, y));
        }
    }

    return cropped;
}
