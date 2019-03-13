cmake_minimum_required(VERSION 3.13.1)
project(19.12e)

set(linked_list_path ../../19.3-Linked_list/19.3.1-Single_linked_list)
set(stack_list_path ../../19.4-Stacks)

include_directories(
  include
  ${linked_list_path}/include
  ${linked_list_path}/src
  ${stack_list_path}/include)

file(GLOB_RECURSE SOURCES RELATIVE "${PROJECT_SOURCE_PATH}" src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} m)
