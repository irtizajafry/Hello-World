#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class Fraction
{
	private : 
	          int *numerator;
	          int *denominator;
	          
	public :
	          Fraction();
	          Fraction(int n,int d);
			  
		//	  Fraction(const Fraction &frac);
			  
			  
			  Fraction operator + (const Fraction& fraction);
			  Fraction operator-(const Fraction& fraction);
			  Fraction operator * (const Fraction& fraction);
			  Fraction operator / (const Fraction& fraction);
			  bool operator == (const Fraction& fraction);
			  Fraction& operator = (const Fraction& fraction); 
			  Fraction& operator ++ ();
			  Fraction& operator -- ();
			  Fraction operator ++(int dummy);
			  Fraction operator --(int dum);
		      friend ostream& operator << (ostream& out,const Fraction& fraction);
			  friend istream& operator >> (istream& in,const Fraction& fraction);
			  
};
#endif
