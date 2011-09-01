#include "grayscale.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void GrayScale::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("invertColors requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::grayScale(original);

    result.save(destfile);
}

QString GrayScale::usage()
{
    return "<sourcefile> <destfile>";
}
