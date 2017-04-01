#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void freecell_to_home(string Home_Array[4],string freecell[4])
{
	int freenum;
	cout<<"Enter the freecell to move from: ";
	cin>>freenum;
	if(freenum>4 || freenum<=0)
	{
		cout<<"Invalid input"<<endl;
		return;
	}
	if(freecell[freenum-1]=="  ")
	{
		cout<<"There is no card in the freecell you wanted to move from"<<endl;
		return;	
	}
	int a1;
	string x=freecell[freenum-1];
	string sub1=x.substr(0,1);
	string sub2=x.substr(1,1);
	if(x.length()==4)
	{
		sub1=x.substr(0,2);
		sub2=x.substr(2,1);
	}
	
	string y;
	if(sub2=="c")
	{
		if(Home_Array[0]=="-")
		{
			cout<<"Home of Clubs is empty"<<endl;
			return;
		}
	    y=Home_Array[0];
	    a1=0;
	}
	else if(sub2=="d")
	{
		if(Home_Array[1]=="-")
		{
			cout<<"Home of Diamonds is empty"<<endl;
			return;
		}
		y=Home_Array[1];
		a1=2;
	}
	else if(sub2=="h")
	{
		if(Home_Array[2]=="-")
		{
			cout<<"Home of Hearts is empty"<<endl;
			return;
		}
		y=Home_Array[2];
		a1=3;
	}
	else if(sub2=="s")
	{
		if(Home_Array[3]=="-")
		{
			cout<<"Home of Spades is empty"<<endl;
			return;
		}
		y=Home_Array[3];
		a1=4;
	}
	
	string y_sub1=y.substr(0,1);
	if(y.length()==4)
	{
		y_sub1=y.substr(0,2);
	}
    
	int letter1;
	if(y_sub1=="2")
	{
		letter1=2;
	}
	else if(y_sub1=="3")
	{
		letter1=3;
	}
	else if(y_sub1=="4")
	{
		letter1=4;
	}
	else if(y_sub1=="5")
	{
		letter1=5;
	}
		if(y_sub1=="6")
	{
		letter1=6;
	}
	else if(y_sub1=="7")
	{
		letter1=7;
	}
	else if(y_sub1=="8")
	{
		letter1=8;
	}
	else if(y_sub1=="9")
	{
		letter1=9;
	}
		if(y_sub1=="10")
	{
		letter1=10;
	}
	else if(y_sub1=="J")
	{
		letter1=11;
	}
	else if(y_sub1=="Q")
	{
		letter1=12;
	}
	else if(y_sub1=="K")
	{
		letter1=13;
	}

	
	int letter;
	if(sub1=="2")
	{
		letter=2;
	}
	else if(sub1=="3")
	{
		letter=3;
	}
	else if(sub1=="4")
	{
		letter=4;
	}
	else if(sub1=="5")
	{
		letter=5;
	}
		if(sub1=="6")
	{
		letter=6;
	}
	else if(sub1=="7")
	{
		letter=7;
	}
	else if(sub1=="8")
	{
		letter=8;
	}
	else if(sub1=="9")
	{
		letter=9;
	}
		if(sub1=="10")
	{
		letter=10;
	}
	else if(sub1=="J")
	{
		letter=11;
	}
	else if(sub1=="Q")
	{
		letter=12;
	}
	else if(sub1=="K")
	{
		letter=13;
	}
	
	if(letter!=letter+1)
	{
		cout<<"Cards after transfer in homecell are not is ascending order"<<endl;
		return;
	}
	
	Home_Array[a1]=y;
	freecell[freenum-1]="  ";
	
}

