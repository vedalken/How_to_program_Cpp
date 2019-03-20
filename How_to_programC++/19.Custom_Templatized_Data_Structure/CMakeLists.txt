cmake_minimum_required(VERSION 3.13.1)

set(SUBDIRS
    19.3-Linked_list
    19.4-Stacks
    19.5-Queues
    19.6-Trees
    19.6-Trees-shared_ptr
    Exercises)

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()
