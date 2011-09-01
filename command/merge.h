#ifndef MERGE_H
#define MERGE_H

#include "command.h"

class Merge : public Command
{
public:
    Merge() {name = "merge";}

    void run(QStringList args) throw(CommandException);
    QString usage();
};



#endif // MERGE_H
