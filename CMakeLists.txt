cmake_minimum_required(VERSION 3.15)
project(OurServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(OurServer main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h
        MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h Solver.cpp Solver.h StringReverser.cpp
        StringReverser.h)