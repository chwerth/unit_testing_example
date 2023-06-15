add_executable(shapes_app main.cpp)
target_link_libraries(shapes_app shapes_lib)

set_property(TARGET shapes_lib PROPERTY CXX_STANDARD 98)