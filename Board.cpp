#include "Board.h"

void verify(char c) {
	if (c!='.' && c!='X' && c!='O')
		throw IllegalCharException{c};
}

BoardLocation& BoardLocation::operator=(char c) {
	verify(c);
	loc = c;
	return *this;
}


Board& Board::operator=(char c) {
	verify(c);
	for(int i=0; i<theSize*theSize; ++i) {
		theChars[i] = '.';
	}
	return *this;
}
