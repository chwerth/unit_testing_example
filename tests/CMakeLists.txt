add_subdirectory(googletest)
include_directories(googletest/include)

include(GoogleTest)

add_executable(shape_tests
    simple_tests.cpp
    fixture_tests.cpp
    parameterized_tests.cpp
    mock_tests.cpp
)

target_link_libraries(shape_tests
    shapes_lib
    gtest_main
    gmock
)

set_property(TARGET shape_tests PROPERTY CXX_STANDARD 20)

gtest_discover_tests(shape_tests)