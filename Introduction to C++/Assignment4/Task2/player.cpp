#include<iostream>
#include<string>
#include<iomanip>
#include"square.h"
#include"player.h"
using namespace std;
Player::Player()
{
	first=" ";
	last=" ";
	sign=" ";
}
Player::Player(string First,string Last,string Sign)
{
	first=First;
	last=Last;
	sign=Sign;
}

string Player::getsymbol()
{
	return sign;
}
void Player::setsymbol(string Symbol)
{
	sign=Symbol;
}

void Player::set1stname(string First)
{
	first=First;
}
void Player::setlastname(string Last)
{
	last=Last;
}

string Player::get1stname()
{
	return first;
}
string Player::getlastname()
{
	return last;
}
