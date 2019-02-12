SRC_TOP := ../../..

include $(SRC_TOP)/rules/Makefile.inc

INC_DIR = ../../19.3-Linked_list/19.3.1-Single_linked_list
LFLAGS_INC = -I$(INC_DIR)/src
CFLAGS := $(CFLAGS) -I$(INC_DIR)/include -I$(INC_DIR)/src

DEPS = $(INC_DIR)/include/list.h
OBJ = src/main.o

include $(SRC_TOP)/rules/Makefile.rules
