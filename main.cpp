#include <iostream>

#include <QtGui/QApplication>
#include <QMap>
#include <QStringList>
#include <QList>
#include <QTextStream>

#include "command/command.h"
#include "command/commandexception.h"
#include "command/crop.h"
#include "command/resize.h"
#include "command/scale.h"

QMap<QString, Command*> command_map;
QTextStream qout(stdout);

void init_command_map()
{
    Cropper *cropper = new Cropper();
    Resize *resize   = new Resize();
    Scale  *scale    = new Scale();

    command_map[cropper->name] = cropper;
    command_map[resize->name] = resize;
    command_map[scale->name] = scale;
}

QMap<Command *, QStringList> retrieve_tasks(QStringList args)
{
    QMap<Command *, QStringList> tasks;
    for (int i = 1; i < args.size(); i++)
    {
        QString arg = args[i];

        if (command_map[arg])
        {
            Command *cmd = command_map[arg];
            QStringList param_list;

            i++;
            arg = args[i];
            while((!command_map.contains(arg)) && i < args.size())
            {
                arg = args[i];

                param_list.push_back(arg);

                i++;
            }

            tasks[cmd] = param_list;
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
            qout << "Exception running command: " << cme.message << endl;

            qout << i.key()->name << " usage:" << endl << "\t " << i.key()->usage() << endl;
        }
    }

    a.exit();

    return 0;
}
