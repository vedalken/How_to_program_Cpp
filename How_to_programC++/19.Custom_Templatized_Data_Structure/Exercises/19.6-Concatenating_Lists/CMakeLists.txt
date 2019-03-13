cmake_minimum_required(VERSION 3.13.1)
project(19.6e)

set(linked_list_path ../../19.3-Linked_list/19.3.1-Single_linked_list)

include_directories(${linked_list_path}/include)

file(GLOB_RECURSE SOURCES RELATIVE "${PROJECT_SOURCE_PATH}" src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
