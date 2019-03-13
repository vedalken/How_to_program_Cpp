SRC_TOP := ../../..

include $(SRC_TOP)/rules/Makefile.inc

LINKED_LIST = ../../19.3-Linked_list/19.3.1-Single_linked_list
LINKED_LIST_SRC = $(LINKED_LIST)/src
LINKED_LIST_INC = $(LINKED_LIST)/include

CFLAGS := $(CFLAGS) -I$(LINKED_LIST_INC) -I$(LINKED_LIST_SRC)
DEPS := $(LINKED_LIST_INC)/list.h $(LINKED_LIST_SRC)/list.cpp
OBJ := src/main.o

include $(SRC_TOP)/rules/Makefile.rules
