#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

// Numbers 1-40 determine the id 

void Reserve_seat(string N,string Id,string a[3][4],string b[7][4],string n[40],string id[40], string f,int &bcount,int &ecount,int row[40],int column[40],string Class[40],int &count)
{
	if(count>=40)
	{
		cout<<"next flight will leave tomorrow"<<endl;
		return;
	}
	
	
	  cout<<"Enter name: ";
    cin>>N;
    cout<<"Enter id: ";
    cin>>Id;
    int r;
    int c;
	
    
    for(int i=0; i<count;i++)
    {
    while(N==n[i])
    {
        cout<<"The name has been reserved.Enter again: ";
        cin>>N;
    }   
    while(Id==id[i])
    {
        cout<<"The id has been reserved.Enter again: ";
        cin>>Id;
    }
    }
   
   cout<<"Enter the class.b for business and e for economy: "; 
   cin>>f;
   int j;
    
   while ((f!="b")&& (f!="e"))
   {
    cout<<"Invalid input.Enter again: ";
    cin>>f;
   }

 
   if(f=="b")
    {
        if(bcount<12)
        {
            cout<<"Available seat: * ; Reserved Seat: o"<<endl;
            cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
			j=0;
			for(int i=0;i<3;i++)
            {
                cout<<"A"<<i+1<<setw(10)<<a[i][j]<<setw(10)<<a[i][j+1]<<setw(10)<<a[i][j+2]<<setw(10)<<a[i][j+3]<<endl;
            }
            
            cout<<"Enter the row: ";
            cin>>r;
            
            while(r!=1 && r!=2 && r!=3)
            {
            	cout<<"Row does not exist.Enter again: ";
            	cin>>r;
			}
      		cout<<"enter the coloumn: ";
			cin>>c;
			while(c<1 && c>4)
			{
				cout<<"Column does not exist.Enter again: ";
				cin>>c;
			}
            if (a[r-1][c-1]=="o")
            {
                cout<<"Seat is reversed. "<<endl;
                return;
            }
            a[r-1][c-1]="o";
            bcount++;
            row[count]=r;
            column[count]=c;
            Class[count]="b";
        }
        else
        {
            cout<<"Business class is full"<<endl;
            return;
        }
    }
    else if(f=="e")
    {   
        if(ecount<28)
        {
            cout<<"Available seat: * ; Reserved Seat: o"<<endl;
            cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
			j=0;
			for(int i=0;i<7;i++)
            {
                cout<<"B"<<i+1<<setw(10)<<b[i][j]<<setw(10)<<b[i][j+1]<<setw(10)<<b[i][j+2]<<setw(10)<<b[i][j+3]<<endl;
            }
            cout<<"Enter the row: ";
            cin>>r;
            while(r<1 && r>7) 
            {
            	cout<<"Invalid row. Enter again: ";
            	cin>>r;
			}
            cout<<"Enter the column: ";
            cin>>c;
            while(c<1 && c>4)
			{
				cout<<"Column does not exist.Enter again: ";
				cin>>c;
			}
            if (b[r-1][c-1]=="o")
            {
                cout<<"Seat is reversed."<<endl;
                return;
            }
            b[r-1][c-1]="o";
            ecount++;
            row[count]=r;
            column[count]=c;
            Class[count]="e";
         }
         else
         {
            cout<<"Economy class is full"<<endl;
            return;
         }
    }
    if(f=="b")
    {
    	cout<<"Your seat A"<<r<<"."<<c<<" has been reserved successfully"<<endl;
	}
	else
	{
		   cout<<"Your seat B"<<r<<"."<<c<<" has been reserved successfully"<<endl;
	}
    n[count]=N;
    id[count]=Id;
    count++;   
}

