#include "xray.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void XRay::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("XRay requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);
    original = ImageProcessor::grayScale(original);
    QImage result = ImageProcessor::xray(original);

    working_image = result;

    result.save(destfile);
}

QString XRay::usage()
{
    return "<sourcefile> <destfile>";
}
