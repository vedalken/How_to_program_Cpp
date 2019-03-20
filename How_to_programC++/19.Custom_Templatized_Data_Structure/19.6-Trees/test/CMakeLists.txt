cmake_minimum_required(VERSION 3.13.1)
project (test_trees)

enable_testing()

include_directories(
  ../include
  ../../19.5-Queues/include
  ../../19.3-Linked_list/19.3.1-Single_linked_list/include)

add_executable(main_test main_test.cpp)
add_test(NAME main_test COMMAND main_test)
