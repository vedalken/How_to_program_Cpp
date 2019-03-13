cmake_minimum_required(VERSION 3.13.1)
project(19.17e)

set(tree_path ../../19.6-Trees)

include_directories(${tree_path}/include)

file(GLOB_RECURSE SOURCES RELATIVE "${PROJECT_SOURCE_PATH}" src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
