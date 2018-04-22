
#include <string>

#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "CircularInt.hpp"

  //constractor
  CircularInt::	CircularInt(int start,int end){
    if(end>start){
      st=start;
      ed=end;
      range=ed-st+1;
      current=st;
    }
    else{
      cout<<"error :range problem"<<endl;

    }
  }//end constractor

  //destructor
  CircularInt::~CircularInt() {

    cout<<"CircularInt ruined"<<endl;
  }


   ostream& operator<<(ostream& os, const CircularInt& Y)
  {
  os << "(" << Y.current<<")";
  return os;
  }

  bool CircularInt::operator >(const CircularInt& other) const{
    return this->current>other.current;
  }

  bool CircularInt::operator <(const CircularInt& other) const{
    return this->current<other.current;
  }
  bool CircularInt::operator >=(const CircularInt& other) const{
    return this->current>=other.current;
  }
  bool CircularInt::operator <=(const CircularInt& other) const{
    return this->current<=other.current;
  }
  CircularInt& CircularInt::operator =( int y) {
    this->current= y%this->ed;
    return *this;
}

CircularInt& CircularInt::operator +=( int y) {
  this->current=(this->current+y)%this->range;
  return *this;
}

CircularInt& CircularInt::operator -=( int y) {
  this->current=(this->current-y)%this->range;
  if(this->current<st ){
    this->current+=range;
    /* data */
  }
  return *this;
}

CircularInt& CircularInt::operator *=( int y) {
  this->current=(this->current*y)%this->range;
  return *this;
}

CircularInt& CircularInt::operator /=( int y) {
    if(this->current%y==0){
        this->current=(this->current/y)%this->range;
        return *this;
    }
    else
        throw;

}


CircularInt& CircularInt::operator %=( int y) {
    this->current=(this->current%y)%this->range;
    return *this;
}

CircularInt& CircularInt::operator++() {
    current ++;
    return *this;
}


CircularInt& CircularInt::operator++(int) {
    CircularInt temp(*this);
    ++*this;
    return temp;
}

int CircularInt:: operator+( CircularInt& other) {
    return (this->current+ other.current)%this->range;
}



int CircularInt:: operator-() {
    int ans=this->current*(-1);
    while (ans<st){
        ans+=this->range;
    }
    return ans%this->ed;
}

int CircularInt:: operator /( int y){
    if(this->current%y==0){
        this->current=(this->current/y)%this->range;
        return this->current;
    }
    else{
        cout<<"There is no number y in {"<<this->st<<", "<<this->ed<<
                  "} such that y*"<<y<<"="<<this->current;
                  return -1;
    }

}

int operator-(int y, CircularInt& other) {
    int ans=(y-other.current)%other.range;
    while(ans<other.st)
        ans+=other.ed;
    return ans;
}
