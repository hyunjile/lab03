#include <iostream>
#include <string>
#include <vector>
#include "List.cpp"

using namespace std;

class User{

public:
  User();
  ~User();
  void setName(string name);
  void setAge(int age);
  void setFriend(string friends);
  string getName();
  void printUser();

private:
  string name_;
  int age_;
  List *friend_;

};

User::User(){
  name_ = "";
  age_ = 0;
  friend_ = new List;
}

User::~User(){}

void User::setName(string name){
  name_ = name;
}

void User::setAge(int age){
  age_ = age;
}

void User::setFriend(string friends){
  friend_ -> push_back(friends);
}

string User::getName(){
  return name_;
}

void User::printUser(){
  cout<<"User name:    "<<name_<<endl;
  cout<<"User age:     "<<age_<<endl;
  cout<<"User friends: ";
  if(friend_->size() == 0){
    cout<<"None"<<endl;
  }
  else{
    for(int u = 0; u<(friend_->size()); u++){
	if((u+1) == friend_->size()){
	  cout<<friend_->at(u)<<endl;
	}
	else{
	  cout<<friend_->at(u)<<" ";
	}
    }
  }
 
}

int main(){
  vector<User*>  userList;
  string name, userName, userFriend;
  int age;

  while(name != "done"){
    cout << "Enter a pair of a first name and an age per line: ";
    cin >> name;
    if(name != "done"){
      cin >> age;
      User *user_ = new User;
      user_->setName(name);
      user_->setAge(age);
      userList.push_back(user_);
    }
  }

  while(userName != "done"){
    cout << "Enter a pair of an user's first name and the user's friend's first name: ";
    cin >> userName;
    if(userName != "done"){
      cin >> userFriend; 
      for(int j = 0; j < userList.size(); j++){
	if(userList[j] -> getName() == userName){
	  userList[j] -> setFriend(userFriend);
	}//if
      }//for
    }//if
  }//while

  for(int i = 0; i < userList.size(); i++){
    userList[i]->printUser();
  }

  return 0;
}


