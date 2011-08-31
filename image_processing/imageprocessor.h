#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QImage>

class ImageProcessor
{
public:
    ImageProcessor();
    static QImage crop(QImage, int x1, int y1, int x2, int y2);
    static QImage resize(QImage, int width, int height);
    static QImage mirror(QImage original);
    static QImage rotate(QImage orginal);
    static QImage lightness(QImage orginal, double lightnessIntensity);
};

#endif // IMAGEPROCESSOR_H
