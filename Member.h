
#ifndef _MEM_H
#define _MEM_H
#include <string.h>
#include <iostream>
#include<typeinfo>
#include <vector>
#include <algorithm>
//#include "Member.cpp"
#pragma warning(disable: 4996)

using namespace std;

class Member
{
	private:
	static int ctr,idctr;
	int id;
	//static vector <Member*> users;

	//char name [22];
	int following, followers ;

	public:
		vector <Member*> mFollow, mFollowed;

	Member();
	~Member();
	//Member* mFollow[22], *mFollowed[22];
	bool iFh(Member&  a);
	bool iFh(Member&  a,int &k);
	bool heFme(Member&  a,int &k );
	bool heFme(Member&  a );
	bool follow(Member &a);
	bool unfollow(Member &a);
	int numFollowers()  ;
	int numFollowing()  ;
	void print();
	//	static int count();
	static int count(){
	  int x=ctr;
	  return x;
	}

bool	check(vector<Member*> v,Member* x );
//	bool ctrd();

};


#endif//_MEM_H
