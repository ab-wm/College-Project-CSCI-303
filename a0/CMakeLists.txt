cmake_minimum_required(VERSION 3.30)
project(a0_figures)

set(CMAKE_CXX_STANDARD 20)

add_executable(a0_figures main.cpp
        figures/src/utilities/figures/TriangleDraw.cpp
        figures/src/utilities/exception/InputPositive.cpp
        figures/include/utilities/exception/ExceptionCheck.h
)
