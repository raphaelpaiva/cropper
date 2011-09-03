#include "fliphorizontal.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void FlipHorizontal::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("flipHorizontal requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::flipHorizontal(original);

    result.save(destfile);
}

QString FlipHorizontal::usage()
{
    return "<sourcefile> <destfile>";
}
