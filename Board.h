//board game class for tic tac toe game X||O

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <iostream>
#include <vector>
#include "Location.h"

#include "Data.h"
#include "IllegalCharException.h"

#include "IllegalCoordinateException.h"

using namespace std;

class Board{

private:
    vector<vector<Data> > brd;

    int length;
public:
  //  Board();
    Board(int nLength=2);
    ~Board(){}

    Board& operator=(const char newVal);
    Board& operator=(const Board& other);

    friend ostream& operator<<(ostream& os, const Board& other);

    Data& operator [](Location loc);

};


#endif //TICTACTOE_BOARD_H
