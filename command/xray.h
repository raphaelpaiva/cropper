#ifndef XRAY_H
#define XRAY_H

#include "command.h"

class XRay : public Command
{
public:
    XRay() {name = "xray";}
    void run(QStringList args) throw(CommandException);
    QString usage();
};

#endif // XRAY_H
