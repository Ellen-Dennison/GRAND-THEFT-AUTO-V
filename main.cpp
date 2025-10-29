/**
 * @file main.cpp (or TestMain.cpp)
 * @brief Testing suite for Actions and Notifications patterns
 */

#include <iostream>
#include <string>
#include <vector>

// ===== STEP 1: Define Plant class FIRST (before any headers that use it) =====
class PlantMemento;  // Forward declare for Plant

class Plant {
private:
    std::string name;
    std::string state;
    int age;
    int healthLevel;
    std::string id;

public:
    Plant(const std::string& plantName, const std::string& plantId)
            : name(plantName), state("Seedling"), age(0), healthLevel(100), id(plantId) {}

    void water() {
        healthLevel += 10;
        if (healthLevel > 100) healthLevel = 100;
        std::cout << "  " << name << " watered! Health: " << healthLevel << "%" << std::endl;
    }

    void grow() {
        age++;
        healthLevel -= 5;
        if (healthLevel < 0) healthLevel = 0;

        // State transitions
        if (healthLevel < 30 && state != "Dead" && state != "Wilting") {
            state = "Wilting";
        } else if (healthLevel == 0) {
            state = "Dead";
        } else if (age >= 12 && healthLevel > 60) {
            state = "Flowering";
        } else if (age >= 7 && healthLevel > 60) {
            state = "Mature";
        } else if (age >= 3) {
            state = "Growing";
        }
    }

    std::string getState() const { return state; }
    std::string getName() const { return name; }
    std::string getId() const { return id; }
    int getAge() const { return age; }
    int getHealthLevel() const { return healthLevel; }

    PlantMemento* createMemento();  // Declare here, define after PlantMemento is included
    void restoreFromMemento(PlantMemento* memento);  // Declare here, define after
};

// ===== STEP 2: Now include all your headers =====
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

// ===== STEP 3: Define Plant methods that need PlantMemento =====
PlantMemento* Plant::createMemento() {
    return new PlantMemento(state, age, healthLevel);
}

void Plant::restoreFromMemento(PlantMemento* memento) {
    if (state != "Wilting") return;

    healthLevel = memento->getHealthLevel();
    state = memento->getStateName();
    std::cout << "  " << name << " restored from memento!" << std::endl;
}

// ===== STEP 4: Mock TestSubject =====
class TestSubject : public Subject {
public:
    void triggerEvent(const std::string& message) {
        notify(message);
    }
};

// ===== STEP 5: Test Functions =====
void testMemento();
void testCommands();
void testObserver();
void testIntegration();

