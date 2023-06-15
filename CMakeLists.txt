cmake_minimum_required(VERSION 3.14)
project(unit_testing_example VERSION 0.1.0 LANGUAGES CXX)

# Ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(googletest)
include_directories(googletest/include)
include_directories(googlemock/include)

include(CTest)
include(GoogleTest)

add_library(shapes shapes.cpp)

add_executable(shape_app main.cpp)

target_link_libraries(shape_app shapes)

add_executable(shape_tests shape_tests.cpp)

target_link_libraries(shape_tests shapes gtest gmock)

gtest_discover_tests(shape_tests)
