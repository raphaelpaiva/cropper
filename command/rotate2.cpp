#include "rotate2.h"

#include "../image_processing/imageprocessor.h"

#include <QString>

void Rotate2::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("rotate requires 2 parameters: sourcefile destfile");
    }

    bool conversion_ok = true;

    QString sourcefile = args[0];
    QString destfile = args[1];

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse integer parameter");
    }

    QImage original(sourcefile);
    QImage rotated = original;

    rotated = ImageProcessor::rotate2(rotated);

    working_image = rotated;

    rotated.save(destfile);
}

QString Rotate2::usage()
{
    return "<sourcefile> <desrfile>";
}
