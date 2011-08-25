#include "scale.h"

#include <QString>
#include <QStringList>
#include <QDebug>

#include <cmath>

/**
* args: sourcefile width height destfile
*/
void Scale::run(QStringList args)
{
    if (args.size() != 4) {
        qDebug() << "error: crop requires 3 parameters: sourcefile scale% destfile";
        return;
    }

    QString sourcefile = args.at(0);
    int width          = args.at(1).toInt();
    int height         = args.at(2).toInt();
    QString destfile   = args.at(3);

    QImage scaled = scale(sourcefile, width, height);

    scaled.save(destfile);
}

QImage Scale::scale(QString sourcefile, int width, int height)
{
    QImage original(sourcefile);
    QImage scaled(width, height, original.format());

    double x_ratio = original.width()/(double)width;
    double y_ratio = original.height()/(double)height;

    double px, py;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            px = floor(j*x_ratio);
            py = floor(i*y_ratio);

            int color = original.pixel(px, py);

            scaled.setPixel(j, i, color);
        }
    }

    return scaled;
}
