
#include "RevivePlantCommand.h"
//#include "Plant.h"
//#include "PlantCaretaker.h"

RevivePlantCommand::RevivePlantCommand(Plant* p, PlantCaretaker* c, const std::string& id) : plant(p), caretaker(c), plantID(id){

}
void RevivePlantCommand::execute(){

}