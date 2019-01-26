cmake_minimum_required(VERSION 3.13.1)
project(19.3.1)

include_directories(include)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
