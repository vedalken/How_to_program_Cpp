cmake_minimum_required(VERSION 3.13.1)
project (test_trees)

enable_testing()

include_directories(../include)

add_executable(main_test main_test.cpp)
add_test(NAME main_test COMMAND main_test)