void Change_seat(string N,string Id,string a[3][4],string b[7][4],string n[40],string id[40], string f,int &bcount,int &ecount,int row[40],int column[40],string Class[40],int &count)
{
    cout<<"You can change seat only from economy class to business class or within business class"<<endl;
    cout<<"Enter name: ";
	cin>>N;
	cout<<"Enter rollno: ";
    cin>>Id;
    cout<<"Enter class: ";
    cin>>f;
    int r,c;
    int j;
    cout<<"Please enter row and column of your current seat: ";
    cin>>r>>c;
    int row1;
	int column1;
    
    
    //Have you registered for a seat with the specified name,id and seat no

	int am=0;
    for(int i=0;i<count;i++)
    {
    	if(id[i]==Id && n[i]==N)
    	{
    		if(row[i]==r && column[i]==c && Class[i]==f)  
    		{
				am++; 			
			}
		}
	}
	if (am==0)
	{
		cout<<"Your name,id or your seat does not exist or do not match with each other"<<endl;
		return;
	}
	else
	{
    if(f=="b")
    {
		
       if(a[r-1][c-1]=="*")
        {
        	cout<<"You have not reserved a seat at your specified place"<<endl;
        	return;
        }
        int mm=0;
		if(bcount<11)
		{
			mm++;
		}
		 
        if(mm>0 && a[r-1][c-1]=="o")
        {
        a[r-1][c-1]="*";
		cout<<"Available seat: * ; Reserved Seat: o"<<endl;
        cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
        for(int i=0;i<3; i++)
        {
            j=0;
            cout<<"A"<<i+1<<setw(10)<<a[i][j]<<setw(10)<<a[i][j+1]<<setw(10)<<a[i][j+2]<<setw(10)<<a[i][j+3]<<endl;
        }
        cout<<"Choose row and column for your seat: ";
        cin>>row1;
		cin>>column1;
		while(row1<1 || row1>4)
		{
			cout<<"innvalid row enter again: ";
			cin>>row1;
		}
		while(column1<1 || column1>4)
		{
			cout<<"invalid column enter again: ";
			cin>>column1;
		}
		
        }
        else
        {
            cout<<"All seats are reserved in business class"<<endl;
            cout<<"Next flight will leave tomorrow"<<endl;
            return;
        }
        while(a[row1-1][column1-1]!="*")
        {
            cout<<"Seat is reserved.Enter again: ";
            cin>>row1>>column1;
        }
        a[row1-1][column1-1]="o";
        for(int i=0;i<count;i++)
        {
            if(N==n[i] && Id==id[i])
            {
                row[i]=row1;
                column[i]=column1;
            }
        }
    }
    
    
    
    
    else if(f=="e")
    {
        int mm=0;
        for(int i=0;i<7;i++)
        {
            for(int k=0;k<4;k++)
            {
                if (b[i][k]=="*")
                {
                    mm=mm+1;
                }
            }
        } 
        if(mm>0)
        {
        	b[r-1][c-1]="*";
        cout<<"Available seat: * ; Reserved Seat: o"<<endl;
        cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
        for(int i=0;i<3; i++)
        {
            j=0;
            cout<<"B"<<i+1<<setw(10)<<a[i][j]<<setw(10)<<a[i][j+1]<<setw(10)<<a[i][j+2]<<setw(10)<<a[i][j+3]<<endl;
        }
        cout<<"Choose row and column for your seat: ";
        cin>>row1>>column1;
        while(row1<1 || row1>3)
        {
        	cout<<"invalid row "<<endl;
        	cin>>row1;
		}
		while(column1<1 || column1>4)
		{
			cout<<"invalid column"<<endl;
			cin>>column1;
		}
        }
        else
        {
            cout<<"All seats are reserved in business class"<<endl;
            cout<<"Next flight will leave tomorrow"<<endl;
            return;
        }
        while(a[row1-1][column1-1]!="*")
        {
            cout<<"Seat is reserved.Enter again: ";
            cin>>row1>>column1;
        }
        a[row1-1][column1-1]="o";
        for(int i=0;i<count;i++)
        {
            if(N==n[i] && Id==id[i])
            {
                row[i]=row1;
                column[i]=column1;
                Class[i]="b";
            }
            else
            {
                cout<<"Name or rollno does not exist"<<endl;
                return;
            }
        }
        
    }
}
    
  cout<<"Your seat has been changed successfully"<<endl;
    
    
}


void Cancel_seat(string N,string Id,string a[3][4],string b[7][4],string n[40],string id[40], string f,int &bcount,int &ecount,int row[40],int column[40],string Class[40],int &count) 
{
    cout<<"Enter name: ";
    cin>>N;
    cout<<"Enter rollno: ";
    cin>>Id;
    int aa=0;
    for(int i=0;i<40;i++)
    {
    	if(n[i]==N && id[i]==Id)
    	{
              aa++;    		
		}
	}
	if(aa=0)
	{
		cout<<"You have not reserved a seat"<<endl;
		return;
	}
	else
	{
    cout<<"Enter your class: ";
    cin>>f;
    int r,c;
    cout<<"Enter your current r0w and column: ";
    cin>>r>>c;
    int j;
    
    
    if(f=="b")
    {
    for(int i=0;i<count ;i++)
    {
        if(N==n[i] && Id==id[i])
        {
            if(column[i]==c && row[i]==r)
            {
                a[r-1][c-1]="*";
                int k=count-i;
                for(int l=0;l<k;l++)
                {
                 n[i]=n[i+1];
                 id[i]=id[i+1];
                 row[i]=row[i+1];
                 column[i]=column[i+1];
                 Class[i]=Class[i+1];
                 cout<<"Your seat has been cancelled successfully"<<endl;
                }
                cout<<"Available seat: * ; Reserved Seat: o"<<endl;
                cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
                for(int i=0;i<3; i++)
                {
                  
                  int j=0;
                  cout<<"A"<<i+1<<setw(10)<<a[i][j]<<setw(10)<<a[i][j+1]<<setw(10)<<a[i][j+2]<<setw(10)<<a[i][j+3]<<endl;
                }
                count--;
                bcount--;
                return;
            }
            else
            {
                cout<<"That seat was not registered for you"<<endl;
                return;
            }   
        }
        else
        {
            cout<<"Invalid name or Id or both"<<endl;
            return;
        }
    }
    }
    else if(f=="e")
    {
    for(int i=0;i<count ;i++)
    {
        if(N==n[i] && Id==id[i])
        {
            if(column[i]==c && row[i]==r)
            {
                b[r-1][c-1]="*";
                int k=count-i;
                for(int l=0;l<k;l++)
                {
                 n[i]=n[i+1];
                 id[i]=id[i+1];
                 row[i]=row[i+1];
                 column[i]=column[i+1];
                 Class[i]=Class[i+1];
                 cout<<"Your seat has been cancelled successfully"<<endl;
                }
                cout<<"Available seat: * ; Reserved Seat: o"<<endl;
                cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
                for(int i=0;i<7; i++)
                {
                  
                  int j=0;
                  cout<<"B"<<i+1<<setw(10)<<b[i][j]<<setw(10)<<b[i][j+1]<<setw(10)<<b[i][j+2]<<setw(10)<<b[i][j+3]<<endl;
                }
                count--;
                ecount--;
                return;
            }
            else
            {
                cout<<"That seat was not registered for you"<<endl;
                return;
            }   
        }    
    }
    }
    else
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    
}
}