void column_to_home(string *Array_Count[8],int Column_Count[8],string Home_Array[4])
{
	int column;
	cout<<"Enter the column to move from: ";
	cin>>column;
	if(column<=0 || column>8)
	{
		cout<<"Invalid input"<<endl;
		return;
	}
	string y=Array_Count[column-1][Column_Count[column-1]-1];
	string suby2=y.substr(1,1);
	string suby1=y.substr(0,1);
	if(y.length()==4)
	{
		suby2=y.substr(2,1);
		suby1=y.substr(0,2);
	}
	int index;
	if(suby2=="c")
	{
		index=0;
	}
	else if(suby2=="d")
	{
		index=1;
	}
	else if(suby2=="h")
	{
		index=2;
	}
	else if(suby2=="s")
	{
		index=3;
	}
	
	int letter;
	int letter1;
	
	string x=Home_Array[index];
	string subx1;
	if(x!="-")
	{
	subx1=x.substr(0,1);
	if(x.length()==4)
	{
		subx1=x.substr(0,2);
	}
	
	if(subx1=="A")
	{
		letter=1;
	}
	else if(subx1=="2")
	{
		letter=2;
	}
	else if(subx1=="3")
	{
		letter=3;
	}
	else if(subx1=="4")
	{
		letter=4;
	}
		else if(subx1=="5")
	{
		letter=5;
	}
	else if(subx1=="6")
	{
		letter=6;
	}
	else if(subx1=="7")
	{
		letter=7;
	}
		else if(subx1=="8")
	{
		letter=8;
	}
	else if(subx1=="9")
	{
		letter=9;
	}
	else if(subx1=="10")
	{
		letter=10;
	}
		else if(subx1=="J")
	{
		letter=11;
	}
	else if(subx1=="Q")
	{
		letter=12;
	}
	else if(subx1=="K")
	{
		letter=13;
	}
	
	if(suby1=="A")
	{
		letter1=1;
	}
	else if(suby1=="2")
	{
		letter1=2;
	}
	else if(suby1=="3")
	{
		letter1=3;
	}
	else if(suby1=="4")
	{
		letter1=4;
	}
		else if(suby1=="5")
	{
		letter1=5;
	}
	else if(suby1=="6")
	{
		letter1=6;
	}
	else if(suby1=="7")
	{
		letter1=7;
	}
		else if(suby1=="8")
	{
		letter1=8;
	}
	else if(suby1=="9")
	{
		letter1=9;
	}
	else if(suby1=="10")
	{
		letter1=10;
	}
		else if(suby1=="J")
	{
		letter1=11;
	}
	else if(suby1=="Q")
	{
		letter1=12;
	}
	else if(suby1=="K")
	{
		letter1=13;
	}
		
	if(letter1!=letter+1)
	{
		cout<<"Card is not immediate ascendant of the home card"<<endl;
		return;
	}
    }
	
	Home_Array[index]=y;
	int ad=Column_Count[column-1]-1;
	string *t=new string[ad];
	for(int i=0;i<ad;i++)
	{
		t[i]=Array_Count[column-1][i];
	}
	delete []Array_Count[column-1];
	Array_Count[column-1]=t;
	Column_Count[column-1]--;
}

