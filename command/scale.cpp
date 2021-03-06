#include "scale.h"

#include <QString>

#include "../image_processing/imageprocessor.h"

/**
* args: sourcefile scale destfile
*/
void Scale::run(QStringList args) throw(CommandException)
{
    if (args.size() != 3  || args.isEmpty()) {
        throw CommandException("scale requires 3 parameters: sourcefile scale destfile");
    }

    bool conversion_ok = true;

    QString sourcefile = args.at(0);
    double scale       = args.at(1).toDouble(&conversion_ok);
    QString destfile   = args.at(2);

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse double parameter");
    }

    QImage original(sourcefile);

    int width = original.width();
    int height = original.height();

    QImage scaled = ImageProcessor::resize(original, scale*width, scale*height);

    working_image = scaled;

    scaled.save(destfile);
}

QString Scale::usage()
{
    return "<sourcefile> <scale (double)> <destfile>";
}
