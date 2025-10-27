
#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command(){}
    virtual void execute() = 0;
    virtual void undo();//new
    virtual std::string getDescription() const{
        return "Command";
    }

    virtual bool isUndoable() const {
        return false;
    }

};


#endif //GRAND_THEFT_AUTO_V_COMMAND_H