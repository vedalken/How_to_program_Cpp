INCDIR = .
CXX    = g++
FLAGS  = -Wall -Wpedantic -std=c++14
DFLAGS = -g
CFLAGS = -c $(FLAGS) $(DFLAGS) -I$(INCDIR)
LFLAGS = $(FLAGS) -I$(INCDIR)
MAKE   = make
