cmake_minimum_required(VERSION 3.27)
project(Projeto_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto_2 main.cpp
        Headers/structs.h
        Headers/AirportListHandler.h
        AirportListHandler.cpp
        Headers/init_planes_people.h
        init_planes_people.cpp
        Headers/Aux_functions.h
        Aux_functions.cpp
        Headers/Menus.h
        Menus.cpp)
