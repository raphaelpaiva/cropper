#include "imageprocessor.h"

#include <cmath>
#include <QColor>
#include <QPoint>

#include <QDebug>

QImage ImageProcessor::crop(QImage original, int x1, int y1, int x2, int y2)
{
    int width = x2 - x1;
    int height = y2 - y1;

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

QImage ImageProcessor::resize(QImage original, int width, int height)
{
    QImage resized(width, height, original.format());

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

            resized.setPixel(j, i, color);
        }
    }

    return resized;
}

QImage ImageProcessor::mirror(QImage original)
{
    QImage mirrored(original.width(), original.height(), original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = original.width() - 1; x >= 0; x--)
        {
            mirrored.setPixel(x, y, original.pixel((original.width() - 1) - x, y));
        }
    }

    return mirrored;
}

QImage ImageProcessor::lightness(QImage original, double lightnessIntensity)
{
    QImage final(original.width(), original.height(), original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = original.width() - 1; x >= 0; x--)
        {


            QRgb cc = original.pixel(x,y);

            QColor co = QColor::fromRgb(cc);

            int red = (int)(co.red() * lightnessIntensity) ;
            if (red>0xFF) red=0xFF;
            int green = (int)(co.green() * lightnessIntensity) ;
            if (green>0xFF) green=0xFF;
            int blue = (int)(co.blue() * lightnessIntensity) ;
            if (blue>0xFF) blue=0xFF;
            co.setRed(red);
            co.setGreen(green);
            co.setBlue(blue);

            final.setPixel(x, y, co.rgb());
        }
    }

    return final;
}

QImage ImageProcessor::rotate(QImage original)
{
    QImage rotated(original.height(), original.width(), original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = 0; x < original.width(); x++)
        {
            rotated.setPixel(y, x, original.pixel(x, y));
        }
    }

    return rotated;
}
