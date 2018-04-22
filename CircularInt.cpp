#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "CircularInt.hpp"


//Constructor
CircularInt::CircularInt(int newStart, int newEnd) {
    start=newStart;
    end=newEnd;
    currentInt=newStart;
}

//Destructor
CircularInt::~CircularInt() {

}

ostream& operator<<(ostream& output, const CircularInt& X) {
    output << X.currentInt ;
    return output;
}

bool CircularInt::operator >(const CircularInt &X) const {
    return currentInt > X.currentInt;
}

bool CircularInt::operator >=(const CircularInt &X) const {
    return currentInt >= X.currentInt;
}


bool CircularInt::operator <(const CircularInt &X) const {
    return currentInt < X.currentInt;
}

bool CircularInt::operator <=(const CircularInt &X) const {
    return currentInt <= X.currentInt;
}


CircularInt& CircularInt::operator =( int x) {
    this->currentInt=x%this->end;
    return *this;
}

CircularInt& CircularInt::operator +=( int x) {
    this->currentInt=(this->currentInt+x)%this->end;
    return *this;
}

CircularInt& CircularInt::operator -=( int x) {
    this->currentInt=(this->currentInt-x)%this->end;
    if(this->currentInt<0)
        this->currentInt+=12;
    return *this;
}

CircularInt& CircularInt::operator *=( int x) {
    this->currentInt=(this->currentInt*x)%this->end;
    return *this;
}

CircularInt& CircularInt::operator /=( int x) {
    if(this->currentInt%x==0){
        this->currentInt=(this->currentInt/x)%this->end;
        return *this;
    }
    else
        throw;

}

CircularInt& CircularInt::operator %=( int x) {
    this->currentInt=(this->currentInt%x)%this->end;
    return *this;
}



// prefix increment operator
CircularInt& CircularInt::operator++() {
    currentInt ++;
    return *this;
}

// postfix increment operator
CircularInt& CircularInt::operator++(int) {
    CircularInt temp(*this);
    ++*this;
    return temp;
}



int CircularInt:: operator+( CircularInt& x) {
    return (this->currentInt+x.currentInt)%this->end;
}


int CircularInt:: operator-() {
    int ans=this->currentInt*(-1);
    while (ans<0){
        ans+=this->end;
    }
    return ans%this->end;
}


int CircularInt:: operator /( int x){
    if(this->currentInt%x==0){
        this->currentInt=(this->currentInt/x)%this->end;
        return this->currentInt;
    }
    else{
        cout<<"There is no number x in {"<<this->start<<", "<<this->end<<
                  "} such that x*"<<x<<"="<<this->currentInt;
        //throw logic_error();
    }

}

int operator-(int y, CircularInt&x) {
    int ans=(y-x.currentInt)%x.end;
    if(ans<=0)
        ans+=x.end;
    return ans;
}