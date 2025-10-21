

#ifndef GRAND_THEFT_AUTO_V_REVIVEPLANTCOMMAND_H
#define GRAND_THEFT_AUTO_V_REVIVEPLANTCOMMAND_H


#include "Command.h"
#include <string>

class Plant;
class PlantCaretaker;

class RevivePlantCommand : public Command{
private:
    Plant* plant;
    PlantCaretaker* caretaker;
    std::string plantID;

public:
    RevivePlantCommand(Plant* p, PlantCaretaker* c, const std::string& id);
    void execute() override;



};


#endif //GRAND_THEFT_AUTO_V_REVIVEPLANTCOMMAND_H
