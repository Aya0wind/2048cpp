cmake_minimum_required(VERSION 3.20)
project(2048)
set(CMAKE_CXX_STANDARD 17)

# if(CMAKE_HOST_WIN32)
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# endif()

# Setup vcpkg
# if not define CMAKE_TOOLCHAIN_FILE, use VCPKG_ROOT to set it
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if(NOT EXISTS ${VCPKG_ROOT})
        message(FATAL_ERROR "vcpkg not found, please set VCPKG_ROOT or CMAKE_TOOLCHAIN_FILE")
    endif()

    set(CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
endif()

message(STATUS "VCPKG_ROOT: ${VCPKG_ROOT}")
message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
set(VCPKG_BUILD on)
set(VCPKG_FEATURE_FLAGS manifests)
set(VCPKG_BUILD_TYPE ${CMAKE_BUILD_TYPE})

find_package(fmt REQUIRED)

# add source files
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
add_executable(2048 ${SOURCES})
target_include_directories(2048 PRIVATE ${INCLUDE_DIR})
target_link_libraries(2048 PRIVATE fmt::fmt-header-only)

# gtest setup
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include(GoogleTest)

# gtest test files

# # test1
add_executable(test1 test/test1.cpp)
target_link_libraries(test1
    PRIVATE
    GTest::gtest
    GTest::gtest_main
)
gtest_discover_tests(test1)
