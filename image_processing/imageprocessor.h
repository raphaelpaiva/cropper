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
    static QImage InterpolatedScale(QImage original);
    static QImage Interpolated3(QImage original);
    static QImage invertColors(QImage original);
    static QImage grayScale(QImage original);
    static QImage popArt(QImage original);
    static QImage crazy(QImage original);
    static QImage merge(QImage original, QImage original2);
    static QImage append(QImage original, QImage original2);
    static QImage mask(QImage original, QImage original2, QImage mascara);
    static QImage sepia(QImage original);
};

#endif // IMAGEPROCESSOR_H
