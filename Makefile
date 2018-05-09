CXX=clang++-5.0
CPPFLAGS=-std=c++17 

CCX=g++ -std=c++11


a.out: all
		$(CCX) main.cpp *.o
all: Board.o Data.o

Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o

Data.o: Data.cpp Data.h
	$(CXX) $(CPPFLAGS) --compile Data.cpp -o Data.o
Clean:
		rm *.o a.out
