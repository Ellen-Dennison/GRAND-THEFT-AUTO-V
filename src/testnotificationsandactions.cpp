#include <iostream>
#include <vector>
#include "Flower.h"
#include "Succulent.h"
#include "Herb.h"
#include "Tree.h"
#include "PlantMemento.h"
#include "PlantCaretaker.h"
#include "Command.h"
#include "WaterPlantsCommand.h"
#include "AdvanceTimeCommand.h"
#include "RevivePlantCommand.h"
#include "Observer.h"
#include "Subject.h"
#include "StaffObserver.h"
#include "ManagerObserver.h"
#include "WiltingState.h"

class TestSubject : public Subject {
public:
    void triggerEvent(const std::string& message) {
        notify(message);
    }
};

void printSeparator(const std::string& title) {
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << ">>> " << title << " <<<\n";
    std::cout << "------------------------------------------------------------\n\n";
}



void testMementoPattern() {
    printSeparator("TEST 1: MEMENTO PATTERN");

    PlantCaretaker* caretaker = new PlantCaretaker();

    // Create and save mementos
    PlantMemento* m1 = new PlantMemento("Mature", 8, 95);
    PlantMemento* m2 = new PlantMemento("Growing", 5, 80);
    PlantMemento* m3 = new PlantMemento("Flowering", 12, 90);

    caretaker->saveMemento("Rose1", m1);
    caretaker->saveMemento("Succulent1", m2);
    caretaker->saveMemento("Lavender1", m3);

    std::cout << "\nMementos saved. Count: " << caretaker->getMementoCount() << std::endl;
    caretaker->displayAllMementos();

    // Retrieve and display one
    std::cout << "\nRetrieving memento for Rose1..." << std::endl;
    PlantMemento* retrieved = caretaker->getMemento("Rose1");
    if (retrieved) retrieved->display();

    // Update and delete
    caretaker->deleteMemento("Succulent1");
    std::cout << "\nAfter deletion, count: " << caretaker->getMementoCount() << std::endl;

    delete caretaker;
    std::cout << "\n✓ Memento Pattern Test Complete!" << std::endl;
}


void testCommandPattern() {
    printSeparator("TEST 2: COMMAND PATTERN");

    std::vector<Plant*> greenhouse;
    greenhouse.push_back(new Flower("Rose", 65.0));
    greenhouse.push_back(new Succulent("Aloe Vera", 45.0));
    greenhouse.push_back(new Herb("Lavender", 50.0));

    std::cout << "Created " << greenhouse.size() << " plants in greenhouse\n" << std::endl;

    Command* waterCmd = new WaterPlantsCommand(greenhouse);
    std::cout << "--- Executing WaterPlantsCommand ---" << std::endl;
    waterCmd->execute();
    delete waterCmd;

    Command* timeCmd = new AdvanceTimeCommand(greenhouse, 2);
    std::cout << "\n--- Executing AdvanceTimeCommand ---" << std::endl;
    timeCmd->execute();
    delete timeCmd;

    PlantCaretaker* caretaker = new PlantCaretaker();
    Plant* testPlant = greenhouse[0];
    PlantMemento* saved = testPlant->createMemento();
    caretaker->saveMemento(testPlant->getName(), saved);

    testPlant->setState(new WiltingState());
    testPlant->adjustHealth(-70);
    std::cout << testPlant->getName() << " is wilting. Health: " << testPlant->getHealth() << "%\n";

    Command* reviveCmd = new RevivePlantCommand(testPlant, caretaker, testPlant->getName());
    reviveCmd->execute();
    delete reviveCmd;

    for (Plant* p : greenhouse) delete p;
    delete caretaker;

    std::cout << "\n✓ Command Pattern Test Complete!" << std::endl;
}

void testObserverPattern() {
    printSeparator("TEST 3: OBSERVER PATTERN");

    TestSubject* subject = new TestSubject();

    Observer* john = new StaffObserver("John", "GreenhouseWorker");
    Observer* alice = new StaffObserver("Alice", "SalesAssociate");
    Observer* manager = new ManagerObserver("Sarah");

    subject->attach(john);
    subject->attach(alice);
    subject->attach(manager);

    subject->displayObservers();

    std::cout << "\n--- Event 1: Purchase ---\n";
    subject->triggerEvent("Customer Alice purchased Rose for R65");

    std::cout << "\n--- Event 2: Wilting ---\n";
    subject->triggerEvent("Plant Rose entered wilting state");

    std::cout << "\n--- Event 3: Revival ---\n";
    subject->triggerEvent("Plant Rose successfully revived");

    ((ManagerObserver*)manager)->displayStatistics();

    subject->detachAll();
    delete john;
    delete alice;
    delete manager;
    delete subject;

    std::cout << "\n✓ Observer Pattern Test Complete!" << std::endl;
}




void testIntegration() {
    printSeparator("TEST 4: INTEGRATION TEST");

    std::vector<Plant*> greenhouse;
    greenhouse.push_back(new Flower("Rose", 65.0));
    greenhouse.push_back(new Succulent("Aloe Vera", 45.0));

    PlantCaretaker* caretaker = new PlantCaretaker();
    TestSubject* subject = new TestSubject();
    Observer* worker = new StaffObserver("John", "GreenhouseWorker");
    Observer* manager = new ManagerObserver("Sarah");
    subject->attach(worker);
    subject->attach(manager);

    std::cout << "=== Day 1: Care Routine ===\n";
    Command* waterCmd = new WaterPlantsCommand(greenhouse);
    waterCmd->execute();
    delete waterCmd;

    for (Plant* p : greenhouse)
        caretaker->saveMemento(p->getName(), p->createMemento());

    Command* timeCmd = new AdvanceTimeCommand(greenhouse, 2);
    timeCmd->execute();
    delete timeCmd;

    Plant* rose = greenhouse[0];
    rose->setState(new WiltingState());
    rose->adjustHealth(-70);
    subject->triggerEvent("Plant " + rose->getName() + " entered wilting state");

    Command* reviveCmd = new RevivePlantCommand(rose, caretaker, rose->getName());
    reviveCmd->execute();
    delete reviveCmd;

    ((ManagerObserver*)manager)->displayStatistics();

    for (Plant* p : greenhouse) delete p;
    delete caretaker;
    delete worker;
    delete manager;
    delete subject;

    std::cout << "\n✓ Integration Test Complete!" << std::endl;
}




int main() {
    std::cout << "\n---------------------------------------------------------------\n";
    std::cout << "         ACTIONS AND NOTIFICATIONS TEST SUITE             \n";
    std::cout << "----------------------------------------------------------------\n";

    try {
        testMementoPattern();
        testCommandPattern();
        testObserverPattern();
        testIntegration();

        printSeparator("ALL TESTS PASSED! ✓");
        std::cout << "All systems are functioning as expected!\n";

    } catch (const std::exception& e) {
        std::cerr << "\n❌ TEST FAILED: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
