cmake_minimum_required(VERSION 3.21)
project(_FakeArduinoHeaders)

set(CMAKE_CXX_STANDARD 14)

add_executable(_FakeArduinoHeaders main.cpp FakeArduino/FakeArduino.hpp FakeArduino/DigitalIO.hpp FakeArduino/AnalogIO.hpp FakeArduino/AdvancedIO.hpp FakeArduino/Timer.hpp FakeArduino/Math.hpp FakeArduino/Trigonometry.hpp FakeArduino/Characters.hpp FakeArduino/RandomNumbers.hpp FakeArduino/BitsArray.hpp FakeArduino/ExternalInterrupts.hpp FakeArduino/Interrupts.hpp FakeArduino/Communication.hpp FakeArduino/USB.hpp FakeArduino/Utilities.hpp)
