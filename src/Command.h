
#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command(){}
    virtual void execute() = 0;
    virtual void undo() {
        }
    virtual std::string getDescription() const{
        return "Command";
    }

    virtual bool isUndoable() const {
        return false;
    }

};


#endif //COMMAND_H