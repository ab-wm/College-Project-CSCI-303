#This CMAKE configuration file defines parameters required to compile/run the code

#cmake version
cmake_minimum_required(VERSION 3.10)

#project name (replace "cmake_base_project" with whatever name you want)
project(cmake_base_project)

#define c++ standard (don't change these variables)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#define the source code directories, "include" is for headers and "src" is for implementation
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

#define a list, called SRC_FILES, that finds and stores all the source code files within "include" and "src" directories
file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )

#include all the source code files to generate an executable (replace "cmake_base_project" with whatever name you want for the executable)
add_executable(cmake_base_project ${SRC_FILES})
