#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class User
{
	protected : string first;
	            string last;
	            string password;
	            string username;
	            int marks;
	            
	public: User();
	        User(string First, string Last,string Username,string Password);
	        User(const User& u);
	        virtual string GetStatus();
	        virtual string GetPassword();
	        virtual string GetUsername();	        
	        
	        string GetFirst();
	        string GetLast();
	        void SetFirst(string First);
	        void SetLast(string Last);
	        void SetUsername(string Username);
	        void SetPassword(string Password);
	        virtual void PopulateData(istream& is);
			             
};
#endif
