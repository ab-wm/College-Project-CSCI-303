#!/bin/bash -x

#IMPORTANT: this script must be executed on the "MSYS2 MinGW" terminal (as opposed to the Windows terminal)

#NOTE: this BASH script compiles/runs the code through the command line, rather than through CLion or any other IDE

#create directory
mkdir -p build-win-msys2

#go to directory
cd build-win-msys2

#run cmake to check if the compiler, C++ libraries, etc. are correct in your system and generate the necessary files to compile the code
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=mingw32-make.exe -DCMAKE_C_COMPILER=gcc.exe -DCMAKE_CXX_COMPILER=g++.exe -G "CodeBlocks - MinGW Makefiles" ../

#run cmake to compile the code and build the executable
cmake --build ./

#run the program (i.e., the executable) now
./hashing.exe
