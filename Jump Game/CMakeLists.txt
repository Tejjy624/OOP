cmake_minimum_required(VERSION 3.13)
project(JumpGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(JumpGame main.cpp VectorGame.cpp VectorGame.h)
add_compile_options(JumpGame -Wall -Werror)
