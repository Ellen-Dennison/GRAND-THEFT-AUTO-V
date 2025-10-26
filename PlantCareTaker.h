#ifndef PLANTCARETAKER_H
#define PLANTCARETAKER_H



#include "PlantMemento.h"
#include <map>
#include <string>




class PlantCaretaker{
private:
    std::map<std::string, PlantMemento*> mementos;

public:

    PlantCaretaker();
    ~PlantCaretaker();
    void saveMemento(const std::string& plantId, PlantMemento* memento);
    PlantMemento* getMemento(const std::string& plantId) const;
    bool hasMemento(const std::string& plantId) const;

    bool deleteMemento(const std::string& plantId);
    int getMementoCount() const;
    void clearAllMementos();
    void displayAllMementos() const;



};





#endif