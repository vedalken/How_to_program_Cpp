include ../../../Makefile.inc

DEPS = Complex.h
OBJ = main.o Complex.o

%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(LFLAGS) $(LIBS)

all: main
.PHONY: all

clean:
	-rm -f *.o main
.PHONY: clean

