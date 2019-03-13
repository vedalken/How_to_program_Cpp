cmake_minimum_required(VERSION 3.13.1)

set(SUBDIRS
    10.Operator_Overloading_Class_string
    19.Custom_Templatized_Data_Structure)

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()
