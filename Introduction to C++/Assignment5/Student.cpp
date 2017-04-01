#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Student.h"

Student::Student()
{
	rollno=" ";
	status=" ";
}
Student::Student(string Rollno, string Status,string First, string Last, string Username, string Password):User(First,Last,Username,Password)
{
	rollno=Rollno;
	status=Status;
}
Student::Student(const Student & u):User(u)
{
	rollno=u.rollno;
	status=u.status;
}

string Student::GetStatus()
{
	return status;
}
string Student::GetUsername()
{
	return username;
}
string Student::GetPassword()
{
	return password;
}
void Student::PopulateData(istream& is)
{
	is>>rollno>>status>>first>>last>>username>>password;
}
void Student::SetStatus(string Status)
{
	status=Status;
}
void Student::SetRollno(string Rollno)
{
	rollno=Rollno;
}
