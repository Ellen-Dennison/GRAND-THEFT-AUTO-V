
#ifndef GRAND_THEFT_AUTO_V_COMMAND_H
#define GRAND_THEFT_AUTO_V_COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command(){}
    virtual void execute() = 0;
    virtual void undo() =0;
    virtual std::string getDescription() const =0;

};


#endif //GRAND_THEFT_AUTO_V_COMMAND_H
