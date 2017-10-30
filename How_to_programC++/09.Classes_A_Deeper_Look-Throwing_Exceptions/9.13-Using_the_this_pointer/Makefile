include ../Makefile.inc

DEPS = Time.h
OBJ  = main.o Time.o

%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CXX) -o $@ $^ $(LFLAGS) $(LIBS)

all: main
.PHONY: all

clean:
	\rm -f *.o main
.PHONY: clean
