#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include <QString>

class CommandException
{
public:
    QString message;
    CommandException(QString message) : message(message) {}
};

#endif // COMMANDEXCEPTION_H
