# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11

all: launcher

launcher: Board.o

Board.o: Board.hpp

clean:
	rm -f launcher *.o core*
