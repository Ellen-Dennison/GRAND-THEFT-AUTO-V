cmake_minimum_required(VERSION 3.10)
project(GRAND-THEFT-AUTO-V)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
add_executable(GRAND-THEFT-AUTO-V
        AdvanceTimeCommand.cpp
        AdvanceTimeCommand.h
        BiWeeklyWateringStrategy.cpp
        BiWeeklyWateringStrategy.h
        Command.h
        DailyWateringStrategy.cpp
        DailyWateringStrategy.h
        DeadState.cpp
        DeadState.h
        Enums.h
        FloweringState.cpp
        FloweringState.h
        GrowingState.cpp
        GrowingState.h
        main.cpp
        ManagerObserver.cpp
        ManagerObserver.h
        MatureState.cpp
        MatureState.h
        Observer.h
        Plant.cpp
        Plant.h
        PlantCaretaker.cpp
        PlantCaretaker.h
        PlantMemento.cpp
        PlantMemento.h
        PlantState.cpp
        PlantState.h
        RevivePlantCommand.cpp
        RevivePlantCommand.h
        SeedlingState.cpp
        SeedlingState.h
        StaffObserver.cpp
        StaffObserver.h
        Subject.cpp
        Subject.h
        WateringStrategy.cpp
        WateringStrategy.h
        WaterPlantsCommand.cpp
        WaterPlantsCommand.h
        WeeklyWateringStrategy.cpp
        WeeklyWateringStrategy.h
        WiltingState.cpp
        WiltingState.h
)
