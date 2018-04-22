
#ifndef _CRR_H
#define _CRR_H

#include<iostream>
#include<string>

using namespace std;

class CircularInt {
	int range, st,ed,current;

public:
	//constractor
	CircularInt(int start,int end);

	//destructor
	~CircularInt();

friend	ostream& operator<<(ostream& os, const CircularInt& Y) ;

	bool operator >(const CircularInt& other) const;
	bool operator <(const CircularInt& other) const;
	bool operator <= (const CircularInt& other) const;
	bool operator >=(const CircularInt& other) const;

	CircularInt& operator =( int y);
	CircularInt& operator +=( int y);
	CircularInt& operator -=( int y);
	CircularInt& operator *=( int y);
	CircularInt& operator /=( int y);
	CircularInt& operator %=( int y);

	CircularInt& operator ++();
	CircularInt& operator ++( int);
		int operator+( CircularInt& y);
	int operator-();
	int operator /( int x);

	friend int operator-(int y, CircularInt&x);



};
#endif//_CRR_H
