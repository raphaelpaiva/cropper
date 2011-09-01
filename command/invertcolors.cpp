#include "invertcolors.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"

void InvertColors::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("invertColors requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::invertColors(original);

    result.save(destfile);
}

QString InvertColors::usage()
{
    return "<sourcefile> <destfile>";
}
