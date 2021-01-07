cmake_minimum_required(VERSION 3.14)
project(ConnectN)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConnectN main.cpp ConnectN.cpp ConnectN.h Model.cpp Model.h View.cpp View.h Player.cpp Player.h Board.cpp Board.h Move.cpp Move.h ValidatedReads.cpp ValidatedReads.h GameStatus.h)
target_compile_options(ConnectN PRIVATE -Wall -Werror)
