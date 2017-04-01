#include <iostream>
#include <string>

using namespace std;

int LCM(int x, int y)
{
    int max=0;
    if (x>y)
    {
        max=x;
    }
    else
    {
        max=y;
    }
    while ((max%x)!=0 || (max%y)!=0)
    {
        max=max+1;
    }
    return max;
}

int HCF(int x, int y)
{
    int min=0;
    if (x<y)
    {
        min=x;
    }
    else
    {
        min=y;
    }
    while ((x%min)!=0 || (y%min)!=0)
    {
        min=min-1;
    }
    return min;
}


int main()
{
  //Act as a operator
  int op;
  
while(op!=-1)  
{
  cout<<"Press 1 for addition, 2 for subtraction, 3 for multilplication, 4 for division, 5 for inverse or -1 for exit";
  cin>>op;
 
  int a,b;
  int c,d;
  if(op==5)
  {
     cout<<"Enter the numerators and denominators for the number: ";
     cin>>a>>b;  
     if(b==0)
     {
      cout<<"Denominator cannot be zero"<<endl;
      cout<<"Enter the first number's denominator again: "<<endl;
      cin>>b;
     }     
  }
  else if (op>0 && op<5)
  {
  //First number
  cout<<"Enter the numerators and denominators for first number: ";
  cin>>a>>b;
  if(b==0)
  {
   cout<<"Denominator cannot be zero"<<endl;
   cout<<"Enter the first number's denominator again: "<<endl;
   cin>>b;
  }
  //Second Number
  cout<<"Enter the numerators and denominators for second number: ";
  cin>>c>>d;
  if(d==0)
  {
   cout<<"Denominator cannot be zero"<<endl;
   cout<<"Enter the second number's denominator again: "<<endl;
   cin>>d;
  }
  
  
  }
  
  else if(op==-1)
  {
      return 0;
  }
  
  else 
  {
      cout<<"Invalid Input"<<endl;   
  }
  
  //For addition and subtraction
  int e=LCM(b,d); 
  int f=e/b; 
  int g=e/d; 
  int h=a*f; 
  int i=c*g;
  int sum=i+h;
  int j=HCF(sum,e);
  int dif=(h-i);
  int r=HCF(dif,e);
  
  //For Multiplication and Division
  int k;
  int l;
  int m;
  int s;
  int t;
  int u;
  int n;
  int p;
  int v;
  int w;
  
  //For Inverse
  int z;
  int aa;
  int bb;
  
  
  switch (op)
  {
    case 1 :  
      if (j!=1)
      {
        e=e/j; sum=sum/j;
      }
	  cout<<"Sum is: "<<sum<<"/"<<e<<endl; break;
      
    case 2 : 
      if (r!=1)
      {
        e=e/r; dif=dif/r;
      }
	  cout<<"Difference is: "<<dif<<"/"<<e<<endl; break;
   
      
     case 3 :
      k=a*c;
      l=b*d;
      m=HCF(k,l);
      if(m!=1)
      {
        n=k/m;
        p=l/m;
      }
      cout<<"Product is: "<<n<<"/"<<p<<endl; break;	
        
    case 4 :
      s=a*d;
      t=b*c;
      u=HCF(s,t);
      if(u!=1)
      {
        v=s/u;
        w=t/u;
      }
      cout<<"Answer is: "<<v<<"/"<<w<<endl; break;
      
     case 5 :
      z=HCF(a,b);
      if(z!=1)
      {
      	bb=b/z;
      	aa=a/z;
	    cout<<bb<<"/"<<aa<<endl;
      }  
	    else
      {
      	cout<<b<<"/"<<a<<endl;
	    }
	    break;
      
      default:
      cout<<"Invalid input"<<endl;
  }
 }
return 0;
}
