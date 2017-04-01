#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Instructor.h"

Instructor::Instructor()
{
	designation=" ";
	qualification=" ";
}
Instructor::Instructor(string Designation,string Qualification,string First, string Last,string Username, string Password):User(First,Last,Username,Password)
{
	designation=Designation;
	qualification=Qualification;
}
Instructor::Instructor(const Instructor& u):User(u)
{
	designation=u.designation;
	qualification=u.qualification;
}

string Instructor::GetStatus()
{
	return "1";
}
void Instructor::PopulateData(istream& is)
{
	is>>designation>>qualification>>first>>last>>username>>password;
}
string Instructor::GetDesignation()
{
	return designation;
}
string Instructor::GetQualification()
{
	return qualification;
}
void Instructor::SetDesignation(string Designation)
{
	designation=Designation;
}
void Instructor::SetQualification(string Qualification)
{
	qualification=Qualification;
}
