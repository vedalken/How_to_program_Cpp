cmake_minimum_required(VERSION 3.13.1)
project(19.5)

get_filename_component(linked_list_path "../19.3-Linked_list" ABSOLUTE)

include_directories(
    include 
    ${linked_list_path}/19.3.1-Single_linked_list/include
)

file(GLOB_RECURSE SOURCES RELATIVE "${PROJECT_SOURCE_PATH}" src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
