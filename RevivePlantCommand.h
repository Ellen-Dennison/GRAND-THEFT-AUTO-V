

#ifndef REVIVEPLANTCOMMAND_H
#define REVIVEPLANTCOMMAND_H


#include "Command.h"
#include "Plant.h"
#include "PlantCaretaker.h"
#include <string>



class RevivePlantCommand : public Command{
private:
    Plant* plant;
    PlantCaretaker* caretaker;
    std::string plantIdentifier;

public:
    RevivePlantCommand(Plant* targetPlant, PlantCaretaker* plantCaretaker, const std::string& id);
    ~RevivePlantCommand();
    void execute() override;
    std::string getDescription() const override;

    bool isUndoable() const override;
    std::string getPlant() const;

    bool canRevive() const;



};


#endif //REVIVEPLANTCOMMAND_H