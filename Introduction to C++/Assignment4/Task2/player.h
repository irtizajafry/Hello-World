#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
#include<iomanip>
#include"square.h"
using namespace std;
class Player
{
	private: string sign;
	         string first;
	         string last;
	        
	public:	Player();     
			Player(string First,string Last,string Sign);
			string getsymbol();
			void setsymbol(string Symbol); 
			string get1stname();
			string getlastname();
			void set1stname(string First);
			void setlastname(string Last);
	                   
};
#endif
