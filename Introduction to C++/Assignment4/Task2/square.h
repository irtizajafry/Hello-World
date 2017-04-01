#ifndef SQUARE_H
#define SQUARE_H
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Square
{
	private: 
	        string position;
	        
	public: Square();
	        Square(string Position);
	        void setposition(string Position);
            string getposition();
};
#endif
