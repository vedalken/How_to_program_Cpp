SRC_TOP:=../..

include $(SRC_TOP)/rules/Makefile.inc

INC_LINK_LIST=../19.3-Linked_list/19.3.1-Single_linked_list/include

CFLAGS := $(CFLAGS) -Iinclude -I$(INC_LINK_LIST)
DEPS = include/stack.h include/cstack.h
OBJ = src/main.o

include $(SRC_TOP)/rules/Makefile.rules
