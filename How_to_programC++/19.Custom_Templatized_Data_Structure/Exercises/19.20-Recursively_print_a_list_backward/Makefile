SRC_TOP := ../../..

include $(SRC_TOP)/rules/Makefile.inc

INC_DIR = ../../19.3-Linked_list/19.3.1-Single_linked_list
CFLAGS := $(CFLAGS) -I$(INC_DIR)/include

OBJ = $(patsubst %.cpp,%.o,$(wildcard src/*))

include $(SRC_TOP)/rules/Makefile.rules
