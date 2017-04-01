#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "User.h"


User::User()
{
	first=" ";
	last=" ";
	username=" ";
	password=" ";

}
User::User(string First,string Last,string Username,string Password)
{
	first=First;
	last=Last;
	username=Username;
	password=Password;
}

User::User(const User& u)
{
	first=u.first;
	last=u.last;
	username=u.username;
	password=u.password;
}
string User::GetStatus()
{
	return "";
}

string User::GetUsername()
{
	return username;
}
string User::GetPassword()
{
	return password;
}
string User::GetFirst()
{
	return first;
}
string User::GetLast()
{
	return last;
}
void User::SetFirst(string First)
{
	first=First;
}
void User::SetLast(string Last)
{
	last=Last;
}
void User::SetUsername(string Username)
{
	username=Username;
}
void User::SetPassword(string Password)
{
	password=Password;
}
void User::PopulateData(istream &is)
{
	
}


