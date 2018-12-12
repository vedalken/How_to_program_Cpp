cmake_minimum_required(VERSION 3.13.1)
project(hello_world_of_concurrency)

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world pthread)
