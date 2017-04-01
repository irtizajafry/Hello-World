#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
//array for logged on computers
//array for rollno
//array for password
//array for PC row
//array for PC column
//array for login on one computer
//array for change password request linked with rollno
//array for seating plan

using namespace std;

void Log_in(string rollno[10],string password[10],string rollno1[10],string a[4][8],int &count,int Row[10],int Column[10])
{
	string roll;
	string p;
	cout<<"Enter rollno: ";
	cin>>roll;
	
	int r;
	int c;
	int alpha=0;
	for(int i=0;i<10;i++)
	{
		if(roll==rollno[i])
		{
			alpha++;
		}
	}
	if(alpha==0)
	{
		cout<<"Entered roll no is not registered"<<endl;
		return;
	}
	else
	{
	cout<<"Enter password: ";
	cin>>p;
	for(int i=0;i<10;i++)
	{
	    if(roll==rollno[i])
	    {
		while(p!=password[i])
        {
        	cout<<"Entered password is wrong.Enter again: ";
        	cin>>p;
		}
	    }
    }
	cout<<"Enter row: ";
	cin>>r;
	cout<<"Enter column: ";
	cin>>c;
	for(int i=0;i<10;i++)
	{
		
		if(roll==rollno[i] && p==password[i])
		{
			for(int k=0;k<count;k++)
			{
				if(roll==rollno1[k])
				{
					cout<<"You are logged in already"<<endl;
					return;
				}
			}
				
					int com;
					com=((r-1)*8)+c;
					cout<<"You have logged in to computer# "<<com<<" successfully"<<endl;
					a[r-1][c-1]="o";
					Row[i]=r-1;
					Column[i]=c-1;
					rollno1[count]=roll;
					count=count+1;
					return;
				
			}	
		
		if(i==9)
		{
			cout<<"You are not registered"<<endl;
			return;	
		}
	}
    } 

	
}

void Log_out(string rollno1[10],int &count,int Row[10],int Column[10],string a[4][8])
{
	string r;
	cout<<"Enter your rollno: ";
	cin>>r;
	
	if(count==0)
	{
		cout<<"You are not logged in"<<endl;
		return;
	}
	for(int i=0;i<count;i++)
	{
		if(r==rollno1[i])
		{
			int aa=Row[i];
		    int ab=Column[i];
		    a[aa][ab]="*";
			for(int k=i;k<count-1;k++)
			{
				rollno1[k]=rollno1[k+1];
				Row[k]=Row[k+1];
				Column[k]=Column[k+1];
			}
			count--;
			int cc=(aa*8)+ab;
			cout<<"You have logged out successfully from computer#"<<cc<<endl;	
			return;;
		}
		if(i==count-1)
		{
			cout<<"You are not logged in on this computer"<<endl;
		}
	}
	
	
}

void Password_change_request(string pcr[10],string rollno1[10],string rollno[10],int &count,int&requestcount)
{
	string r;
    cout<<"enter your rollno: ";
	cin>>r;
	int n;
	
	for(int i=0;i<count;i++)
	{
		if(rollno1[i]==r)
		{
			cout<<"You are logged in.Password change request denied"<<endl;
			return;
		}
	}
	for(int i=0;i<requestcount;i++)
	{
		n=i;
		if(pcr[i]==r)
		{
			cout<<"You already have a pending password change request"<<endl;
			return ;
		}
	if(n==9)
		{
			cout<<"Entered roll no is not registered"<<endl;
		}
	}
	pcr[requestcount]=r;
	cout<<"You have successfully requested change of password"<<endl;
	requestcount=requestcount+1;
	return;
}

void Message_from_helpdesk(string rollno[10],string pcr[10],string password[10],int&counts,int&requestcount)
{
	string r;
	cout<<"Enter rollno: ";
	cin>>r;
	int bb=0;
	int aa=0;
	int cc=0;
	for(int i=0;i<10;i++)
	{
		if(r==rollno[i])
		{
			bb++;
			cc=i;
		}
	}
	if(bb>0)
	{
	for(int i=0;i<requestcount;i++)
	{
			aa=i;
			if(pcr[i]==r)
			{
				cout<<"Dear "<<r<<" Thank you for contacting IST Helpdesk. It is our top priority to resolve your issue in the most timely manner."<<endl;
			    return;
			}
		if(aa==requestcount-1)
			{
				if(counts==1)
		     	{
								
								cout<<"Your password has been reset.Your new password is "<<password[cc]<<endl;
			 	                
				                return;
					    
					}
				
		    
				else 
				{
				cout<<"No new message"<<endl;
			    }  
			}
        }
	}
   else
   {
   	    cout<<"The rollno is not registered"<<endl;
   }
	
}

void View_seating_plan(string a[4][8])
{
	int j;
	cout<<"                                           Lab 3 "<<endl;
	cout<<"           "<<setw(7)<<"col1"<<setw(7)<<"col2"<<setw(7)<<"col3"<<setw(7)<<"col4"<<setw(7)<<"col5"<<setw(7)<<"col6"<<setw(7)<<"col7"<<setw(7)<<"col8"<<endl;   
    for(int i=0;i<4;i++)
	{
		j=0;
		cout<<"row"<<i+1<<setw(10)<<a[i][j]<<setw(10)<<a[i][j+1]<<setw(10)<<a[i][j+2]<<setw(10)<<a[i][j+3]<<setw(10)<<a[i][j+4]<<setw(10)<<a[i][j+5]<<setw(10)<<a[i][j+6]<<setw(10)<<a[i][j+7]<<endl;	
	}  
	cout<<"Available seat:*;Occupied Seat:o"<<endl;
}


