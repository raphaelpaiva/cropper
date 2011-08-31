#include "lightness.h"
#include "../image_processing/imageprocessor.h"
#include <QStringList>
#include <QImage>

void Lightness::run(QStringList args) throw(CommandException){

    if (args.size() != 3 || args.isEmpty()) {
        throw CommandException("lightness requires 3 parameters: sourcefile lightness destfile");
    }
    bool conversion_ok = true;

    QString sourcefile = args.at(0);
    double l = args.at(1).toDouble(&conversion_ok);
    QString destfile = args.at(2);

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse integer parameter");
    }

    QImage original(sourcefile);

    QImage result = ImageProcessor::lightness(original,l);
    result.save(destfile);

}

QString Lightness::usage(){
    return "<sourcefile> <lighness> <destfile>";
}