void view_plan(string a[3][4],string b[7][4])
{
	int j;
	cout<<"Available seat: * ; Reserved Seat: o"<<endl;
    cout<<setw(10)<<"Column1"<<setw(10)<<"Column2"<<setw(10)<<"Column3"<<setw(10)<<"Column4"<<endl;
    for(int i=0;i<3; i++)
    {
        j=0;
        cout<<"A"<<i+1<<setw(10)<<a[i][j]<<setw(10)<<a[i][j+1]<<setw(10)<<a[i][j+2]<<setw(10)<<a[i][j+3]<<endl;
    }
    cout<<endl;
    for(int i=0;i<7; i++)
    {
        j=0;
        cout<<"B"<<i+1<<setw(10)<<b[i][j]<<setw(10)<<b[i][j+1]<<setw(10)<<b[i][j+2]<<setw(10)<<b[i][j+3]<<endl;
    }
}   

void seek_help(string N,string Id,string n[40],string id[40],int row[40],int column[40],int &count,string Class[40])
{
    cout<<"Enter name: ";
    cin>>N;
    cout<<"Enter rollno: ";
    cin>>Id;
    int Row;
    int Column;
    string cls;
    if(count==0)
    {
    	cout<<"Your seat on the entered name and rollno does not exist"<<endl;
        return;
	}
    for(int i=0;i<count;i++)
    {
        if(N==n[i]&& Id==id[i])
        {
            Row=row[i];
            Column=column[i];
            cls=Class[i];
            if(cls=="b")
            {
                cout<<"Row is "<<Row<<",Column is "<<Column<<" in business class"<<endl; 
                return;
			}
			else if(cls=="e")
			{
				cout<<"Row is "<<Row<<",Column is "<<Column<<" in economy class"<<endl; 
                return;
			}
          
        }
        if(i==9)
        {
            cout<<"Your seat on the entered name and rollno does not exist"<<endl;
            return;
        }
    }
    
    
} 



int main()
{
    int x;
    cout<<"**** Welcome to Reservation System ****"<<endl;
    
	int j;
    string a[3][4]={{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"}};
    string b[7][4]={{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"},{"*","*","*","*"}};
    
    string N; //name
    string Id;// id
    string f;//Class
    int count=0; 
    string n[40];//array names
    string id[40];//array rollno
    int bcount=0;//business class count
    int ecount=0;//economy class count
    int row[40];
    int column[40];
    string Class[40];
    
    cout<<"Press 1 to reserve a seat"<<endl;
    cout<<"Press 2 to cancel your seat"<<endl;
    cout<<"Press 3 to change your seat"<<endl;
    cout<<"Press 4 to View Seating Plan"<<endl;
    cout<<"Press 5 to Seek Help"<<endl;
    cout<<"Press -1 to exit"<<endl;

    cin>>x;
    while(x!=-1)
   {
    if(x==1)
    {  
    // Call function 1
       Reserve_seat(N,Id,a,b,n,id, f,bcount,ecount,row,column,Class,count);
    }
    else if(x==3)
    {
       Change_seat(N,Id,a,b,n,id, f,bcount,ecount,row,column,Class,count );
    }
    
    else if(x==2)
    {
        Cancel_seat(N,Id,a,b,n,id, f,bcount,ecount,row,column,Class,count);   
    }
    
    else if(x==4)
    {
        view_plan(a,b);
    }
    
    else if(x==5)
    {
        seek_help(N,Id,n,id,row,column,count,Class);
    }
    else
    {
        cout<<"Invalid input"<<endl;
    }
    cout<<"Press 1 to reserve a seat"<<endl;
    cout<<"Press 2 to cancel your seat"<<endl;
    cout<<"Press 3 to change your seat"<<endl;
    cout<<"Press 4 to View Seating Plan"<<endl;
    cout<<"Press 5 to Seek Help"<<endl;
    cout<<"Press -1 to exit"<<endl;
    cin>>x;
   }
    return 0;
}   
