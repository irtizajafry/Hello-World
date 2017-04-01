#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#ifndef COURSE_H
#define COURSE_H
#include "User.h"
#include "Student.h"
#include "Instructor.h"

class Course 
{
	protected:
	        string coursename;
	        string coursecode;
	        string school;
	        int capacity;
	        int noofstudents;
	        Student *s;
	        Instructor ins;
	        vector<string> assignment;
	        vector<string> resource;
	        vector<string> duedate;
	        

	          
	public: Course();
	     //   Course(string Coursename,string Coursecode,string School,int Capacity,int Noofstudents,Student *S); 
	       // Instructor SetInstructor(Instructor i1);
	      //  Student SetStudent(Student s1);
	        void SetNoofstudents(int Noofstudents);
	        int GetNoofstudents();
	        Instructor GetInstructor();
	        Student* GetStudent();
	        string GetCoursecode();
	        void ViewRoster();
	        void InputCourse(istream& in);
	        void AddAssignment(string a);
	        void AddResource(string r);
	        void ViewAssignment();
	        void ViewResource();
	        void SetAssignment(string a,string b);
	        void SetResource(string a);
	        void AddDuedate(string d);
	        void ViewDuedate();        
};

#endif
