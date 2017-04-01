#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include "User.h"

class Instructor : public User
{
	private:string designation;
	        string qualification; 
	
	public: Instructor();
	        Instructor(string Designation, string Qualification,string First, string Last,string Username,string Password);
	    //    void AddMarks(Student s,Course c);
	        void PopulateData(istream& is);
	        Instructor(const Instructor& u);
	        string GetStatus();
	        string GetDesignation();
	        string GetQualification();
	        void SetDesignation(string Designation);
	        void SetQualification(string Qualification);
	        void AddMarks();
	        
};

#endif
