cmake_minimum_required(VERSION 3.13.1)
project(19.17e)

include_directories(
  ../../19.3-Linked_list/19.3.1-Single_linked_list/include
  ../../19.5-Queues/include
  ../../19.6-Trees/include)

file(GLOB_RECURSE SOURCES RELATIVE "${PROJECT_SOURCE_PATH}" src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
