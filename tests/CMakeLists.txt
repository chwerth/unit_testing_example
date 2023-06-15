add_subdirectory(googletest)
include_directories(googletest/include)

include(CTest)
include(GoogleTest)

add_executable(shape_tests shape_tests.cpp test_file.cpp)

target_link_libraries(shape_tests shapes_lib gtest_main gmock)

gtest_discover_tests(shape_tests)