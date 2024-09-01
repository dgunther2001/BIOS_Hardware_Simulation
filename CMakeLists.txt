cmake_minimum_required(VERSION 3.15)

project(BIOS_Sim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(include)
add_subdirectory(src)

add_executable(power src/power_on.cpp src/memory.cpp src/digital_signal.cpp src/logic_gates.cpp src/mem_cell.cpp src/ROM.cpp src/CPU.cpp)