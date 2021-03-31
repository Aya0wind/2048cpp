cmake_minimum_required(VERSION 3.10)
project(2048)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
add_executable(2048 ${SOURCES})
target_include_directories(2048 PRIVATE ${INCLUDE_DIR})