#include "mirror.h"
#include "../image_processing/imageprocessor.h"

#include <QImage>

void Mirror::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("mirror requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args[0];
    QString destfile = args[1];

    QImage original(sourcefile);

    QImage mirrored = ImageProcessor::mirror(original);

    working_image = mirrored;

    mirrored.save(destfile);
}

QString Mirror::usage()
{
    return "<sourcefile> <destfile>";
}
