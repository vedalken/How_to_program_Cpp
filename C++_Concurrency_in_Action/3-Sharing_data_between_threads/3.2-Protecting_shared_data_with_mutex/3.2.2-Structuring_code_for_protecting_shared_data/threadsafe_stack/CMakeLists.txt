cmake_minimum_required(VERSION 3.13.1)
project(threadsafe_stack)

add_executable(threadsafe_stack threadsafe_stack.cpp)

target_link_libraries(threadsafe_stack pthread)
