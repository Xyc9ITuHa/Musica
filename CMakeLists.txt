cmake_minimum_required(VERSION 3.30)
project(wellwell)

set(CMAKE_CXX_STANDARD 20)

add_executable(wellwell main.cpp
        Instruments.cpp
        Instruments.h)
