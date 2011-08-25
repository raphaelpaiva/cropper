#include <QtGui/QApplication>
#include "cropper.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "cropper!";

    QImage img = Cropper::crop("/home/raphaelpaiva/Images/Avatar/papaco.jpg", 65, 46, 100, 81);

    img.save("/home/raphaelpaiva/Images/Avatar/papaco-cropper.jpg");

    a.exit();

    return 0;
}