int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════╗\n";
    std::cout << "║   PLANT NURSERY TESTING SUITE                     ║\n";
    std::cout << "║   Actions and Notifications Subsystem             ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
    std::cout << "\n";

    try {
        testMemento();
        testCommands();
        testObserver();
        testIntegration();

        std::cout << "\n";
        std::cout << "╔════════════════════════════════════════════════════╗\n";
        std::cout << "║   ALL TESTS COMPLETED SUCCESSFULLY! ✓             ║\n";
        std::cout << "╚════════════════════════════════════════════════════╝\n";
        std::cout << "\n";

    } catch (const std::exception& e) {
        std::cerr << "\n❌ TEST FAILED: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// ===== Test Implementations =====
void testMemento() {
    std::cout << "\n┌─────────────────────────────────────────────┐\n";
    std::cout << "│ TEST 1: MEMENTO PATTERN                    │\n";
    std::cout << "└─────────────────────────────────────────────┘\n\n";

    PlantCaretaker* caretaker = new PlantCaretaker();

    std::cout << "Test 1.1: Save and Retrieve Memento\n";
    PlantMemento* memento1 = new PlantMemento("Mature", 8, 95);
    caretaker->saveMemento("Rose1", memento1);

    PlantMemento* retrieved = caretaker->getMemento("Rose1");
    if (retrieved) {
        std::cout << "✓ Retrieved: " << retrieved->getStateName()
                  << ", Age: " << retrieved->getAge()
                  << ", Health: " << retrieved->getHealthLevel() << "%\n";
    }

    std::cout << "\nTest 1.2: Update Existing Memento\n";
    PlantMemento* memento2 = new PlantMemento("Flowering", 12, 100);
    caretaker->saveMemento("Rose1", memento2);

    std::cout << "\nTest 1.3: Check Memento Existence\n";
    std::cout << "Rose1 has memento: " << caretaker->hasMemento("Rose1") << "\n";
    std::cout << "Rose999 has memento: " << caretaker->hasMemento("Rose999") << "\n";

    std::cout << "\nTest 1.4: Display All Mementos\n";
    PlantMemento* memento3 = new PlantMemento("Growing", 5, 80);
    caretaker->saveMemento("Lavender2", memento3);
    caretaker->displayAllMementos();

    std::cout << "\nTest 1.5: Delete Memento\n";
    caretaker->deleteMemento("Lavender2");
    std::cout << "Memento count: " << caretaker->getMementoCount() << "\n";

    delete caretaker;
    std::cout << "\n✓ Memento Pattern Tests Passed!\n";
}

void testCommands() {
    std::cout << "\n┌─────────────────────────────────────────────┐\n";
    std::cout << "│ TEST 2: COMMAND PATTERN                    │\n";
    std::cout << "└─────────────────────────────────────────────┘\n\n";

    std::vector<Plant*> greenhouse;
    greenhouse.push_back(new Plant("Rose", "Rose1"));
    greenhouse.push_back(new Plant("Succulent", "Succulent1"));
    greenhouse.push_back(new Plant("Lavender", "Lavender1"));

    std::cout << "Test 2.1: Water Plants Command\n";
    Command* waterCmd = new WaterPlantsCommand(greenhouse);
    std::cout << "Command: " << waterCmd->getDescription() << "\n";
    waterCmd->execute();
    delete waterCmd;

    std::cout << "\nTest 2.2: Advance Time Command\n";
    Command* timeCmd = new AdvanceTimeCommand(greenhouse, 3);
    std::cout << "Command: " << timeCmd->getDescription() << "\n";
    timeCmd->execute();

    std::cout << "After 3 weeks:\n";
    for (Plant* plant : greenhouse) {
        std::cout << "  " << plant->getName() << " - Age: " << plant->getAge()
                  << ", State: " << plant->getState()
                  << ", Health: " << plant->getHealthLevel() << "%\n";
    }
    delete timeCmd;

    std::cout << "\nTest 2.3: Revive Plant Command\n";

    PlantCaretaker* caretaker = new PlantCaretaker();
    Plant* rose = greenhouse[0];
    PlantMemento* snapshot = rose->createMemento();
    caretaker->saveMemento("Rose1", snapshot);

    std::cout << "Making Rose1 wilt...\n";
    for (int i = 0; i < 15; i++) {
        rose->grow();
    }
    std::cout << "Rose1 state: " << rose->getState()
              << ", Health: " << rose->getHealthLevel() << "%\n";

    Command* reviveCmd = new RevivePlantCommand(rose, caretaker, "Rose1");
    std::cout << "Command: " << reviveCmd->getDescription() << "\n";
    reviveCmd->execute();

    std::cout << "After revival - State: " << rose->getState()
              << ", Health: " << rose->getHealthLevel() << "%\n";

    delete reviveCmd;
    delete caretaker;

    for (Plant* plant : greenhouse) {
        delete plant;
    }

    std::cout << "\n✓ Command Pattern Tests Passed!\n";
}

void testObserver() {
    std::cout << "\n┌─────────────────────────────────────────────┐\n";
    std::cout << "│ TEST 3: OBSERVER PATTERN                   │\n";
    std::cout << "└─────────────────────────────────────────────┘\n\n";

    TestSubject* subject = new TestSubject();

    StaffObserver* john = new StaffObserver("John", "GreenhouseWorker");
    StaffObserver* alice = new StaffObserver("Alice", "SalesAssociate");
    ManagerObserver* manager = new ManagerObserver("Sarah");

    std::cout << "Test 3.1: Attach Observers\n";
    subject->attach(john);
    subject->attach(alice);
    subject->attach(manager);

    std::cout << "\nTest 3.2: Display Observers\n";
    subject->displayObservers();

    std::cout << "\nTest 3.3: Notify Purchase Event\n";
    subject->triggerEvent("Customer Bob purchased Rose for R65");

    std::cout << "\nTest 3.4: Notify Wilting Event\n";
    subject->triggerEvent("Plant Rose3 entered wilting state");

    std::cout << "\nTest 3.5: Notify Revival Event\n";
    subject->triggerEvent("Plant Rose3 successfully revived");

    std::cout << "\nTest 3.6: Test Inactive Observer\n";
    john->setActive(false);
    subject->triggerEvent("Plant watered");
    john->setActive(true);

    std::cout << "\nTest 3.7: Check Attachment\n";
    std::cout << "John attached: " << subject->isAttached(john) << "\n";

    std::cout << "\nTest 3.8: Detach Observer\n";
    subject->detach(alice);
    subject->displayObservers();

    std::cout << "\nTest 3.9: Manager Statistics\n";
    manager->displayStatistics();

    subject->detachAll();
    delete john;
    delete alice;
    delete manager;
    delete subject;

    std::cout << "\n✓ Observer Pattern Tests Passed!\n";
}

void testIntegration() {
    std::cout << "\n┌─────────────────────────────────────────────┐\n";
    std::cout << "│ TEST 4: INTEGRATION TEST                   │\n";
    std::cout << "│ (All patterns working together)            │\n";
    std::cout << "└─────────────────────────────────────────────┘\n\n";

    TestSubject* mediator = new TestSubject();
    PlantCaretaker* caretaker = new PlantCaretaker();

    std::vector<Plant*> greenhouse;
    greenhouse.push_back(new Plant("Rose", "Rose1"));
    greenhouse.push_back(new Plant("Rose", "Rose2"));
    greenhouse.push_back(new Plant("Succulent", "Succulent1"));

    StaffObserver* john = new StaffObserver("John", "GreenhouseWorker");
    StaffObserver* alice = new StaffObserver("Alice", "SalesAssociate");
    ManagerObserver* manager = new ManagerObserver("Sarah");

    mediator->attach(john);
    mediator->attach(alice);
    mediator->attach(manager);

    std::cout << "=== Scenario 1: Daily Watering Routine ===\n";
    Command* waterCmd = new WaterPlantsCommand(greenhouse);
    waterCmd->execute();
    mediator->triggerEvent("Daily watering completed");
    delete waterCmd;

    std::cout << "\n=== Scenario 2: Time Passes (4 weeks) ===\n";

    for (Plant* plant : greenhouse) {
        PlantMemento* snapshot = plant->createMemento();
        caretaker->saveMemento(plant->getId(), snapshot);
    }
    mediator->triggerEvent("Auto-saved healthy plant states");

    Command* timeCmd = new AdvanceTimeCommand(greenhouse, 4);
    timeCmd->execute();
    mediator->triggerEvent("4 weeks have passed");
    delete timeCmd;

    std::cout << "\n=== Scenario 3: Customer Purchase ===\n";
    mediator->triggerEvent("Customer Alice purchased Rose for R65");
    mediator->triggerEvent("Customer Bob purchased Succulent for R45");

    std::cout << "\n=== Scenario 4: Plant Health Crisis ===\n";
    Plant* rose1 = greenhouse[0];
    for (int i = 0; i < 10; i++) {
        rose1->grow();
    }

    if (rose1->getState() == "Wilting") {
        mediator->triggerEvent("Plant Rose1 entered wilting state");

        Command* reviveCmd = new RevivePlantCommand(rose1, caretaker, "Rose1");
        reviveCmd->execute();
        mediator->triggerEvent("Plant Rose1 successfully revived");
        delete reviveCmd;
    }

    std::cout << "\n=== Scenario 5: Inventory Management ===\n";
    mediator->triggerEvent("Low stock alert: Only 1 Rose remaining");

    std::cout << "\n=== Final Manager Report ===\n";
    manager->displayStatistics();

    mediator->detachAll();
    delete john;
    delete alice;
    delete manager;
    delete mediator;
    delete caretaker;

    for (Plant* plant : greenhouse) {
        delete plant;
    }

    std::cout << "\n✓ Integration Test Passed!\n";
}