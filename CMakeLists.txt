cmake_minimum_required(VERSION 3.0.0)
project(unit_testing_example VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 98)

include(CTest)
enable_testing()

add_executable(shape_app main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
