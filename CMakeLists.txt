cmake_minimum_required(VERSION 3.10)
project(GRAND-THEFT-AUTO-V)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
add_executable(GRAND-THEFT-AUTO-V
        src/AdvanceTimeCommand.cpp
        src/AdvanceTimeCommand.h
        src/BiWeeklyWateringStrategy.cpp
        src/BiWeeklyWateringStrategy.h
        src/Command.h
        src/DailyWateringStrategy.cpp
        src/DailyWateringStrategy.h
        src/DeadState.cpp
        src/DeadState.h
        src/DecorativePotDecorator.cpp
        src/DecorativePotDecorator.h
        src/Flower.cpp
        src/Flower.h
        src/FlowerFactory.cpp
        src/FlowerFactory.h
        src/FloweringState.cpp
        src/FloweringState.h
        src/GiftWrappingDecorator.cpp
        src/GiftWrappingDecorator.h
        src/GrowingState.cpp
        src/GrowingState.h
        src/Herb.cpp
        src/Herb.h
        src/HerbFactory.cpp
        src/HerbFactory.h
        src/main.cpp
        src/ManagerObserver.cpp
        src/ManagerObserver.h
        src/MatureState.cpp
        src/MatureState.h
        src/Observer.h
        src/Plant.cpp
        src/Plant.h
        src/PlantCaretaker.cpp
        src/PlantCaretaker.h
        src/PlantDecorator.cpp
        src/PlantDecorator.h
        src/PlantFactory.cpp
        src/PlantFactory.h
        src/PlantMemento.cpp
        src/PlantMemento.h
        src/PlantState.cpp
        src/PlantState.h
        src/RevivePlantCommand.cpp
        src/RevivePlantCommand.h
        src/SeedlingState.cpp
        src/SeedlingState.h
        src/StaffObserver.cpp
        src/StaffObserver.h
        src/Subject.cpp
        src/Subject.h
        src/Succulent.cpp
        src/Succulent.h
        src/SucculentFactory.cpp
        src/SucculentFactory.h
        src/Tree.cpp
        src/Tree.h
        src/TreeFactory.cpp
        src/TreeFactory.h
        src/WaterPlantsCommand.cpp
        src/WaterPlantsCommand.h
        src/WeeklyWateringStrategy.cpp
        src/WeeklyWateringStrategy.h
        src/WiltingState.cpp
        src/WiltingState.h


)

