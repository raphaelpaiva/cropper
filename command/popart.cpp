#include "popart.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void PopArt::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("popArt requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::popArt(original);

    working_image = result;

    result.save(destfile);
}

QString PopArt::usage()
{
    return "<sourcefile> <destfile>";
}
