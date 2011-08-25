#include <QtGui/QApplication>
#include <QDebug>
#include <QMap>
#include <QStringList>
#include <QList>

#include "command.h"
#include "cropper.h"
#include "resize.h"

QMap<QString, Command*> command_map;

void init_command_map()
{
    Cropper *cropper = new Cropper();
    Resize *resize = new Resize();

    command_map[cropper->name] = cropper;
    command_map[resize->name] = resize;
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
        i.key()->run(i.value());
    }

    a.exit();

    return 0;
}
