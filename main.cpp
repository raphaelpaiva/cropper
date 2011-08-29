#include <QtGui/QApplication>
#include <QDebug>
#include <QMap>
#include <QStringList>
#include <QList>

#include "command/command.h"
#include "command/commandexception.h"
#include "command/cropper.h"
#include "command/resize.h"
#include "command/scale.h"

QMap<QString, Command*> command_map;

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    init_command_map();

    QMap<Command *, QStringList> tasks = retrieve_tasks(a.arguments());

    QMapIterator<Command *, QStringList> i(tasks);

    while(i.hasNext())
    {
        i.next();
        qDebug() << i.key()->name << i.value();

        try
        {
            i.key()->run(i.value());
        }
        catch (CommandException& cme)
        {
            qDebug() << "Exception running command: " << cme.message;
        }
    }

    a.exit();

    return 0;
}
