#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Plant.h"
#include "WaterPlantsCommand.h"
#include "AdvanceTimeCommand.h"
#include "Subject.h"
#include "ManagerObserver.h"
#include "StaffObserver.h"
#include "Flower.h"

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
    Plant* p = new Flower("Rose",50.0);

    std::vector<Plant*> plants = {p};
    double oldHealth = p->getHealth();

    WaterPlantsCommand cmd(plants);
    CHECK_NOTHROW(cmd.execute());

    CHECK(p->getHealth() >= oldHealth);

    delete p;
}

TEST_CASE("AdvanceTimeCommand correctly simulates time passage"){
    Plant* p = new Flower("Tulip",30.0);
    std::vector<Plant*> plants = {p};

    double oldHealth = p->getHealth();

    AdvanceTimeCommand cmd(plants, 1);
    CHECK_NOTHROW(cmd.execute());

    CHECK(p->getHealth() <= oldHealth);

    delete p;
}