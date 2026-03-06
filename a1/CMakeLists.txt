#cmake version
cmake_minimum_required(VERSION 3.10)

#project name
project(a1-program)

#define c++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#define source directories, "include" is for headers and "src" is for implementation
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

#define a list, called SRC_FILES, that stores all source code files within "include" and "src"
file(GLOB_RECURSE SRC_FILES
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )

#include all source code files to generate an executable
add_executable(a1-program ${SRC_FILES} )

#this line links the compiled code with the libalgos... library
#replace [os] with:
#   win (Windows users)
#   ubuntu (Ubuntu/Linux users)
#   mac-x86-64-clang (Mac OS users with an Intel CPU and using CLang as compiler)
#   mac-arm64-clang (Mac OS users with an M1/M2 CPU and using CLang as compiler)
#   mac-arm64-gcc (Mac OS users with an M1/M2 CPU and using GCC as compiler)
target_link_libraries(a1-program "${PROJECT_SOURCE_DIR}/lib/libalgos-ubuntu.a")


