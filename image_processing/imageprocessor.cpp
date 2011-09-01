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

QImage ImageProcessor::merge(QImage original, QImage original2)
{
    int width, height;

    if(original.width()>original2.width()) width = original.width();
    if(original.width()<=original2.width()) width = original2.width();

    if(original.height()>original2.height()) height = original.height();
    if(original.height()<=original2.height()) height = original2.height();

    QImage final(width, height, original.format());

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {


            QRgb cc = original.pixel(x,y);
            QColor co = QColor::fromRgb(cc);

            QRgb cc2 = original2.pixel(x,y);
            QColor co2 = QColor::fromRgb(cc2);

            int red = co.red()*0.5 + co2.red()*0.5;
            int green = co.green()*0.5 + co2.green()*0.5;
            int blue = co.blue()*0.5 + co2.blue()*0.5;


            co.setRed(red);
            co.setGreen(green);
            co.setBlue(blue);

            final.setPixel(x, y, co.rgb());
        }
    }

    return final;
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

QImage ImageProcessor::crazy(QImage original)
{
    QImage final(original.width(), original.height(), original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = original.width() - 1; x >= 0; x--)
        {

            int red = original.pixel(x,y) >> 16;
            int green = original.pixel(x,y) >> 8; green = green % 0x100;
            int blue = original.pixel(x,y) % 0x100;

            int r = (int)(255 - red*2) % 0x100;
            int g = (int)(255 - green*2) % 0x100;
            int b = (int)(255 - blue*1.55) % 0x100;

            r = r << 16;
            g = g << 8;


            final.setPixel(x, y, (r + g + b));
        }
    }

    return final;
}

QImage ImageProcessor::grayScale(QImage original)
{
    QImage final(original.width(), original.height(), original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = original.width() - 1; x >= 0; x--)
        {


            QRgb cc = original.pixel(x,y);

            QColor co = QColor::fromRgb(cc);

            int red = (int)(co.red()) ;
            if (red>0xFF) red=0xFF;
            int green = (int)(co.green()) ;
            if (green>0xFF) green=0xFF;
            int blue = (int)(co.blue()) ;
            if (blue>0xFF) blue=0xFF;
            co.setRed((red + green + blue)/3);
            co.setGreen((red + green + blue)/3);
            co.setBlue((red + green + blue)/3);

            final.setPixel(x, y, co.rgb());
        }
    }

    return final;
}

QImage ImageProcessor::popArt(QImage original)
{
    int width = 2*original.width();
    int height = 2*original.height();
    QImage final(width, height, original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = 0; x < original.width(); x++)
        {
            QRgb cc = original.pixel(x,y);
            QColor co = QColor::fromRgb(cc);
            int red = (int)(co.red()) ;
            if (red>0xFF) red=0xFF;
            int green = (int)(co.green()) ;
            if (green>0xFF) green=0xFF;
            int blue = (int)(co.blue()) ;
            if (blue>0xFF) blue=0xFF;
            co.setRed(red);
            co.setGreen(0);
            co.setBlue(0);

            final.setPixel(x, y, co.rgb());

            co.setRed(0);
            co.setGreen(green);
            co.setBlue(0);

            final.setPixel(x+original.width(), y, co.rgb());

            co.setRed(0);
            co.setGreen(0);
            co.setBlue(blue);

            final.setPixel(x,y+original.height(), co.rgb());


            co.setRed(red);
            co.setGreen(green);
            co.setBlue(0);

            final.setPixel(x+original.width(), y+original.height(), co.rgb());


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


QImage ImageProcessor::invertColors(QImage original)
{
    QImage inverted(original.width(), original.height(), original.format());

    for (int y = 0; y < original.height(); y++)
    {
        for (int x = 0; x < original.width(); x++)
        {
            inverted.setPixel(x, y, (int)(0xFFFFFF - original.pixel(x, y)));
        }
    }

    return inverted;
}


QImage ImageProcessor::InterpolatedScale(QImage original)
{
    int width = original.width();
    int height = original.height();

    QImage resized(2*width, 2*height, original.format());

    double px, py;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            px = j;
            py = i;


            //Colocando os pixels arrumados na forma

            // A B C
            // D E F
            // G H I


           int E = original.pixel(px, py);
           int B = E;
           int D = E;
           int F = E;
           int H = E;

           if (py-1 > 0){
            B = original.pixel(px,py-1);
           }
           if (px-1 > 0){
            D = original.pixel(px-1,py);
           }
           if (px+1 < original.width()){
            F = original.pixel(px+1, py);
           }
           if (py+1 < original.height()){
            H = original.pixel(px, py+1);
           }

            //Vamos pegar o pixel central E e dividi-lo em 4 pixels.

            int E0, E1, E2, E3;

            //E calcular o valor da cor de cada um desses 4 pixels.

            if (B != H && D != F) {
                    E0 = D == B ? D : E;
                    E1 = B == F ? F : E;
                    E2 = D == H ? D : E;
                    E3 = H == F ? F : E;
            } else {
                    E0 = E;
                    E1 = E;
                    E2 = E;
                    E3 = E;
            }

            int nj = j*2;
            int ni = i*2;

            resized.setPixel(nj, ni, E0);

            if ( nj+1 < resized.width()) {
                resized.setPixel(nj+1, ni, E1);
            }

            if (ni + 1 < resized.height()) {
                resized.setPixel(nj, ni+1, E2);
            }

            if (nj + 1 < resized.width() && ni + 1 < resized.height()) {
                resized.setPixel(nj+1, ni+1, E3);
            }
        }
    }

    return resized;
}

