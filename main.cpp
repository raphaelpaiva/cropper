#include <iostream>

#include <QtGui/QApplication>
#include <QMap>
#include <QStringList>
#include <QList>
#include <QTextStream>
#include <QDebug>

#include "command/command.h"
#include "command/commandexception.h"
#include "command/crop.h"
#include "command/resize.h"
#include "command/scale.h"
#include "command/rotate.h"
#include "command/rotate2.h"
#include "command/mirror.h"
#include "command/lightness.h"
#include "command/interpolatedscale.h"
#include "command/interpolated3.h"
#include "command/invertcolors.h"
#include "command/grayscale.h"
#include "command/popart.h"
#include "command/crazy.h"
#include "command/merge.h"
#include "command/append.h"
#include "command/mask.h"
#include "command/sepia.h"
#include "command/xray.h"
#include "command/fliphorizontal.h"
#include "command/flipvertical.h"
#include "command/makeit3d.h"

QMap<QString, Command*> command_map;
QTextStream qout(stdout);

void init_command_map()
{
    Cropper *cropper = new Cropper();
    Resize *resize   = new Resize();
    Scale  *scale    = new Scale();
    Rotate *rotate   = new Rotate();
    Rotate2 *rotate2   = new Rotate2();
    Mirror *mirror   = new Mirror();
    Lightness *lightness   = new Lightness();
    InterpolatedScale *interpolated = new InterpolatedScale();
    Interpolated3 *interpolated3 = new Interpolated3();
    InvertColors *invertColors = new InvertColors();
    GrayScale *grayScale = new GrayScale();
    PopArt *popArt = new PopArt();
    Crazy *crazy = new Crazy();
    Merge *merge = new Merge();
    Append *append = new Append();
    Mask *mask = new Mask();
    Sepia *sepia = new Sepia();
    XRay *xray = new XRay();
    FlipHorizontal *fh = new FlipHorizontal();
    FlipVertical *fv = new FlipVertical();
    MakeIt3d *img3d = new MakeIt3d();

    command_map[cropper->name] = cropper;
    command_map[resize->name]  = resize;
    command_map[scale->name]   = scale;
    command_map[rotate->name]  = rotate;
    command_map[rotate2->name]  = rotate2;
    command_map[mirror->name]  = mirror;
    command_map[lightness->name]  = lightness;
    command_map[interpolated->name] = interpolated;
    command_map[interpolated3->name] = interpolated3;
    command_map[invertColors->name] = invertColors;
    command_map[grayScale->name]  = grayScale;
    command_map[popArt->name]  = popArt;
    command_map[crazy->name]  = crazy;
    command_map[merge->name]  = merge;
    command_map[append->name]  = append;
    command_map[mask->name]  = mask;
    command_map[sepia->name]  = sepia;
    command_map[xray->name]  = xray;
    command_map[fh->name]  = fh;
    command_map[fv->name]  = fv;
    command_map[img3d->name]  = img3d;
}


QMap<Command *, QStringList> retrieve_tasks(QStringList args)
{
    QMap<Command *, QStringList> tasks;

    if ( args.size() > 1 )
    {
        QString cmd_name = args[1];

        if (command_map.contains(cmd_name))
        {
            Command *cmd = command_map[cmd_name];
            QStringList cmd_args;

            for (int i = 2; i < args.size(); i++)
            {
                cmd_args << args[i];
            }

            tasks[cmd] = cmd_args;
        }
    }

    return tasks;
}

void print_usage()
{
    QMapIterator<QString, Command *>i(command_map);

    qout << "cropper usage: " << endl;
    qout << "\t<command> [params]" << endl;

    while(i.hasNext())
    {
        i.next();

        qout << "\t " << i.key() << ": " << i.value()->usage() << endl;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    init_command_map();

    QMap<Command *, QStringList> tasks = retrieve_tasks(a.arguments());

    if (tasks.isEmpty())
    {
        print_usage();
        a.exit();
    }

    QMapIterator<Command *, QStringList> i(tasks);

    while(i.hasNext())
    {
        i.next();

        try
        {
            i.key()->run(i.value());
        }
        catch (CommandException& cme)
        {
            qout << "Exception running command " << i.key()->name << ": " << cme.message  << "." << endl;

            qout << i.key()->name << " usage:" << endl << "\t " << i.key()->usage() << endl;
        }
    }

    a.exit();

    return 0;
}