void Trace_student(string rollno1[10],int Row[10],int Column[10],int &count)
{
	string r;
	cout<<"Enter rollno of student: ";
	cin>>r;
	
	int ro;
	int co;
	int no;
	if(count==0)
	{
		cout<<"The student with rollno "<<r<<" is not logged in"<<endl;
		return;	
	}
	for(int i=0;i<count;i++)
	{
		if(rollno1[i]==r)
		{ 
		   ro=Row[i];
		   co=Column[i];
		   no=(ro*8)+co;
		   cout<<"The row number is: "<<ro+1<<endl;
		   cout<<"The column number is: "<<co+1<<endl;
		   cout<<"The computer on which the student is logged in is: "<<no+1<<endl;
		   break; 
	    }
		if(i==count-1)
		{
			cout<<"The student with rollno "<<r<<"is not logged in"<<endl;
			return;
		}
	}
} 

void View_change_password_requests(string pcr[10],string rollno[10],int&requestcount)
	
{
	if (requestcount==0)
	{
		cout<<"No students have requested for password change"<<endl;
	}
	else
	{
		cout<<"Following students have requested for password change"<<endl;
	for (int i=0;i<requestcount;i++)
	{
	    cout<<pcr[i]<<endl;
	}
	
    }  
}

int Change_password(string pcr[10],string password[10],string rollno[10],int &requestcount)
{
	int counts;
	string r;
	cout<<"Enter rollno of student: ";
	cin>>r;
	for(int i=0;i<10;i++)
	{
		if (r==rollno[i])
		{
			for(int k=0;k<requestcount;k++)
			{
				if (pcr[k]==r)
				{
					string ps;
			        cout<<"Enter new password: ";
			        cin>>ps;
			        password[i]=ps;
			        for(int n=k;n<requestcount-1;n++)
			        {
			        	pcr[n]=pcr[n+1];
					}
					requestcount--;
			        cout<<"Password has been changed successfully!"<<endl;
			        return 1;
				}
				if(k==requestcount-1)
				{
				    cout<<"The student did not request for password change"<<endl;
			        return 0;
				}
			}
		}
		if(i==9)
		{
		    cout<<"The entered rollno is not designated to any student"<<endl;
		    return 0;
		}
    }
}



int main ()
{
   
    int j;
    
    int count=0;
    int q;
    string rollno[10]={"19100001","19100002","19100003","19100004","19100005","19100006","19100007","19100008","19100009","19100010"};
	string password[10]={"abc123","abc456","abc789","def123","def456","def789","xyz123","xyz456","xyz789","xyz123"};
	string pcr[10]={};
	string rollno1[10]={};
	int Row[10]={};
	int Column[10]={};
	int counts=0;
    int requestcount=0;
	
	string a[4][8]={{"*","*","*","*","*","*","*","*"},{"*","*","*","*","*","*","*","*"},{"*","*","*","*","*","*","*","*"},{"*","*","*","*","*","*","*","*"}};
   
	string x="0";
	while(x!="-1")
	{
		 cout<<"**** Student Mode ****"<<endl;
    cout<<endl;
    cout<<"-Press 1 to log in to a computer"<<endl;
    cout<<"-Press 2 to log off from a computer"<<endl;
    cout<<"-Press 3 to request for password reset"<<endl;
    cout<<"-Press 4 to view message from Helpdesk"<<endl;
    cout<<"-Press 5 to view Lab seating arrangement"<<endl;
    cout<<"-Press 6 to switch mode"<<endl;
    cout<<"-Press -1 to exit"<<endl;

    
    cin>>x;
		if(x=="1")
		{
			Log_in(rollno,password,rollno1,a,count,Row,Column);
		}
		else if(x=="2")
		{
			Log_out(rollno1,count,Row,Column,a);
		}
		else if(x=="3")
		{
			Password_change_request(pcr,rollno1,rollno,count,requestcount);
		}
		else if(x=="4")
		{
			Message_from_helpdesk(rollno,pcr,password,counts,requestcount);
		}
		else if(x=="5")
		{
			View_seating_plan(a);
		}
		else if(x=="6")
		{
			cout<<"      ****Administrator mode***"<<endl;
			cout<<endl;
			while(x!="-1")
			{
				cout<<"-Press 1 to trace a student"<<endl;
				cout<<"-Press 2 to view change password requests"<<endl;
				cout<<"-Press 3 to change password for a student"<<endl;
				cout<<"-Press 4 to view seating arrangement of Lab"<<endl;
				cout<<"-Press 5 to switch mode"<<endl;
				cout<<"-Press -1 to exit"<<endl;
				cin>>x;
				if(x=="1")
				{
					Trace_student(rollno,Row,Column,count);
				}
				else if(x=="2")
				{
					View_change_password_requests(pcr,rollno,requestcount);
				}
				else if(x=="3")
				{
					counts=Change_password(pcr,password,rollno,requestcount);
				}
				else if(x=="4")
				{
					View_seating_plan(a);	
				}
				else if(x=="5")
				{
					break;
				}
				else
				{
					cout<<"Invalid input"<<endl;
				}
			}
			
		}
		else
		{
			cout<<"Invalid input"<<endl;
		}
	
	} 
	return 0;
}
