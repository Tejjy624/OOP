cmake_minimum_required(VERSION 3.14)
project(Battleship)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BattleShip
        AiPlayer.cpp
        AiPlayer.h
        Attack.cpp
        Attack.h
        AttackResult.cpp
        AttackResult.h
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        CheatingAI.cpp
        CheatingAI.h
        CMakeLists.txt
        Controller.cpp
        Controller.h
        GameAttributes.cpp
        GameAttributes.h
        HumanPlayer.cpp
        HumanPlayer.h
        HuntDestroyAI.cpp
        HuntDestroyAI.h
        main.cpp
        Model.cpp
        Model.h
        Move.cpp
        Move.h
        Player.cpp
        Player.h
        PlayerConfiguration.cpp
        PlayerConfiguration.h
        RandomAI.cpp
        RandomAI.h
        ShipPlacement.cpp
        ShipPlacement.h
        StandardView.cpp
        StandardView.h
        Utility.cpp
        Utility.h
        View.cpp
        View.h)