void freecell_to_column(string *Array_Count[8],int Column_Count[8],string freecell[4])
{
	int freenum;
	cout<<"From which freecell do you want to remove the card? ";
	cin>>freenum;
	if(freenum<=0 || freenum>4)
	{
		cout<<"Invalid input"<<endl;
		return;
	}
	if(freecell[freenum-1]=="-")
	{
		cout<<"There is no card in the freecell you referred to"<<endl;
 		return;
    }
    int column;
    cout<<"Enter the column to move to: ";
    cin>>column;
    if(column<=0 || column>8)
    {
    	cout<<"Invalid input"<<endl;
    	return;
	}
    string x=freecell[freenum-1];
    string y=Array_Count[column-1][Column_Count[column-1]-1];
    
    int first[1];
    string third[1];
    int first1[1];
    string third1[1];
    
    int letter;        
    string substring1=x.substr(0,1);
    string substring3=x.substr(2,1);
    if(x.length()==4)
    {
        letter=10;
		// string substring1=x.substr(0,2);
        substring3=x.substr(3,1);
    }      

    if(substring1=="A")
	{
		letter=1;
	}   
    else if(substring1=="2")
	{
		letter=2;
	}
	else if(substring1=="3")
	{
		letter=3;			
	}
	else if(substring1=="4")
	{
		letter=4;
    }
    else if(substring1=="5")
	{
		letter=5;
	}   
    else if(substring1=="6")
	{
		letter=6;
    }
	else if(substring1=="7")
	{
		letter=7;
	}
	else if(substring1=="8")
	{
		letter=8;
	}
	else if(substring1=="9")
	{
		letter=9;
	}   
    else if(substring1=="10")
	{
		letter=10;
	}
	else if(substring1=="J")
	{
	    letter=11;
	}
	else if(substring1=="Q")
	{
		letter=12;
	}
	else if(substring1=="K")
	{
		letter=13;
	}      
    first[0]=letter;
    third[0]=substring3;   
    
    if(Column_Count[column-1]!=0)
	  {
        int letter1;        
        string y=Array_Count[column-1][Column_Count[column-1]-1];
        string substring11=y.substr(0,1);
        string substring13=y.substr(2,1);
        if(y.length()==4)
        {
          letter1=10;
		  // string substring11=y.substr(0,2);
          substring13=y.substr(3,1);
        }
        

        if(substring11=="A")
		{
			letter1=1;
		}   
        else if(substring11=="2")
		{
			letter1=2;
		}
		else if(substring11=="3")
		{
			letter1=3;
		}
		else if(substring11=="4")
		{
			letter1=4;
        }
        else if(substring11=="5")
		{
			letter1=5;
		}   
        else if(substring11=="6")
		{
			letter1=6;
		}
		else if(substring11=="7")
		{
			letter1=7;
		}
		else if(substring11=="8")
		{
			letter1=8;
		}
		else if(substring11=="9")
		{
			letter1=9;
		}   
        else if(substring11=="10")
		{
			letter1=10;
		}
		else if(substring11=="J")
		{
			letter1=11;
		}
		else if(substring11=="Q")
		{
			letter1=12;
		}
		else if(substring11=="K")
		{
			letter1=13;
		}   
       
        first1[0]=letter1;
        third1[0]=substring13; 
    
    if(first1[0]!=first[0]+1)
    {
    	cout<<"Cards after transfer not in descending order"<<endl;
    	return;
	}
	if((third1[0]=="B" && third[0]!="R") || (third1[0]=="R" && third[0]!="B"))
	{
		cout<<"Cards after transfer are not altenating in colour"<<endl;
		return;
	}
	
    }
    
    
    string *n=new string[Column_Count[column-1]+1];
	for(int i=0;i<Column_Count[column-1];i++)
	{
		n[i]=Array_Count[column-1][i];
	}
	n[Column_Count[column-1]]=freecell[freenum-1];
	delete []Array_Count[column-1];
	Array_Count[column-1]=n;
	freecell[freenum-1]="-"; 
	Column_Count[column-1]=Column_Count[column-1]+1;
    
}

void column_to_freecell(string *Array_Count[8],int Column_Count[8],string freecell[4])
{
	int freenum;
	cout<<"In which freecell do you want to put a card? ";
	cin>>freenum;
	if(freenum<=0 || freenum>4)
	{
		cout<<"Invalid input"<<endl;
		return;
	}
	if(freecell[freenum-1]!="-")
	{
		cout<<"It is already filled"<<endl;
 		return;
    }
		
	int column;
	cout<<"From which column do you want to take the card out: ";
	cin>>column;
	if(column<=0 || column>8)
	{
		cout<<"Invalid input"<<endl;
		return;
	}
	string x=Array_Count[column-1][Column_Count[column-1]-1];
	string y=x.substr(0,1);
	if(y=="A")
	{
		cout<<"Ace cannot be moved to freecell"<<endl;
		return;
	}	
    
	string *m=new string[Column_Count[column-1]-1];
	for(int i=0;i<Column_Count[column-1]-1;i++)
	{
		m[i]=Array_Count[column-1][i];
	}
	freecell[freenum-1]=Array_Count[column-1][Column_Count[column-1]-1];
	delete []Array_Count[column-1];
	Array_Count[column-1]=m;
	Column_Count[column-1]=Column_Count[column-1]-1;
	
}

