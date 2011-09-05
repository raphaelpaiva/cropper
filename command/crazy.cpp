#include "crazy.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void Crazy::run(QStringList args) throw(CommandException)
{
    if (args.size() != 2 || args.isEmpty()) {
        throw CommandException("invertColors requires 2 parameters: sourcefile destfile");
    }

    QString sourcefile = args.at(0);
    QString destfile = args.at(1);

    QImage original(sourcefile);

    QImage result = ImageProcessor::crazy(original);

    working_image = result;

    result.save(destfile);
}

QString Crazy::usage()
{
    return "<sourcefile> <destfile>";
}
