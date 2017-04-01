#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Course.h"

Course::Course()
{
	coursename=" ";
	coursecode=" ";
	school=" ";
	capacity=0;
	noofstudents=0;
}

void Course::InputCourse(istream& in)
{
	in>>coursename;
	in>>coursecode;
	in>>school;
	in>>capacity;
	
	s=new Student[noofstudents];
	for(int i=0;i<noofstudents;i++)
	{
		string a1,a2,a3,a4,a5,a6;
		in>>a1>>a2>>a3>>a4>>a5>>a6;
		s[i].SetRollno(a1);
		s[i].SetStatus(a2);
		s[i].SetFirst(a3);
		s[i].SetLast(a4);
		s[i].SetUsername(a5);
		s[i].SetPassword(a6);
	}
	string b1,b2,b3,b4,b5,b6;
	in>>b1>>b2>>b3>>b4>>b5>>b6;
	ins.SetDesignation(b1);
	ins.SetQualification(b2);
	ins.SetFirst(b3);
	ins.SetLast(b4);
	ins.SetUsername(b5);
	ins.SetPassword(b6);
}
void Course::SetNoofstudents(int Noofstudents)
{
	noofstudents=Noofstudents;
}
int Course::GetNoofstudents()
{
	return noofstudents;
}
Instructor Course::GetInstructor()
{
	return ins;
}
Student* Course::GetStudent()
{
	return s;
}
string Course::GetCoursecode()
{
	return coursecode;
}
void Course::ViewRoster()
{
	cout<<"List of Students: "<<endl;
	for(int i=0;i<noofstudents;i++)
	{
		cout<<s[i].GetFirst()<<" "<<s[i].GetLast()<<endl;
	}
    cout<<"Instructor of course: ";
	cout<<ins.GetFirst()<<" "<<ins.GetLast()<<endl;
}
void Course::AddAssignment(string a)
{
	assignment.push_back(a);

}
void Course::AddResource(string r)
{
	resource.push_back(r);
}
void Course::ViewAssignment()
{
    for(int i=0;i<assignment.size();i++)
    {
    	cout<<"Name: "<<assignment[i]<<endl;
    }
}
void Course::ViewResource()
{
	for(int i=0;i<resource.size();i++)
	{
		cout<<"Name: "<<resource[i]<<endl;
	}
}
void Course::SetAssignment(string a,string b)
{
	assignment.push_back(a);
	duedate.push_back(b);
}
void Course::SetResource(string a)
{
	resource.push_back(a);
}
void Course::ViewDuedate()
{
	for(int i=0;i<duedate.size();i++)
	{
		cout<<"Due-date: "<<duedate[i]<<endl;
	}
}
void Course::AddDuedate(string d)
{
	duedate.push_back(d);
}

