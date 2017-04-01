#ifndef __FRACTION_CPP
#define __FRACTION_CPP

#include<iostream>
#include<string>
#include"Fraction.h"
using namespace std;

Fraction::Fraction()
{
	numerator=new int;
	denominator=new int;
	*numerator=0;
	*denominator=1;
}

Fraction::Fraction(int n,int d)
{
	numerator=new int;
	denominator=new int;
	
	*numerator=n;
	*denominator=d;
}
/*
Fraction::Fraction(const Fraction &frac)
{
	*numerator=*(frac.numerator);
	*denominator=*(frac.denominator); 
}
*/
int HCF(int a,int b)
{
	int min=0;
	if(a<0)
	{
		a=a*-1;		
	}
	if(b<0)
	{
		b=b*-1;
	}
	if(a==0)
	{
		min=1;
		return min;
	}

	if(a<b)
	{
		min=a;
	}
	else
	{
		min=b;
	}
	for(int i=min;i>=1;i--)
	{
		if((a%i)==0 && (b%i)==0)
		{
			break;
		}
		min--;
	}
	return min;
}


Fraction Fraction::operator + (const Fraction& fraction)
{
	while(*(denominator)==0)
	{
		cout<<"Denominator is zero for first fraction. Enter again."<<endl;
		cout<<"enter numerator again :";
	    cin>>*(numerator);
	    cout<<"enter denominator again :";
		cin>>*(denominator);
	}
	while(*(fraction.denominator)==0)
	{
		cout<<"Denominator is zero for second fraction. Enter again."<<endl;
		cout<<"enter numerator again : ";
	    cin>>*(fraction.numerator);
		cout<<"enter denominator again : ";
		cin>>*(fraction.denominator);
	}
	int a,b,ab,aa;
	if(*numerator==0)
	{
		aa=*(fraction.numerator);
		ab=*(fraction.denominator);
	}
	if(*(fraction.numerator)==0)
	{
		aa=*numerator;
		ab=*denominator;
	}
	if(*numerator!=0 && *(fraction.numerator)!=0)
	{
		ab = *(denominator)*(*(fraction.denominator));
	    a =*(numerator)*(*(fraction.denominator));
	    b =*(denominator)*(*(fraction.numerator));
	    aa = a+b;
	}
	int hcf = HCF(aa,ab);
	if(hcf!=1)
	{
		aa=aa/hcf;
		ab=ab/hcf;
	}

	Fraction f3(aa,ab);
	
	return f3;
}

Fraction Fraction:: operator-(const Fraction& fraction)
{
	while(*(denominator)==0)
	{
		cout<<"Denominator is zero for first fraction. Enter again."<<endl;
	    cin>>*(numerator)>>*(denominator);
	}
	while(*(fraction.denominator)==0)
	{
		cout<<"Denominator is zero for second fraction. Enter again."<<endl;
	    cin>>*(fraction.numerator)>>*(fraction.denominator);
	}
	int a,b,ab,aa;
	if(*numerator==0)
	{
		aa=*(fraction.numerator);
		ab=*(fraction.denominator);
	}
	if(*(fraction.numerator)==0)
	{
		aa=*numerator;
		ab=*denominator;
	}
	if(*numerator!=0 && *(fraction.numerator)!=0)
	{
		ab = *(denominator)*(*(fraction.denominator));
	    a =*(numerator)*(*(fraction.denominator));
	    b =*(denominator)*(*(fraction.numerator));
	    aa = a-b;
	}
	
	int hcf;
	
    hcf = HCF(aa,ab);
	
	if(hcf!=1)
	{
		aa=aa/hcf;
		ab=ab/hcf;
	}

	Fraction f3(aa,ab);
	
	return f3;
} 	

Fraction Fraction::operator * (const Fraction& fraction) 	
{
	while(*(denominator)==0)
	{
		cout<<"Denominator is zero for first fraction. Enter again."<<endl;
	    cin>>*(numerator)>>*(denominator);
	}
	while(*(fraction.denominator)==0)
	{
		cout<<"Denominator is zero for second fraction. Enter again."<<endl;
	    cin>>*(fraction.numerator)>>*(fraction.denominator);
	}
	int a = *numerator*(*(fraction.numerator));
	int b = *denominator*(*(fraction.denominator)); 
	int hcf = HCF(a,b);
	if(hcf!=1)
	{
		a=a/hcf;
		b=b/hcf;
	}
	
	Fraction f3(a,b);
	
	return f3;
}

Fraction Fraction::operator / (const Fraction& fraction) 	
{
	while(*(fraction.numerator)==0)
	{
		cout<<"Numerator is zero for second fraction. Enter again."<<endl;
	    cin>>*(fraction.numerator)>>*(fraction.denominator);
	}
	int a = *(numerator)*(*(fraction.denominator));
	int b = *(denominator)*(*(fraction.numerator)); 
	int hcf = HCF(a,b);
	if(hcf!=1)
	{
		a=a/hcf;
		b=b/hcf;
	}

	Fraction f3(a,b);
	
	return f3;
}

istream& operator >> (istream& in, const Fraction& fraction)
{
	cout<<"Enter numerator: ";
	in>>*(fraction.numerator);
	cout<<"Enter denominator: ";
	in>>*(fraction.denominator);
	return in;
}

ostream& operator << (ostream& out,const Fraction& fraction)
{
	out<<*(fraction.numerator)<<"/"<<*(fraction.denominator)<<endl;
	return out;
}

Fraction& Fraction::operator ++ ()
{
	int hcf=HCF(*numerator,*denominator);
	if(hcf!=1)
	{
		*numerator/=hcf;
		*denominator/=hcf;
	}
	*numerator=*numerator + *denominator*1;
	return *this;
}

Fraction& Fraction::operator -- ()
{
	int hcf=HCF(*numerator,*denominator);
	if(hcf!=1)
	{
		*numerator/=hcf;
		*denominator/=hcf;
	}
	*numerator=*numerator - *denominator*1;
	return *this;
}  

Fraction Fraction::operator ++ (int dummy)
{
	int hcf=HCF(*numerator,*denominator);
	if(hcf!=1)
	{
		*numerator/=hcf;
		*denominator/=hcf;
	}
	int num=*numerator;
	int den=*denominator;
	Fraction f3(num,den);
	*numerator=*numerator + *denominator*1;
	return f3;
} 

Fraction Fraction::operator --(int dum)
{
	int hcf=HCF(*numerator,*denominator);
	if(hcf!=1)
	{
		*numerator/=hcf;
		*denominator/=hcf;
	}
	int num=*numerator;
	int den=*denominator;
	Fraction f3(num,den);
	*numerator=*numerator - *denominator*1;
	return f3;
} 


Fraction& Fraction::operator = (const Fraction& fraction)
{
	*numerator=*(fraction.numerator);
	*denominator=*(fraction.denominator);
	return *this;
}

bool Fraction::operator == (const Fraction& fraction)
{
	int hcf=HCF(*numerator,*denominator);
	int hcf1=HCF(*(fraction.numerator),*(fraction.denominator));
	if(hcf!=1)
	{
		*numerator/=hcf;
		*denominator/=hcf;
	}
	if(hcf1!=1)
	{
		*(fraction.numerator)/=hcf1;
		*(fraction.denominator)/=hcf1;
	}
	if ((*(numerator)==*(fraction.numerator)) && (*(denominator)==*(fraction.denominator)))
	{
		return true;
	}
	else 
	{
		return false;
	}
} 
#endif
