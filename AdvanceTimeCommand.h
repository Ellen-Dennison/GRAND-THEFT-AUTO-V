

#ifndef ADVANCETIMECOMMAND_H
#define ADVANCETIMECOMMAND_H
#include "Command.h"
#include "Plant.h"
#include <vector>
#include <string>


class AdvanceTimeCommand : public Command{
private:
    std::vector<Plant*>& plants;
    int weeks;

public:
    AdvanceTimeCommand(std::vector<Plant*>& plantCollection, int numWeeks=1);
    ~AdvanceTimeCommand();
    void execute() override;
    std::string getDescription() const override;

    bool isUndoable() const override;

    int getWeeks() const;
    void setWeeks(int numWeeks);

    int getPlantCount() const;



};


#endif //ADVANCETIMECOMMAND_H