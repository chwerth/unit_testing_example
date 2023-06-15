add_subdirectory(googletest)
include_directories(googletest/include)

include(CTest)
include(GoogleTest)

add_executable(shape_tests shape_tests.cpp)

target_link_libraries(shape_tests shapes_lib gtest gmock)

gtest_discover_tests(shape_tests)