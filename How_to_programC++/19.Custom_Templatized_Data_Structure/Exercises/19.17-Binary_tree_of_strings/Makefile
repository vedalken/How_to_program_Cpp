SRC_TOP := ../../..

include $(SRC_TOP)/rules/Makefile.inc

TREES_DIR = ../../19.6-Trees
CFLAGS := $(CFLAGS) -I$(TREES_DIR)/include

OBJ = $(patsubst %.cpp,%.o,$(wildcard src/*))

include $(SRC_TOP)/rules/Makefile.rules
