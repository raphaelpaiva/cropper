#include "interpolatedscale.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"

void InterpolatedScale::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("lightness requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::InterpolatedScale(original);

    result.save(destfile);
}

QString InterpolatedScale::usage()
{
    return "<sourcefile> <destfile>";
}
