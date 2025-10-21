cmake_minimum_required(VERSION 4.0)
project(GRAND_THEFT_AUTO_V)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GRAND_THEFT_AUTO_V
        NurseryMediator.cpp
        NurseryMediator.h
        Subject.h
        Customer.cpp
        Customer.h
        StaffWorkflow.cpp
        StaffWorkflow.h
        GreenhouseWorker.cpp
        GreenhouseWorker.h
        SalesAssociate.cpp
        SalesAssociate.h
        Subject.cpp
)
