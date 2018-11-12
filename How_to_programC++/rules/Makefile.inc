INCDIR = .
CXX = ccache gcc
FLAGS = -Wall -Wextra -Wpedantic -std=c++1z
DFLAGS = -O2
CFLAGS = -x c++ -c $(FLAGS) $(DFLAGS) -I$(INCDIR)
LFLAGS = -fuse-ld=gold $(FLAGS) -I$(INCDIR) -lstdc++
MAKE_OPTS =
MAKE = make $(MAKE_OPTS)
