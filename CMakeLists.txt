cmake_minimum_required(VERSION 3.7.2)
project(neural_network_scratch)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

add_executable(neural_network_scratch main.cpp ${SOURCES} ${HEADERS} )