void column_to_column(string *Array_Count[8],int Column_Count[8])
{ 
    int column1,n; 
    cout<<"Enter column to move from: ";
    cin>>column1;
  	if(column1<=0 || column1>8)
	{
		cout<<"Invalid input"<<endl;
		return;
	}
    cout<<"Enter no of elements to move: ";
    cin>>n;

    int column2;
    cout<<"Enter the column to move to: ";
    cin>>column2;  
	if(column2<=0 || column2>8)
	{
		cout<<"Invalid input"<<endl;
		return;
	}       

    if(Column_Count[(column1-1)]<n)
     {
        cout<<"There are not enough elements in the column."<<endl;
        return;
     }
    int first[n];
    string third[n];
    
	int first1[1];
    string third1[1];
     string substring11;
     string substring13;
	  if(Column_Count[column2-1]!=0)
	  {
        int letter1;        
        string bb=Array_Count[column2-1][Column_Count[column2-1]-1];
        if(bb.length()==3)
        {
        	substring11=bb.substr(0,1);
            string substring13=bb.substr(2,1);
		}
		
        else if(bb.length()==4)
        {
          letter1=10;
          substring13=bb.substr(3,1);
        }
        

        if(substring11=="A")
		{
			letter1=1;
		}   
        else if(substring11=="2")
		{
			letter1=2;
		}
		else if(substring11=="3")
		{
			letter1=3;
		}
		else if(substring11=="4")
		{
			letter1=4;
        }
        else if(substring11=="5")
		{
			letter1=5;
		}   
        else if(substring11=="6")
		{
			letter1=6;
		}
		else if(substring11=="7")
		{
			letter1=7;
		}
		else if(substring11=="8")
		{
			letter1=8;
		}
		else if(substring11=="9")
		{
			letter1=9;
		}   
        else if(substring11=="10")
		{
			letter1=10;
		}
		else if(substring11=="J")
		{
			letter1=11;
		}
		else if(substring11=="Q")
		{
			letter1=12;
		}
		else if(substring11=="K")
		{
			letter1=13;
		}   
       
        first1[0]=letter1;
        third1[0]=substring13; 
    } 
    int letter;
    string substring1;
    string substring3;
    for(int j=0;j<n;j++)
    {
        string aa=Array_Count[column1-1][Column_Count[column1-1]-j-1];
        if(aa.length()==3)
		{
		    substring1=aa.substr(0,1);	
		    substring3=aa.substr(2,1);
		   
		}
        else if(aa.length()==4)
        {
           substring3=aa.substr(3,1);
           letter=10;
        }
        

        if(substring1=="A")
		{
			letter=1;
		}   
		else if(substring1=="2")
		{
			letter=2;
		}
		else if(substring1=="3")
		{
			letter=3;
        }
        else if(substring1=="4")
		{
			letter=4;
		}   
        else if(substring1=="5")
		{
			letter=5;
		}
		else if(substring1=="6")
		{
			letter=6;
		}
		else if(substring1=="7")
		{
			letter=7;
		}
		else if(substring1=="8")
		{
			letter=8;
		}   
        else if(substring1=="9")
		{
			letter=9;
		}
		else if(substring1=="10")
		{
			letter=10;
		}
		else if(substring1=="J")
		{
			letter=11;
		}
		else if(substring1=="Q")
		{
			letter=12;
		}   
        else if(substring1=="K")
		{
			letter=13;
		}
       
        first[j]=letter;
        third[j]=substring3;
    }
   
   
    for(int j=1;j<n;j++)
    {
      
	  if(first[j]!=first[j-1]+1)
      {
        cout<<"Cards are not in descending order"<<endl;
        return;
      }
      if((third[j]=="R" && third[j-1]!="B") || (third[j]=="B" && third[j-1]!="R"))
      {
        cout<<"Colour of cards is not alternating:"<<endl;
        return;
      }
    }
    if(Column_Count[column2-1]!=0)
    {
    if(third1[0]==third[n-1])
    {
    	cout<<"Cards in the 2nd column are not alternating in colour"<<endl;
		return;
	}
	if(first1[0]!=first[n-1]+1)
	{
		cout<<"Cards in 2nd column after transfer are not descending"<<endl;
		cout<<first1[0]<<endl;
		cout<<first[n-1]<<endl;
		return;
	}
   }
	   int ac=Column_Count[column2-1]+n;
	    int ab=Column_Count[column1-1]-n;
    string *r=new string[ac];
    for(int i=0;i<ac-n;i++)
    {
        r[i]=Array_Count[column2-1][i];
    }
    for(int i=0;i<n;i++)
    {
        r[i+ac-n]=Array_Count[column1-1][ab+i];
    }
    
    delete []Array_Count[column2-1];
    Array_Count[column2-1]=r;
    
	Column_Count[column2-1]=Column_Count[column2-1]+n; 
 

   
    string *q=new string[ab];
    for(int i=0;i<ab;i++)
    {
       q[i]=Array_Count[column1-1][i];
    }
    delete []Array_Count[column1-1];
    Array_Count[column1-1]=q;
   
    Column_Count[column1-1]=Column_Count[column1-1]-n;
}

