#include "flipvertical.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void FlipVertical::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("flipVertical requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::flipVertical(original);

    working_image = result;

    result.save(destfile);
}

QString FlipVertical::usage()
{
    return "<sourcefile> <destfile>";
}
