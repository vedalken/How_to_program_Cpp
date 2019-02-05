CXX = ccache gcc
FLAGS = -Wall -Wextra -Wpedantic -std=c++1z
DFLAGS = -O2
CFLAGS = -x c++ -c $(FLAGS) $(DFLAGS) 
LFLAGS_INC := $(LFLAGS_INC)
LFLAGS = -fuse-ld=gold $(FLAGS) $(LFLAGS_INC) -lstdc++
MAKE_OPTS =
MAKE = make $(MAKE_OPTS)