void save_game(string *Array_Count[8],int Column_Count[8],string freecell[4],string Home_Array[4])
{
    ofstream out;
	out.open("freecell.txt");
	for(int i=0;i<8;i++)
	{
		out<<Column_Count[i]<<" ";
	}
	out<<endl;
	for(int i=0;i<4;i++)
	{
		out<<freecell[i]<<" ";
	}
	out<<"  ";
	for(int i=0;i<4;i++)
	{
		out<<Home_Array[i]<<" ";
	}
	out<<endl;
	
	int largestcount=0;
	for(int i=0;i<7;i++)
    {
		if(Column_Count[i+1]>Column_Count[largestcount])
		largestcount=i+1;
	}
	for(int i=0;i<Column_Count[largestcount];i++)
	{
		for(int k=0;k<8;k++)
		{
		if(k==4)
		{
			out<<"  ";
		}
		if(Column_Count[k]>i)
		{
			out<<" "<<Array_Count[k][i];
		}	
		else
		{
			out<<"  ";
		}	
		}
		out<<endl;
	}
    out.close();
	
}


int main()
{
    int option;
    cout<<"Press 1 to choose a new game: ";
    cout<<"Press 2 to open your saved game: ";
    cin>>option;
    if(option!=1 && option!=2)
    {
    	cout<<"Invalid input"<<endl;
    	return 0;
	}
    
    if(option==1)
    {
    		string *p1=new string[7];
    string *p2=new string[7];
    string *p3=new string[7];
    string *p4=new string[7];
    string *p5=new string[6];
    string *p6=new string[6];
    string *p7=new string[6];
    string *p8=new string[6];

    srand (time(NULL));  
    string a[52]={"AcB","2cB","3cB","4cB","5cB","6cB","7cB","8cB","9cB","10cB","JcB","QcB","KcB","AdR","2dR","3dR","4dR","5dR","6dR","7dR","8dR","9dR","10dR","JdR","QdR","KdR","AhR","2hR","3hR","4hR","5hR","6hR","7hR","8hR","9hR","10hR","JhR","QhR","KhR","AsB","2sB","3sB","4sB","5sB","6sB","7sB","8sB","9sB","10sB","JsB","QsB","KsB"};
  
  for(int i=0;i<52;i++)
  {
      int x=rand()%52+1;
      string b=a[i];
      string c=a[x-1];
      a[i]=c;
      a[x-1]=b;
  }

  for(int i=0;i<7;i++)
  { 
     *(p1+i)=a[i];
     *(p2+i)=a[i+7];
     *(p3+i)=a[i+14];
     *(p4+i)=a[i+21];
     if(i<=5)
     {
          *(p5+i)=a[i+28];
          *(p6+i)=a[i+34];
          *(p7+i)=a[i+40];
          *(p8+i)=a[i+46];
     }
  }

  int p1count=7;
  int p2count=7;
  int p3count=7;
  int p4count=7;
  int p5count=6;
  int p6count=6;
  int p7count=6;
  int p8count=6;
  
  string freecell[4]={"-","-","-","-"};
  string homeC="-";
  string homeD="-";
  string homeH="-";
  string homeS="-";
  string Home_Array[4]={homeC,homeD,homeH,homeS};
  int Column_Count[8]={p1count,p2count,p3count,p4count,p5count,p6count,p7count,p8count};
  string *Array_Count[8]={p1,p2,p3,p4,p5,p6,p7,p8};
    
  string press;
  while(Home_Array[0]!="KcB" && Home_Array[1]!="KdR" && Home_Array[2]!="KhR" && Home_Array[3]!="KsB")
  { 	
  	
	cout<<"|"<<setw(3)<<freecell[0]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<freecell[1]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<freecell[2]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<freecell[3]<<setw(3)<<"|"<<setw(15)<<"|"<<setw(3)<<Home_Array[0]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<Home_Array[1]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<Home_Array[2]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<Home_Array[3]<<setw(3)<<"|"<<endl;
    cout<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(11)<<" "<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<endl;
    cout<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(11)<<" "<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<endl;
    cout<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(11)<<" "<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<endl;
    cout<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(11)<<" "<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<endl;
    cout<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(11)<<" "<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<endl;

 
	int largestcount=0;
	for(int i=0;i<7;i++)
    {
		if(Column_Count[i+1]>Column_Count[largestcount])
		largestcount=i+1;
	}
	for(int i=0;i<Column_Count[largestcount];i++)
	{
		for(int k=0;k<8;k++)
		{
		if(k==4)
		{
			cout<<setw(10)<<" ";
		}
		if(Column_Count[k]>i)
		{
			cout<<setw(2)<<"[ "<<setw(4)<<Array_Count[k][i]<<setw(2)<<" ]";
		}	
		else
		{
			cout<<setw(8)<<" ";
		}	
		}
		cout<<endl;
	}
	
	 cout<<"Press 1 for column to column move"<<endl;
     cout<<"Press 2 for column to freecell move"<<endl;
     cout<<"Press 3 for freecell to column move"<<endl;
     cout<<"Press 4 for column to home move"<<endl;
     cout<<"Press 5 for freecell to home move"<<endl;
     cout<<"Press 6 to save your finished game"<<endl;
      
     cin>>press;
     
      if(press=="1")
      {
		column_to_column(Array_Count,Column_Count);
      } 
      else if(press=="2")
      {
      	column_to_freecell(Array_Count,Column_Count,freecell);  
	  }
	  else if(press=="3")
	  {
	  	freecell_to_column(Array_Count,Column_Count,freecell);
	  }
	  else if(press=="4")
	  {
	  	column_to_home(Array_Count,Column_Count,Home_Array);
	  }
	  else if(press=="5")
	  {
	  	freecell_to_home(Home_Array,freecell);
	  }
      else if(press=="6")
      {
      	save_game(Array_Count,Column_Count,freecell,Home_Array);
	  }
	}

}

else if(option==2)
{
	ifstream in;
	in.open("freecell.txt");
	
	string *p1=new string[20];
    string *p2=new string[20];
    string *p3=new string[20];
    string *p4=new string[20];
    string *p5=new string[20];
    string *p6=new string[20];
    string *p7=new string[20];
    string *p8=new string[20];

  

    int p1count;
    int p2count;
    int p3count;
    int p4count;
    int p5count;
    int p6count;
    int p7count;
    int p8count;
    string freecell[4];
    string homeC;
    string homeD;
    string homeH;
    string homeS;
    string Home_Array[4]={homeC,homeD,homeH,homeS};
    int Column_Count[8]={p1count,p2count,p3count,p4count,p5count,p6count,p7count,p8count};
    string *Array_Count[8]={p1,p2,p3,p4,p5,p6,p7,p8};
    
    int input0;
    for(int i=0;i<8;i++)
    {
    	in>>input0;
		Column_Count[i]=input0;
	}
    
    string input; 
    for(int i=0;i<4;i++)
    {
    	in>>input;
    	freecell[i]=input;
    }
    string input1;
    for(int i=0;i<4;i++)
   {
    	in>>input1;
    	Home_Array[i]=input1;
   }
  
  
   	int largestcount=0;
	for(int i=0;i<7;i++)
    {
		if(Column_Count[i+1]>Column_Count[largestcount])
		largestcount=i+1;
	}
	for(int i=0;i<Column_Count[largestcount];i++)
	{
		for(int k=0;k<8;k++)
		{
		    if(Column_Count[k]>i)
		    {
			    in>>Array_Count[k][i];
		    }		
		}
	}
	  
    string press;
  while(Home_Array[0]!="KcB" && Home_Array[1]!="KdR" && Home_Array[2]!="KhR" && Home_Array[3]!="KsB")
  { 	

	cout<<"|"<<setw(3)<<freecell[0]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<freecell[1]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<freecell[2]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<freecell[3]<<setw(3)<<"|"<<setw(15)<<"|"<<setw(3)<<Home_Array[0]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<Home_Array[1]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<Home_Array[2]<<setw(3)<<"|"<<setw(1)<<"|"<<setw(3)<<Home_Array[3]<<setw(3)<<"|"<<endl;
    cout<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(11)<<" "<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<endl;
    cout<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(11)<<" "<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<endl;
    cout<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(11)<<" "<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<endl;
    cout<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(11)<<" "<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<"|    |"<<setw(2)<<" "<<endl;
    cout<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(11)<<" "<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<setw(2)<<" "<<"______"<<endl;

 
	int largestcount=0;
	for(int i=0;i<7;i++)
    {
		if(Column_Count[i+1]>Column_Count[largestcount])
		largestcount=i+1;
	}
	for(int i=0;i<Column_Count[largestcount];i++)
	{
		for(int k=0;k<8;k++)
		{
		if(k==4)
		{
			cout<<setw(10)<<" ";
		}
		if(Column_Count[k]>i)
		{
			cout<<setw(2)<<"[ "<<setw(4)<<Array_Count[k][i]<<setw(2)<<" ]";
		}	
		else
		{
			cout<<setw(8)<<" ";
		}	
		}
		cout<<endl;
	}
	
	cout<<"Press 1 for column to column move"<<endl;
     cout<<"Press 2 for column to freecell move"<<endl;
     cout<<"Press 3 for freecell to column move"<<endl;
     cout<<"Press 4 for column to home move"<<endl;
     cout<<"Press 5 for freecell to home move"<<endl;
     cout<<"Press 6 to save your finished game"<<endl;
      
     cin>>press;
     
      if(press=="1")
      {
		column_to_column(Array_Count,Column_Count);
      } 
      else if(press=="2")
      {
      	column_to_freecell(Array_Count,Column_Count,freecell);  
	  }
	  else if(press=="3")
	  {
	  	freecell_to_column(Array_Count,Column_Count,freecell);
	  }
	  else if(press=="4")
	  {
	  	column_to_home(Array_Count,Column_Count,Home_Array);
	  }
	  else if(press=="5")
	  {
	  	freecell_to_home(Home_Array,freecell);
	  }
      else if(press=="6")
      {
      	save_game(Array_Count,Column_Count,freecell,Home_Array);
	  }
	}
	in.close();
}

   	cout<<"You have won the game"<<endl;
    return 0;       
}

