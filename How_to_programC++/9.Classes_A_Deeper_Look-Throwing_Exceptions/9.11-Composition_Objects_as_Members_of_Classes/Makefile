include ../Makefile.inc
SRCDIR = ./src
OBJDIR = ./obj
LIBDIR = ./lib
INCDIR = ./include
LIBS =

_DEPS = Date.h Employee.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ = Date.o Employee.o main.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CXX) -o $@ $< $(CFLAGS)

$(OBJDIR)/main: $(OBJ)
	$(CXX) -o $@ $^ $(LFLAGS) $(LIBS)

all: $(OBJDIR)/main
.PHONY: all

clean:
	\rm -f $(OBJDIR)/*
.PHONY: clean
