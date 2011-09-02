#include "sepia.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void Sepia::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("invertColors requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);
   // original = ImageProcessor::grayScale(original);
    QImage result = ImageProcessor::sepia(original);

    result.save(destfile);
}

QString Sepia::usage()
{
    return "<sourcefile> <destfile>";
}
