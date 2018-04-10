
#include "Member.h"

//using namespace std;
Member::Member()
{
followers=0;
following=0;

id =++idctr;
int * pid=&id;
++ctr;
//users.push_back(this);
}

Member::~Member(){

  for(int i=0;i<mFollow.size();i++)
    unfollow(*mFollow.at(i));

    for(int i=0;i<mFollowed.size();i++)
      mFollowed.at(i)->unfollow(*this);


  //delete mFollow,mFollowed;
  id=-1;
  --ctr;
}




int Member::numFollowers()
{
	return followers;
}

int Member::numFollowing()
{
	return following;
}






void Member::print(){

		std::cout << "\nnumFollowing:"  <<this->following <<endl;
		for (size_t i = 0; i < 20; i++) {
			cout<<" "<<(mFollow[i]);
		}
		std::cout << "\nnumFollowed:"  <<this->followers <<endl;
		for (size_t i = 0; i < 20; i++) {
			cout<<" "<<(mFollowed[i]);
		}
		cout<<"\n\n"<<endl;

}



bool Member::follow(Member& a){
  bool flag=true;
          //Check if you not following this person already
          for (int i=0;i< mFollow.size()&&flag;i++) {
              if (mFollow.at(i) ==&a) flag= false;
          }
          //If you don't follow -
  if (flag){
    //adds a to ur following list
    mFollow.push_back(&a);
    //adds to a followed list my &
    a.mFollowed.push_back(this);
    a.followers++;
    following++;

    return true;// succesfully follow

}
return false;

}//end follow

bool Member::unfollow(Member& a){
  bool flag=true;
  for (int i=0;i< mFollow.size()&&flag;i++) {
      if (mFollow.at(i) ==&a) flag= false;
  }
  if(flag){cout<<"err:you are not  following him"<<endl;}
  else if(!flag){
    bool f1=true;
    for (int i=0;i< mFollow.size()&&f1;i++)
        if (mFollow.at(i) ==&a) {mFollow.erase(mFollow.begin()+i);f1=false;}

        f1=true;
        for (int i=0;i< a.mFollowed.size()&&f1;i++)
            if (a.mFollowed.at(i) ==this) a.mFollowed.erase(a.mFollowed.begin()+i);
            following--;
            a.followers--;
            return true;
  }

return false;
}//end unfollow

int Member::ctr=0;
int Member::idctr=0;
//void Member::vector <Member*> users=new vector <Member*> () ;
/*
bool Member::heFme(Member&  a,int & k){// checks if he is followed by me
	for(int i=0;i<20;i++){
		if(a.mFollowed[i]==this){
		//	std::cout << "u mark as followed by him " << '\n';
			k=i;
			return true;

		}}

	return false;
}

bool Member::heFme(Member&  a){// checks if he is followed by me
	for(int i=0;i<20;i++){
		if(a.mFollowed[i]==this){
	//		std::cout << "u mark as followed by him " << '\n';
			return true;

		}}

	return false;
}

bool Member::iFh(Member& a,int & k){// checks if i follow him
for(int i=0;i<20;i++){
	if(mFollow[i]==&a){
	//	std::cout << "already following him" << '\n';
		k=i;
		return true;
	}
}
return false ;
}

bool Member::iFh(Member& a){// checks if i follow him
for(int i=0;i<20;i++){
	if(mFollow[i]==&a){
	//	std::cout << "already following him" << '\n';

		return true;
	}
}
return false ;
}


bool Member::follow(Member& a){

	if(!heFme(a)&&(! iFh(a) )  )
	{
	int x=a.followers;
	mFollow[following]=&a;
	a.mFollowed[x]=this;
	a.followers++;
	following++;
//	cout << "succesfully follow: " << typeid(a).name()<< '\n'<<endl;
	return true;
}
std::cout << "follow unsuccesful" << '\n';
return false;
	//a->mFollowers[x]=this.Member;
}

bool Member::unfollow(Member& a){
	int mk=-1,hk=-1;
	//
	if(a.heFme(*this,mk)&&( a.iFh(*this,hk) )  ){
	a.mFollowed[mk]=nullptr;
	mFollow[hk]=nullptr;
	this->following--;
	a.followers--;
	std::cout << "unfollow" << '\n';
	return true;
}
	return false;
	//a->mFollowers[x]=this.Member;
}


*/
