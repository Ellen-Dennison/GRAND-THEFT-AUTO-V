cmake_minimum_required(VERSION 3.10)
project(GRAND-THEFT-AUTO-V)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)
add_executable(GRAND-THEFT-AUTO-V
        AdvanceTimeCommand.cpp
        AdvanceTimeCommand.h
        Command.h
        ManagerObserver.cpp
        ManagerObserver.h
        Observer.h
        PlantCaretaker.cpp
        PlantCaretaker.h
        PlantMemento.cpp
        PlantMemento.h
        RevivePlantCommand.cpp
        RevivePlantCommand.h
        StaffObserver.cpp
        StaffObserver.h
        Subject.cpp
        Subject.h
        WaterPlantsCommand.cpp
        WaterPlantsCommand.h


)
