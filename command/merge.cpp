#include "merge.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void Merge::run(QStringList args) throw(CommandException)
{
    if (args.size() != 3 || args.isEmpty()) {
        throw CommandException("merge requires 3 parameters: sourcefile1 sourcefile2 destfile");
    }

    QString sourcefile = args.at(0);
    QString sourcefile2 = args.at(1);
    QString destfile = args.at(2);

    QImage original(sourcefile);
    QImage original2(sourcefile2);

    if ( !(original.width() == original2.width() && original.height() == original2.height()) )
    {
        original2 = ImageProcessor::resize(original2, original.width(), original.height());
    }

    QImage result = ImageProcessor::merge(original,original2);

    working_image = result;

    result.save(destfile);
}

QString Merge::usage()
{
    return "<sourcefile> <sourcefile> <destfile>";
}
