#include "scale.h"

#include <QString>
#include <QDebug>

/**
* args: sourcefile scale destfile
*/
void Scale::run(QStringList args) throw(CommandException)
{
    if (args.size() != 3) {
        throw CommandException("scale requires 3 parameters: sourcefile scale destfile");
    }

    QString sourcefile = args.at(0);
    double scale       = args.at(1).toDouble();
    QString destfile   = args.at(2);

    QImage original(sourcefile);

    int width = original.width();
    int height = original.height();

    QImage scaled = resize(original, scale*width, scale*height);

    scaled.save(destfile);
}
