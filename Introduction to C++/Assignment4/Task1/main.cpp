#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

int main()
{
    string a;
    
    cout<<"Press 1 for addition"<<endl;
    cout<<"Press 2 for subtraction"<<endl;
    cout<<"Press 3 for multiplication"<<endl;
    cout<<"Press 4 for division"<<endl;
    cout<<"Press 5 for comparison"<<endl;
    cout<<"Press 6 for pre-incrementation"<<endl;
    cout<<"Press 7 for post-incrementation"<<endl;
    cout<<"Press 8 for pre-decrementation"<<endl;
    cout<<"Press 9 for post-decrementation"<<endl;
    cout<<"Press 10 to pop out last operation from stack"<<endl;
    cout<<"Press 11 to print stack"<<endl;
    cout<<"Press -1 to terminate the program"<<endl;
    cin>>a;

    Stack s1;
    int count=0;
	while(a!="-1")
    {
		
		string sign;
    	int opcount;
    	Fraction answer;
    	int answer1;
    	int x0,y0;
    	Fraction f0(x0,y0);
    	int x1,y1;
    	int x2,y2;
    	Fraction f1(x1,y1);
    	Fraction f2(x2,y2);
	
    	if(a=="1" || a=="2" || a=="3" || a=="4" || a=="5")
        {
        	cout<<"Enter numerator and denominator for first fraction: ";
        	cin>>f1;
        	cout<<"Enter numerator and denominator for second fraction: ";
        	cin>>f2;
			opcount=2;
	        
    	    if(a=="1")
            {
    	        sign="+";
    	        answer=f1+f2;
	        }
	        else if(a=="2")
	        {
	        	sign="-";
	            answer=f1-f2; 	
	        }
	        else if(a=="3")
	        {
	        	sign="*";
		        answer=f1*f2; 
	        }
	        else if(a=="4")
	        {
	        	sign="/";
		        answer=f1/f2; 
	        }
	        else if(a=="5")
	        {
	        	sign="==";
		        bool ANS=(f1==f2);
		        answer1=ANS;
	        }
        }
        else if(a=="6" || a=="7" || a=="8" || a=="9")
        {
        	 opcount=1;
	         cout<<"Enter numerator and denominator for the fraction: ";
	         cin>>f0;
        	 if(a=="6")
        	 {
        	 	sign="++";
        	 	answer=++f0;
        	 	--f0;
        	 }
        	 else if(a=="7")
        	 {
        	 	sign="++";
		        answer=f0++;
		        --f0;
        	 }
        	 else if(a=="8")
        	 {
        	 	sign="--";
        	 	answer=--f0;
        	 	++f0;
        	 }
        	 else if(a=="9")
        	 {
        	 	sign=="--";
        	 	answer=f0--;
        	 	++f0;
        	 }
        }
	    else if(a=="10")
	    {
			s1.Pop(); 
	    }
	    else if(a=="11")
	    {
			s1.Print();			  
	    }

	    if(a=="1" || a=="2" || a=="3" || a=="4")
	    {
	    	
			Fraction *m=new Fraction[2];
	    	m[0]=f1;
	    	m[1]=f2; 
	        Operation o1(m,answer,opcount,sign);
			s1.Push(o1);
	        cout<<o1;
	    }
	    else if(a=="5")
	    {
	    	Fraction *m=new Fraction[2]; 
	    	m[0]=f1;
	    	m[1]=f2; 
	        Operation o1(m,answer1,opcount,sign);
			s1.Push(o1);  
	        cout<<o1;
	    }
	    else if(a=="6" || a=="7" || a=="8" || a=="9")
	    {
	    	
			Fraction *m=new Fraction[1]; 
	        m[0]=f0;
	        Operation o1(m,answer,opcount,sign);
			s1.Push(o1);        
	        cout<<o1;
	    }
	    else if(a!="1" && a!="2" && a!="3" && a!="4" && a!="5" && a!="6" && a!="7" && a!="8" && a!="9" && a!="10" && a!="11")
	    {
	    	cout<<"Invalid input"<<endl;
		}
		cout<<endl;
	    cout<<"Press 1 for addition"<<endl;
        cout<<"Press 2 for subtraction"<<endl;
        cout<<"Press 3 for multiplication"<<endl;
        cout<<"Press 4 for division"<<endl;
        cout<<"Press 5 for comparison"<<endl;
        cout<<"Press 6 for pre-incrementation"<<endl;
        cout<<"Press 7 for post-incrementation"<<endl;
        cout<<"Press 8 for pre-decrementation"<<endl;
        cout<<"Press 9 for post-decrementation"<<endl;
        cout<<"Press 10 to pop out last operation from stack"<<endl;
        cout<<"Press 11 to print stack"<<endl; 
        cout<<"Press -1 to terminate the program"<<endl;
		cin>>a; 
    }   	
	return 0;
}

