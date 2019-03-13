cmake_minimum_required(VERSION 3.13.1)
project(19.11e)

file(GLOB_RECURSE SOURCES RELATIVE "${PROJECT_SOURCE_PATH}" src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
