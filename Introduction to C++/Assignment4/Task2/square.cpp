#include<iostream>
#include<string>
#include<iomanip>
#include"square.h"
using namespace std;

Square::Square()
{
	position=" ";
}
Square::Square(string Position)
{
	position=Position;
}
void Square::setposition(string Position)
{
	position=Position;
}
string Square::getposition()
{
	return position;
}
