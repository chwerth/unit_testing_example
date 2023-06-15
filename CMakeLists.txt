cmake_minimum_required(VERSION 3.14)
project(unit_testing_example VERSION 0.1.0 LANGUAGES CXX)

# Ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)
add_subdirectory(apps)

enable_testing()
include(CTest)
add_subdirectory(tests)