cmake_minimum_required(VERSION 3.13.1)

set(SUBDIRS
    19.6-Concatenating_Lists
    19.7-Merging_Order_List
    19.8-Summing_and_Averaging_Elements_in_a_List
    19.9-Copying_a_list_in_reverse_order
    19.10-Printing_a_sentence_in_reverse_order_in_a_stack
    19.11-Palindrom_testing_with_stacks
    19.12-Infix_expression_evaluation
    19.17-Binary_tree_of_strings
    19.19-Depth_of_binary_tree
    19.20-Recursively_print_a_list_backward
    19.21-Recursively_search_a_list
)

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()
