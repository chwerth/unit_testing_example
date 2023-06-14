cmake_minimum_required(VERSION 3.12)
project(unit_testing_example VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest)
include_directories(googletest/include)
include_directories(googlemock/include)

include(CTest)
include(GoogleTest)
enable_testing()

add_library(shapes shapes.cpp)

add_executable(shape_app main.cpp)

target_link_libraries(shape_app shapes)

add_executable(shape_tests shape_tests.cpp)

target_link_libraries(shape_tests shapes gtest gmock)

gtest_discover_tests(shape_tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
