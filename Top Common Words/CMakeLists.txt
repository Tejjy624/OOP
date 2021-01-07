cmake_minimum_required(VERSION 3.13)
project(TopCommonWords LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(TopCommonWords main.cpp TopCommonWords.cpp TopCommonWords.h ExtraStringMethods.cpp ExtraStringMethods.h Contains.h)
target_compile_options(TopCommonWords PRIVATE -Wall -Werror)
