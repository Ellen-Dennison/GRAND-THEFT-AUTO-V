#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Plant.h"
#include "WaterPlantsCommand.h"
#include "AdvanceTimeCommand.h"
#include "Subject.h"
#include "ManagerObserver.h"
#include "StaffObserver.h"

class TestPlant: public Plant
{
public:
    TestPlant(const std::string& name, const std::string& type, double health) : Plant(name, type, health) {}
    void grow() {}
    void water() {}
};

TEST_CASE("Observer notification system works correctly"){
    Subject subject;
    ManagerObserver manager("Alice");

    //initially no observers
    CHECK(subject.getObserverCount()==0);

    //attaching observer
    subject.attach(&manager);
    CHECK(subject.getObserverCount()==1);

    //notify observer
    CHECK_NOTHROW(subject.notify("Water all plants"));

    //detaching observer
    subject.detach(&manager);
    CHECK(subject.getObserverCount()==0);

}

TEST_CASE("WaterPlantCommand correctly waters a plant"){
    Plant* p = new TestPlant("Rose", "Flower", 50.0);
    double oldHealth = p->getHealth();

    WaterPlantsCommand cmd(p);
    CHECK_NOTHROW(cmd.execute());

    CHECK(p->getHealth() >= oldHealth);

    delete p;
}

TEST_CASE("AdvanceTimeCommand correctly simulates time passage"){
    Plant* p = new Flower("Tulip", "Flower", 30.0);
    double oldHealth = p->getHealth();

    AdvanceTimeCommand cmd(p);
    CHECK_NOTHROW(cmd.execute());

    CHECK(p->getHealth() <= oldHealth);

    delete p;
}