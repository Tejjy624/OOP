cmake_minimum_required(VERSION 3.13)
project(RockPaperScissors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(RockPaperScissors main.cpp
        RockPaperScissors.cpp RockPaperScissors.h
        ExtraStringMethods.cpp ExtraStringMethods.h
        Contains.h ExtraRandomMethods.h)
target_compile_options(RockPaperScissors PRIVATE -Wall -Werror)
