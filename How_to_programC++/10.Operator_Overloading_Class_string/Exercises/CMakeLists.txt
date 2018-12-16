cmake_minimum_required(VERSION 3.13.1)

set(SUBDIRS
    10.7-Overloading_the_parentheses_operator
    10.8-Complex_class
    10.9-HugeInt_class)

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()
