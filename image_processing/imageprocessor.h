#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QImage>

class ImageProcessor
{
public:
    ImageProcessor();
    static QImage crop(QImage, int x1, int y1, int x2, int y2);
    static QImage resize(QImage, int width, int height);
};

#endif // IMAGEPROCESSOR_H
