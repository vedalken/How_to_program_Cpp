SRC_TOP:=../..

include $(SRC_TOP)/rules/Makefile.inc

SUBDIRS := test
CFLAGS := $(CFLAGS) -Iinclude
DEPS = include/tree_node.h include/tree.h
OBJ = src/main.o

include $(SRC_TOP)/rules/Makefile.rules
include $(SRC_TOP)/rules/Makefile.dir
