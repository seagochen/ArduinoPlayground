cmake_minimum_required(VERSION 3.20)
project(FakeArduinoHeaders LANGUAGES CXX)

# Set C++ 14 standard
set(CMAKE_CXX_STANDARD 17)

add_executable(fakeArduino main.cpp FakeArduino/Websocket.h)

target_include_directories(fakeArduino
        PUBLIC
        thirds/)

target_include_directories(fakeArduino
        PRIVATE
        FakeArduino/)


