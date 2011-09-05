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

    bool conversion_ok = true;

    QString sourcefile = args.at(0);
    int width          = args.at(1).toInt(&conversion_ok);
    int height         = args.at(2).toInt(&conversion_ok);
    QString destfile   = args.at(3);

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse integer parameter");
    }

    QImage original(sourcefile);

    QImage scaled = ImageProcessor::resize(original, width, height);

    working_image = scaled;

    scaled.save(destfile);
}

QString Resize::usage()
{
    return "<sourcefile> <width (integer)> <height (integer)> <destfile>";
}
