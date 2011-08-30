#include "rotate.h"
#include "../image_processing/imageprocessor.h"

#include <QString>

void Rotate::run(QStringList args) throw(CommandException)
{
    if (args.size() != 3 || args.isEmpty()) {
        throw CommandException("rotate requires 3 parameters: sourcefile times destfile");
    }

    bool conversion_ok = true;

    QString sourcefile = args[0];
    int times = args[1].toInt(&conversion_ok);
    QString destfile = args[2];

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse integer parameter");
    }

    QImage original(sourcefile);

    QImage rotated = original;

    for (int i = 0; i < times; i++)
    {
       rotated = ImageProcessor::rotate(rotated);
    }

    rotated.save(destfile);
}

QString Rotate::usage()
{
    return "<sourcefile> <times (integer)> <desrfile>";
}
