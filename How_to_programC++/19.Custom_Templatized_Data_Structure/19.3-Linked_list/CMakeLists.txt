cmake_minimum_required(VERSION 3.13.1)

set(SUBDIRS
    19.3.1-Single_linked_list
    19.3.2-Single_linked_list_shared_ptr
    19.3.3-Circular_single_linked_list)

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()
