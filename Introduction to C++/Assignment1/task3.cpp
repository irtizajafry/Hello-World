#include <iostream>
#include <sstream>
#include <cmath> 

using namespace std;

string hex_to_bin(string x)
{
    int a=x.length();

    string v[a];
    string b[15];
    
    for (int i=0; i<a; i++)
    {
       v[i]=x[i]; 
    }
   
   //store binary number
   string s="";
   
    for (int i=0; i<a; i++)
    {
        string a=v[i];
         if (a=="0")  { b[i]="0000";}
         else if (a=="1") {b[i]="0001";}
         else if (a=="2")  {b[i]="0010";}
         else if (a=="3")  {b[i]="0011";}
         else if (a=="4") {b[i]="0100";}
         else if (a=="5")  {b[i]="0101";}
         else if (a=="6") {b[i]="0110";}
         else if (a=="7") {b[i]="0111";}
         else if (a=="8")  {b[i]="1000";}
         else if (a=="9") {b[i]="1001";}
         else if (a=="a" || a=="A")  {b[i]="1010";}
         else if (a=="b" || a=="B") {b[i]="1011";}
         else if (a=="c" || a=="C") {b[i]="1100";}
         else if (a=="d" || a=="D") {b[i]="1101";}
         else if (a=="e" || a=="E") {b[i]="1110";}
         else if (a=="f" || a=="F") {b[i]="1111";}
         
        s=s+b[i];
    }
    return s;
}



string bin_to_dex(string x)
{
     
     int a=x.length();
     int b=0;
     int d=0;
     int c=0;
     int j=0;
    for(int i=a-1; i>=0; i--)
    {
        b=pow(2,j);
        if (x[i]=='0')
        {
            c=0*b;
        }
        else if(x[i]=='1')
        {
            c=1*b;
        }
        d=d+c;
        j++;
    }
    
    stringstream ss;
 ss<<d<<endl;
 string s=ss.str();
 return s;
 }



string dex_to_hex(int y)
{
    string s="";
    
    while(y>15)
    {
        
        int a=y/16;
        int b=a*16;
        int c=y-b;
        stringstream ss;
        ss<<c;
        string l=ss.str();
        
        if (l=="10")
        {
            l="a";
        }
        else if(l=="11")
        {
            l="b";
        }
        else if(l=="12")
        {
            l="c";
        }
        else if(l=="13")
        {
            l="d";
        }
        else if(l=="14")
        {
            l="e";
        }
        else if(l=="15")
        {
            l="f";
        }
        
        s=s+l;
        y=a;
    }
    
    stringstream ssi;
    ssi<<y;
    string u=ssi.str();
    
    s=s+u;
    
    string h="";
    string j;
    int a=s.length();
    int b=s.length();
    for (int i=0; i<b; i++)
    {
        h[i]=s[a-1];
        a=a-1;
        j=j+h[i];
    }
    
    return j;
}



int main()
{
   int w=0;
   while(w!=-1)
   {
    cout<<"Enter 1 for decimal number system enter 2 for binary number system,Enter 3 for hexadecimal number system";
    cin>>w;
    
    if (w==1)
    {
        cout<<"Enter no: ";
        int m;
        cin>>m;
        string n=dex_to_hex(m);
        cout<<"Hexadecimal no: "<<n<<endl;
        string o=hex_to_bin(n);
        cout<<"binary no: "<<o<<endl;
    }
    
    else if(w==2)
    {
       cout<<"Enter no: ";
       int m;
       cin>>m;
       stringstream ss;
       ss<<m<<endl;
       string s=ss.str();
       
        string p=bin_to_dex(s);
        cout<<"Decimal no: "<<p<<endl;
        int r;
        stringstream stringToInt; 
        stringToInt.str(p); 
        stringToInt >> r; 
        stringToInt.clear();
        
        string q=dex_to_hex(r);
        cout<<"Hexadecimal no: "<<q<<endl;
    }
    else if(w==3)
    {
       cout<<"Enter no: ";
       string m;
       cin>>m;
       
       string t=hex_to_bin(m);
        cout<<"binary no: "<<t<<endl;
        string bb=bin_to_dex(t);
        cout<<"Decimal no: "<<bb<<endl;
    }
	else 
    {
    	cout<<"Invalid input"<<endl;
	}
}
    
    return 0;
}
        
        
       

