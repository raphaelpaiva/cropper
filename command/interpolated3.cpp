#include "interpolated3.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"

void Interpolated3::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("lightness requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::Interpolated3(original);

    working_image = result;

    result.save(destfile);
}

QString Interpolated3::usage()
{
    return "<sourcefile> <destfile>";
}
