cmake_minimum_required(VERSION 3.10)
project(2048)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
add_executable(2048 ${SOURCES})
target_include_directories(2048 PRIVATE ${INCLUDE_DIR})

# gtest setup
if(CMAKE_HOST_WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

enable_testing()
add_subdirectory(third-party/gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include(GoogleTest)

# gtest test files

# # test1
add_executable(test1 test/test1.cpp)
target_link_libraries(test1
    PRIVATE
    gtest
    gtest_main
)
gtest_discover_tests(test1)

# # test2
add_executable(test2 test/test2.cpp)
target_link_libraries(test2
    PRIVATE
    gtest
    gtest_main
)
gtest_discover_tests(test2)

# # test3
add_executable(test3 test/test3.cpp)
target_link_libraries(test3
    PRIVATE
    gtest
    gtest_main
)
gtest_discover_tests(test3)