QImage ImageProcessor::Interpolated3(QImage original)
{
    int width = original.width();
    int height = original.height();

    QImage resized(3*width, 3*height, original.format());

    double px, py;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            px = j;
            py = i;


            //Colocando os pixels arrumados na forma

            // A B C
            // D E F
            // G H I


           int E = original.pixel(px, py);
           int A = E;
           int B = E;
           int C = E;
           int D = E;
           int F = E;
           int G = E;
           int H = E;
           int I = E;

           if (py-1 > 0 && px-1 > 0){
            A = original.pixel(px-1,py-1);
           }
           if (py-1 > 0){
            B = original.pixel(px,py-1);
           }
           if (px+1 < original.width() && py-1 > 0){
            C = original.pixel(px+1, py-1);
           }
           if (px-1 > 0){
            D = original.pixel(px-1,py);
           }
           if (px+1 < original.width()){
            F = original.pixel(px+1, py);
           }
           if (py+1 < original.height() && px-1 > 0){
            G = original.pixel(px, py+1);
           }
           if (py+1 < original.height()){
            H = original.pixel(px, py+1);
           }
           if (py+1 < original.height() && px+1 < original.width()){
            H = original.pixel(px, py+1);
           }

            //Vamos pegar o pixel central E e dividi-lo em 9 pixels.

            int E0, E1, E2, E3, E4, E5, E6, E7, E8;

            //E calcular o valor da cor de cada um desses 9 pixels.

            if (B != H && D != F) {
                    E0 = D == B ? D : E;
                    E1 = (D == B && E != C) || (B == F && E != A) ? B : E;
                    E2 = B == F ? F : E;
                    E3 = (D == B && E != G) || (D == H && E != A) ? D : E;
                    E4 = E;
                    E5 = (B == F && E != I) || (H == F && E != C) ? F : E;
                    E6 = D == H ? D : E;
                    E7 = (D == H && E != I) || (H == F && E != G) ? H : E;
                    E8 = H == F ? F : E;
            } else {
                    E0 = E;
                    E1 = E;
                    E2 = E;
                    E3 = E;
                    E4 = E;
                    E5 = E;
                    E6 = E;
                    E7 = E;
                    E8 = E;
            }

            int nj = j*3;
            int ni = i*3;

            resized.setPixel(nj, ni, E0);

            if ( nj+1 < resized.width()) {
                resized.setPixel(nj+1, ni, E1);
            }

            if ( nj+2 < resized.width()) {
                resized.setPixel(nj+2, ni, E2);
            }

            if (nj + 0 < resized.width() && ni + 1 < resized.height()) {
                resized.setPixel(nj+0, ni+1, E3);
            }

            if (nj + 1 < resized.width() && ni + 1 < resized.height()) {
                resized.setPixel(nj+1, ni+1, E4);
            }

            if (nj + 2 < resized.width() && ni + 1 < resized.height()) {
                resized.setPixel(nj+2, ni+1, E5);
            }

            if (nj + 0 < resized.width() && ni + 2 < resized.height()) {
                resized.setPixel(nj+0, ni+2, E6);
            }
            if (nj + 1 < resized.width() && ni + 2 < resized.height()) {
                resized.setPixel(nj+1, ni+2, E7);
            }
            if (nj + 2 < resized.width() && ni + 2 < resized.height()) {
                resized.setPixel(nj+2, ni+2, E8);
            }
        }
    }

    return resized;
}
