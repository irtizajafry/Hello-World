#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User
{
	private:string rollno;
	        string status;

	        
	public: Student();
	        Student(string Rollno,string Status,string First,string Last, string Username, string Password);
	        Student(const Student& u);
	        
	        string GetStatus();
	        string GetPassword();
	        string GetUsername();
	        void SetRollno(string Rollno);
	        string GetRollno();
	        void SetStatus(string Status);
	        void PopulateData(istream& is);
};

#endif
