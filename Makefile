
CXX=clang++-5.0
RM=rm -f
CPPFLAGS=-std=c++17

all:
	$(CXX) $(CPPFLAGS) *.cpp -o a.out
	./a.out

Board.o: Board.cpp Board.h
	$(CXX) $(CPPFLAGS) --compile Board.cpp -o Board.o

clean:
	$(RM) *.exe a.out *.class
