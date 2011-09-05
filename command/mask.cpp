#include "mask.h"

#include <QImage>
#include "../image_processing/imageprocessor.h"


void Mask::run(QStringList args) throw(CommandException)
{
    if (args.size() != 4 || args.isEmpty()) {
        throw CommandException("invertColors requires 2 parameters: sourcefile sourcefile2 mask destfile");
    }

    QString sourcefile = args.at(0);
    QString sourcefile2 = args.at(1);
    QString mascara = args.at(2);

    QString destfile = args.at(3);

    QImage original(sourcefile);
    QImage original2(sourcefile2);
    QImage mascaraf(mascara);

    if ( !(original.width() == original2.width() && original.height() == original2.height()) )
    {
        original2 = ImageProcessor::resize(original2, original.width(), original.height());
    }

    if ( !(original.width() == mascaraf.width() && original.height() == mascaraf.height()) )
    {
        mascaraf = ImageProcessor::resize(mascaraf, original.width(), original.height());
    }

    QImage result = ImageProcessor::mask(original, original2, mascaraf);

    working_image = result;

    result.save(destfile);
}

QString Mask::usage()
{
    return "<sourcefile> <sourcefile> <mask> <destfile>";
}
