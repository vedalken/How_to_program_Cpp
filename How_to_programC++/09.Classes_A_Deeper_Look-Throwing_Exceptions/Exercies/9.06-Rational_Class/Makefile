include ../../../Makefile.inc

DEPS = Rational.h
OBJ = main.o Rational.o

%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(LFLAGS) $(LIBS)

all: main
.PHONY: all

clean:
	-rm -f *.o main
.PHONY: clean

