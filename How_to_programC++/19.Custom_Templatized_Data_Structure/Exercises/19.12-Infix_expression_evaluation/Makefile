SRC_TOP := ../../..

include $(SRC_TOP)/rules/Makefile.inc

CUSTOM_TEMPL_DATA_DIR := $(SRC_TOP)/19.Custom_Templatized_Data_Structure
STACKS_DIR = $(CUSTOM_TEMPL_DATA_DIR)/19.4-Stacks
LINKED_LIST_DIR =$(CUSTOM_TEMPL_DATA_DIR)/19.3-Linked_list/19.3.1-Single_linked_list

INCDIRS = $(STACKS_DIR)/include $(LINKED_LIST_DIR)/include

CFLAGS := $(CFLAGS) $(patsubst %,-I%,include $(INCDIRS))
LFLAGS_INC = -I$(LINKED_LIST_DIR)/src

DEPS = include/infix_expr.h
OBJ = $(patsubst %.cpp,%.o,$(wildcard src/*))

# add math library
LFLAGS += -lm

include $(SRC_TOP)/rules/Makefile.rules
