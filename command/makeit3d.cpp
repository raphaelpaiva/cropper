#include "makeit3d.h"
#include "../image_processing/imageprocessor.h"
#include <QStringList>
#include <QImage>

void MakeIt3d::run(QStringList args) throw(CommandException){

    if (args.size() != 3 || args.isEmpty()) {
        throw CommandException("makeIt3d requires 4 parameters: sourcefile sourcefile destfile");
    }
    bool conversion_ok = true;

    QString sourcefile = args.at(0);
    QString sourcefile2 = args.at(1);
    QString destfile = args.at(2);

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse integer parameter");
    }

    QImage original(sourcefile);
    QImage original2(sourcefile2);

    QImage result = ImageProcessor::makeIt3d(original,original2);

    working_image = result;

    result.save(destfile);

}

QString MakeIt3d::usage(){
    return "<sourcefile> <lighness> <destfile>";
}
