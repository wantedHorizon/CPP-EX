#include <iostream>
#include "Board.h"
using namespace std;


Board::Board(int nLength)
{
    this->length = nLength;
    for (int i = 0; i < length; i++)
        brd.push_back(vector<Data>(length));
      }

int Board::getL() const {return length;}

//-----operators----
Board& Board::operator=(char ch)
{
    if(ch == '.')
        *this=Board{length};

    else{
        IllegalCharException cc;
        cc.setChar(ch);
        throw cc;
    }

    return *this;
}



/*
Board& Board::operator=(const Board& other){
    if(other.length!=this->length)
    *this=Board{other.getL()};

      for (int i = 0; i <length ; ++i)
          for (int j = 0; j <length ; ++j)
              brd[i][j]=other.brd[i][j];






    else{  IllegalCoordinateException cc{other.length};
      throw cc;

            }



              return *this;
}
*/

Board& Board::operator=(const Board& other)
{
    if(other.length!=length){
        IllegalCoordinateException ce{other.length};
        throw ce;
    }

    else{
        for (int i = 0; i <length ; ++i) {
            for (int j = 0; j <length ; ++j) {
                brd[i][j]=other.brd[i][j];
            }

        }
    }

    return *this;
}
ostream& operator<<(ostream& os, const Board& other){

    for (size_t i = 0; i <other.length ; ++i){
        for (size_t t = 0; t <other.length ; ++t){
            os<<other.brd[i][t];
          }
        os<<endl;
}
    return os;

}






Data& Board::operator [](Location loc)
{
    if(loc.getx() < 0 || loc.gety() < 0 ||
       loc.getx() >= length || loc.gety() >= length){
        IllegalCoordinateException ss{loc};
        throw ss;
    }
    return brd[loc.getx()][loc.gety()];
}

//
bool Board::verify(const char ch){
  if(ch=='X'||ch=='O'||ch=='.')
    return true;
  else{
      IllegalCharException cc;
      cc.setChar(ch);
      throw cc;

      return false;
    }
}

bool Board::verify(const Board& other){
  for (int i = 0; i <length ; ++i)
      for (int j = 0; j <length ; ++j){
        if(!verify(other.brd[i][j]))
        return false;


      }
      return true;

}
