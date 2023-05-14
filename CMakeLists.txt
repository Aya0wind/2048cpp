cmake_minimum_required(VERSION 3.20)
project(2048cpp)
set(CMAKE_CXX_STANDARD 17)
set(VCPKG_BUILD on)
set(VCPKG_FEATURE_FLAGS manifests)
set(VCPKG_BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME})

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
include(${CMAKE_TOOLCHAIN_FILE})

# Setup Packages
find_package(fmt CONFIG REQUIRED)
find_package(SqliteOrm CONFIG REQUIRED)

# Global link packege
link_libraries(sqlite_orm::sqlite_orm)

# add source files
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
add_executable(2048cpp ${SOURCES})
target_include_directories(2048cpp PRIVATE ${INCLUDE_DIR})
target_link_libraries(2048cpp PRIVATE fmt::fmt-header-only)

# gtest setup
find_package(GTest CONFIG REQUIRED)
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})
include(GoogleTest)

# # sqlite-orm-test
add_executable(sqlite-orm-test test/sqlite-orm-test.cpp)
target_link_libraries(sqlite-orm-test
    PRIVATE
    GTest::gtest
    GTest::gtest_main
)

target_include_directories(sqlite-orm-test PUBLIC ${INCLUDE_DIR})
set_target_properties(sqlite-orm-test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
gtest_discover_tests(sqlite-orm-test)
