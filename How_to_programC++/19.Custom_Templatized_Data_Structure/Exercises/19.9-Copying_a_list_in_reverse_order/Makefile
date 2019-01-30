SRC_TOP := ../../..

include $(SRC_TOP)/rules/Makefile.inc

LINKED_LIST := ../../19.3-Linked_list/19.3.1-Single_linked_list

LFLAGS_INC = -I$(LINKED_LIST)/src
CFLAGS := $(CFLAGS) -I$(LINKED_LIST)/include -I$(LINKED_LIST)/src
DEPS = $(LINKED_LIST)/include/list.h
OBJ = main.o

include $(SRC_TOP)/rules/Makefile.rules
