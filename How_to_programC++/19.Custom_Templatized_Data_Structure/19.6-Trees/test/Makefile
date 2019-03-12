SRC_TOP:=../../..

include $(SRC_TOP)/rules/Makefile.inc

TOP:=..
TOP_INC:=$(TOP)/include

CFLAGS := $(CFLAGS) -I$(TOP_INC)
DEPS = $(TOP_INC)/tree_node.h $(TOP_INC)/tree.h
OBJ = main_test.o

include $(SRC_TOP)/rules/Makefile.rules
