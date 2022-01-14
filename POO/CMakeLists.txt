cmake_minimum_required(VERSION 3.16)
project(POO)

set(CMAKE_CXX_STANDARD 14)

add_executable(POO main.cpp Ilha.cpp Ilha.h Interface.cpp Interface.h Jogada.cpp Jogada.h Player.cpp Player.h Worker.cpp Worker.h Building.cpp Building.h Finance.cpp Finance.h)
