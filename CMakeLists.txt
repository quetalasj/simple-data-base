cmake_minimum_required(VERSION 3.21)
project(simple_data_base)

set(CMAKE_CXX_STANDARD 20)

add_executable(simple_data_base src/main.cpp src/DataBase.cpp src/DataBase.h src/Date.cpp src/Date.h src/Event.cpp src/Event.h src/InputParser.cpp src/InputParser.h)
