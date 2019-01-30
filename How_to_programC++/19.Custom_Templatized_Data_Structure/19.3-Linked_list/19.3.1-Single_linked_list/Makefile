SRC_TOP:=../../..

include $(SRC_TOP)/rules/Makefile.inc

CFLAGS := $(CFLAGS) -Iinclude
DEPS = include/list.h
OBJ = $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

include $(SRC_TOP)/rules/Makefile.rules
