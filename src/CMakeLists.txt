add_library(shapes_lib shapes.cpp ../include/shapes.hpp)

target_include_directories(shapes_lib PUBLIC ../include)

set_property(TARGET shapes_lib PROPERTY CXX_STANDARD 98)