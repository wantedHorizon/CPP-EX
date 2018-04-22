#include<iostream>
#include<string>
#include "CircularInt.cpp"
using namespace std;

class CircularInt {


public:

    //Constructor
    CircularInt(int newStart, int newEnd);

    //Destructor
    ~CircularInt();

    friend ostream& operator<<(ostream& output, const CircularInt& H);

    bool operator >(const CircularInt& X) const;
    bool operator >=(const CircularInt& X) const;
    bool operator <(const CircularInt& X) const;
    bool operator <=(const CircularInt& X) const;

    CircularInt& operator =( int x);
    CircularInt& operator +=( int x);
    CircularInt& operator -=( int x);
    CircularInt& operator *=( int x);
    CircularInt& operator /=( int x);
    CircularInt& operator %=( int x);

    CircularInt& operator ++();
    CircularInt& operator ++( int);
    int operator+( CircularInt& x);
    int operator-();
    int operator /( int x);

    friend int operator-(int y, CircularInt&x);


private:
    int start, end, currentInt;

};