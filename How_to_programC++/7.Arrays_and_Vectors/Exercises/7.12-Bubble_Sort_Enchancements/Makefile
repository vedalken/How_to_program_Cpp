all: main.o sortFunctions.o
	g++ -Wall main.o sortFunctions.o -o main 
main.o: main.cpp sortFunctions.h
	g++ -I . -Wall -c main.cpp
sortFunctions.o: sortFunctions.cpp sortFunctions.h
	g++ -I . -Wall -c sortFunctions.cpp
clean:
	rm -f *.o
	rm -f main
