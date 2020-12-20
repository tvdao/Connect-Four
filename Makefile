# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11

all: launcher

launcher: Board.o Instructions.o

Board.o: Board.hpp

Instructions.o: Instructions.hpp

clean:
	rm -f launcher *.o core*
