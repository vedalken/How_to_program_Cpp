cmake_minimum_required(VERSION 3.13.1)
project(parallel_accumulate)

add_executable(parallel_accumulate parallel_accumulate.cpp)

target_link_libraries(parallel_accumulate pthread)
