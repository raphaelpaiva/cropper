#include "resize.h"

#include <QString>
#include <QStringList>
#include <QDebug>

#include <cmath>

#include "../image_processing/imageprocessor.h"

/**
* args: sourcefile width height destfile
*/
void Resize::run(QStringList args) throw(CommandException)
{
    if (args.size() != 4 || args.isEmpty()) {
        throw CommandException("resize requires 4 parameters: sourcefile width heigth destfile");
    }

    QString sourcefile = args.at(0);
    int width          = args.at(1).toInt();
    int height         = args.at(2).toInt();
    QString destfile   = args.at(3);

    QImage original(sourcefile);

    QImage scaled = ImageProcessor::resize(original, width, height);

    scaled.save(destfile);
}

QString Resize::usage()
{
    return "<sourcefile> <width> <height> <destfile>";
}
