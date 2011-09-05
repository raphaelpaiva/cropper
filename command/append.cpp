#include "append.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void Append::run(QStringList args) throw(CommandException)
{
    if (args.size() != 3 || args.isEmpty()) {
        throw CommandException("invertColors requires 3 parameters: sourcefile sourcefile2 destfile");
    }

    QString sourcefile = args.at(0);
    QString sourcefile2 = args.at(1);
    QString destfile = args.at(2);

    QImage original2(sourcefile);
    QImage original(sourcefile2);

    QImage result = ImageProcessor::append(original, original2);

    working_image = result;

    result.save(destfile);
}

QString Append::usage()
{
    return "<sourcefile> <sourcefile> <destfile>";
}
