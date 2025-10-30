cmake_minimum_required(VERSION 3.10)
project(GRAND-THEFT-AUTO-V)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
add_executable(GRAND-THEFT-AUTO-V
        AdvanceTimeCommand.cpp
        AdvanceTimeCommand.h
        Command.h
        DecorativePotDecorator.cpp
        DecorativePotDecorator.h
        Flower.cpp
        Flower.h
        FlowerFactory.cpp
        FlowerFactory.h
        GiftWrappingDecorator.cpp
        GiftWrappingDecorator.h
        Herb.cpp
        Herb.h
        HerbFactory.cpp
        HerbFactory.h
        main.cpp
        ManagerObserver.cpp
        ManagerObserver.h
        Observer.h
        Plant.cpp
        Plant.h
        PlantCaretaker.cpp
        PlantCaretaker.h
        PlantFactory.cpp
        PlantFactory.h
        PlantMemento.cpp
        PlantMemento.h
        RevivePlantCommand.cpp
        RevivePlantCommand.h
        StaffObserver.cpp
        StaffObserver.h
        Subject.cpp
        Subject.h
        Succulent.cpp
        Succulent.h
        SucculentFactory.cpp
        SucculentFactory.h
        Tree.cpp
        Tree.h
        TreeFactory.cpp
        TreeFactory.h
        WaterPlantsCommand.cpp
        WaterPlantsCommand.h


)

