#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"


int main() {
	
	
	ifstream in0;
	ifstream in1;
	ifstream in2;
	ifstream in3;
	ifstream in4;
	ifstream in5; 
	in0.open("userList.txt");
	User* Userlist[20];
	
	Course Course_Array[5];
	
	
	for(int i=0;i<20;i++)
	{
		if(i<15)
		{
			Userlist[i]=new Student;
			Userlist[i]->PopulateData(in0);
		}
		if(i>=15)
		{
			Userlist[i]=new Instructor;
			Userlist[i]->PopulateData(in0);
		}
	}


	
	in1.open("Course1.txt");
	in2.open("Course2.txt");
	in3.open("Course3.txt");
	in4.open("Course4.txt");
	in5.open("Course5.txt");
	
	Course c1,c2,c3,c4,c5;
	c1.SetNoofstudents(6);
	c1.InputCourse(in1);
	c2.SetNoofstudents(10);
	c2.InputCourse(in2);
	c3.SetNoofstudents(4);
	c3.InputCourse(in3);
	c4.SetNoofstudents(10);
	c4.InputCourse(in4);
	c5.SetNoofstudents(15);
	c5.InputCourse(in5);
	
	Course_Array[0]=c1;
	Course_Array[1]=c2;
	Course_Array[2]=c3;
	Course_Array[3]=c4;
	Course_Array[4]=c5;


    int marks1[c1.GetNoofstudents()];
    int marks2[c2.GetNoofstudents()];
    int marks3[c3.GetNoofstudents()];
    int marks4[c4.GetNoofstudents()];
    int marks5[c5.GetNoofstudents()];
    for(int i=0;i<c1.GetNoofstudents();i++)
    {
    	marks1[i]=0;
    }
    for(int i=0;i<c2.GetNoofstudents();i++)
    {
    	marks2[i]=0;
    }
    for(int i=0;i<c3.GetNoofstudents();i++)
    {
    	marks3[i]=0;
    }
    for(int i=0;i<c4.GetNoofstudents();i++)
    {
    	marks4[i]=0;
    }
    for(int i=0;i<c5.GetNoofstudents();i++)
    {
    	marks5[i]=0;
    }

	
	cout<<"Press 1 if you are a student"<<endl;
	cout<<"Press 2 if you are an instructor"<<endl;
	cout<<"Press -1 to exit"<<endl;
    string x;
    cin>>x;
	while(x!="-1")
	{
		if(x=="1")
		{
			int log=0;

			string use;
			cout<<"Enter username: ";
			cin>>use;
			string p;
			cout<<"Enter password: ";
			cin>>p;
			string count[5]={"-","-","-","-","-"};


            int i=0;
			while(i<15)
			{
				string a,b;
				a=Userlist[i]->GetUsername();
				b=Userlist[i]->GetPassword();				
				if(a==use && b==p)
				{
					cout<<"You have signed in successfully"<<endl;
					cout<<"List of Courses: "<<endl;
					for(int q=0;q<5;q++)
					{
						for(int m=0;m<(Course_Array[q]).GetNoofstudents();m++)
						{
							if((Course_Array[q].GetStudent()[m]).GetUsername()==a)
						    {
							    cout<<(Course_Array[q]).GetCoursecode()<<" ";
							    count[q]=(Course_Array[q]).GetCoursecode();
							}
						}	
					}
					cout<<endl;
					string cor;
					while(cor!="-1")
					{

					cout<<"Enter coursecode: ";
					cin>>cor;
					int counts1=0;
					int counts2=0;
					int counts3=0;
					int counts4=0;
					int counts5=0;
					int acount;
					

					string d;
					while(d!="-1")
					{
						for(int ac=0;ac<5;ac++)
						{
							if(count[ac]==cor)
							{
								acount=ac;
								break;
							}
							if(ac==4)
							{
								cout<<"That is not your code or that code does does not exist.Enter again: "<<endl;
								cin>>cor;
								ac=0;
							}
						}
						cout<<"Press 1 to view marks"<<endl;
					    cout<<"Press 2 to view assignments"<<endl;
					    cout<<"Press 3 to view resources"<<endl;
					    cout<<"Press 4 to view roster"<<endl;
					    cout<<"Press -1 to change course"<<endl;
					    cout<<"Press 5 to log out"<<endl;
						cin>>d;	
						if(d=="1")
						{
							int q=0;
							if(cor=="CS_200")
							{
								q=0;
							}
							else if(cor=="EE_200")
							{
								q=1;
							}
							else if(cor=="BIO_200")
							{
								q=2;
							}
							else if(cor=="CS_210")
							{
								q=3;
							}
							else if(cor=="CS_225")
							{
								q=4;
							}
							cout<<q<<endl;
						        for(int m=0;m<(Course_Array[q]).GetNoofstudents();m++)
						        {
						        	if((Course_Array[q].GetStudent()[m]).GetUsername()==a)
						        	{
						        		 cout<<"Marks: ";
						        		 if(q==0)
						        		 {
						        		 	cout<<marks1[m];
						        		 }
						        		 else if(q==1)
						        		 {
						        		 	cout<<marks2[m];
						        		 }
						        		 else if(q==2)
						        		 {
						        		 	cout<<marks3[m];
						        		 }
						        		 else if(q==3)
						        		 {
						        		 	cout<<marks4[m];
						        		 }
						        		 else if(q==4)
						        		 {
						        		 	cout<<marks5[m];
						        		 }
						        		 cout<<endl;
						        		 break;
								    }
						        }
						}	
					    else if(d=="2")
					    {
					    	cout<<"Assignments: "<<endl;
					    	Course_Array[acount].ViewAssignment();
					    	Course_Array[acount].ViewDuedate();
					    }
					    else if(d=="3")
					    {
					    	cout<<"Resources: "<<endl;
					    	Course_Array[acount].ViewResource();

					    }
						else if(d=="4")
						{ 
							(Course_Array[acount]).ViewRoster();

							for(int p=0;p<5;p++)
					        {
							    if((Course_Array[p].GetCoursecode())==cor)
						        {
							        (Course_Array[p]).ViewRoster();
							    }
							}
						}
						else if(d=="-1")
						{
							break;
						}
						else if(d=="5")
						{
                            log++;
                            break;
						}
						else
						{
							cout<<"Invalid input"<<endl;
						}
					}
					if(log>0)
					{
						break;
					}
				}
				if(log>0)
				{
					break;
				}
				}
				if(i==14)
				{
					cout<<"invalid username or password.Enter again: ";
					cin>>use;
					cin>>p;
					i=-1;

				}
				i++;
			}
		}
		
		else if(x=="2")
		{
			int log=0;
			cout<<"Enter username: ";
			string use;
			string p;
			cin>>use;
			cout<<"Enter password: ";
			cin>>p;
			string count[5]={"-","-","-","-","-"};

			for(int i=15;i<20;i++)
			{
				string a,b;
				a=Userlist[i]->GetUsername();
				b=Userlist[i]->GetPassword();
				
			    if(a==use && b==p)
		        {
			        cout<<"You have signed in successfully"<<endl;
			        for(int j=0;j<5;j++)
				    {
					    if((Course_Array[j].GetInstructor()).GetPassword()==b)
					    {
						    cout<<"Course: "<<Course_Array[j].GetCoursecode()<<" ";
						    count[j]=Course_Array[j].GetCoursecode(); 	
                        }
                    }
                }
                cout<<endl;
                string cor;
                while(cor!="-1")
                {

                cout<<"Enter coursecode: ";
                
                int acount=0;
                cin>>cor;
                int j=0;
                while(j<5)
                {
                    if(count[j]==cor)
                    {
                    	acount=j;
                    	break;
                    }
                    if(j==4)
                    {
                    	cout<<"That is not your coursecode.Enter again: "<<endl;
                    	j=-1;
                        cin>>cor;
                    }
                    j++;
                }
				 	string e;
			        while(e!="-1")
		     	    {
			       	    if(e=="1")
			            {
						    for(int ss=0;ss<(Course_Array[acount]).GetNoofstudents();ss++)
			                {
	    		                cout<<((Course_Array[acount]).GetStudent()[ss]).GetFirst()<<" "<<((Course_Array[acount]).GetStudent()[ss]).GetLast()<<" ";
	    		                string alpha;
	    		                alpha=((Course_Array[acount]).GetCoursecode());
	    		                if(alpha=="CS_200")
	    		                {
	    		                	cout<<marks1[ss];
	    		                }
	    		                else if(alpha=="EE_200")
	    		                {
	    		                	cout<<marks2[ss];
	    		                }
	    		                else if(alpha=="BIO_200")
	    		                {
	    		                	cout<<marks3[ss];
	    		                }
	    		                else if(alpha=="CS_210")
	    		                {
	    		                	cout<<marks4[ss];
	    		                }
	    		                else if(alpha=="CS_225")
	    		                {
	    		                	cout<<marks5[ss];
	    		                }
	    		                cout<<endl;
	    		            }	    
					    }
					    else if(e=="2")
					    {
					    	cout<<"Enter username of the student: ";
					    	string us;
					    	cin>>us;
					        if(cor=="CS_200")
					    	{
					    		for(int ss=0;ss<(Course_Array[0]).GetNoofstudents();ss++)
					    		{
					    			if(((Course_Array[0]).GetStudent()[ss]).GetUsername()==us)
					    			{
					    				int stdmarks;
					    				cout<<"Enter updated marks: ";
					    				cin>>stdmarks;
					    				marks1[ss]=stdmarks;
					    				cout<<"name"<<endl;
					    				break;
					    			}
					    			if(ss==6)
					    			{
					    				cout<<"Entered username is not enrolled in your course"<<endl;
					    			}
					    			
					    		}
					    	}
					   		else if(cor=="EE_200")
					   		{
					   			for(int ss=0;ss<(Course_Array[1]).GetNoofstudents();ss++)
					    		{
					    			if(((Course_Array[1]).GetStudent()[ss]).GetUsername()==us)
					    			{
					    				int stdmarks;
					    				cout<<"Enter updated marks: ";
					    				cin>>stdmarks;
					    				marks2[ss]=stdmarks;
					    				break;
					    			}
					    			if(ss=(Course_Array[1]).GetNoofstudents()-1)
					    			{
					    				cout<<"Entered username is not enrolled in your course"<<endl;
					    			}
					    		}
					   		}
					   		else if(cor=="BIO_200")
				    		{
				    			for(int ss=0;ss<(Course_Array[2]).GetNoofstudents();ss++)
					    		{
					    			if(((Course_Array[2]).GetStudent()[ss]).GetUsername()==us)
					    			{
					    				int stdmarks;
					    				cout<<"Enter updated marks: ";
					    				cin>>stdmarks;
					    				marks3[ss]=stdmarks;
					    				break;

					    			}
					    			if(ss=(Course_Array[2]).GetNoofstudents()-1)
					    			{
					    				cout<<"Entered username is not enrolled in your course"<<endl;
					    			}
					    		}
				    		}
				    		else if(cor=="CS_210")
				    		{
				    			for(int ss=0;ss<(Course_Array[3]).GetNoofstudents();ss++)
					    		{
					    			if(((Course_Array[3]).GetStudent()[ss]).GetUsername()==us)
					    			{
					    				int stdmarks;
					    				cout<<"Enter updated marks: ";
					    				cin>>stdmarks;
					    				marks4[ss]=stdmarks;
					    				break;

					    			}
					    			if(ss=(Course_Array[3]).GetNoofstudents()-1)
					    			{
					    				cout<<"Entered username is not enrolled in your course"<<endl;
					    			}
					    		}
				    		}
					  		else if(cor=="CS_225")
				    		{
				    			for(int ss=0;ss<(Course_Array[4]).GetNoofstudents();ss++)
					    		{
					    			if(((Course_Array[4]).GetStudent()[ss]).GetUsername()==us)
					    			{
					    				int stdmarks;
					    				cout<<"Enter updated marks: ";
					    				cin>>stdmarks;
					    				marks5[ss]=stdmarks;
					    				break;

					    			}
					    			if(ss=(Course_Array[4]).GetNoofstudents()-1)
					    			{
					    				cout<<"Entered username is not enrolled in your course"<<endl;
					    			}
					    		}
				    		}
					        
                        }					    
					    else if(e=="3")
					    {
					    	cout<<"Assignments: "<<endl;
					    	Course_Array[acount].ViewAssignment();
					    	Course_Array[acount].ViewDuedate();
					    }
					    else if(e=="4")
					    {
                            string assign,due;
                            cout<<"Enter name: ";
                            cin>>assign;
                            cout<<"Enter due-date: ";
                            cin>>due;
					    	(Course_Array[acount]).SetAssignment(assign,due);
					    }
					    else if(e=="5")
					    {
					    	cout<<"Resources: "<<endl;
					    	Course_Array[acount].ViewResource();
					    }
					    else if(e=="6")
					    {
					    	string assign;
					    	cout<<"Enter name: ";
					    	cin>>assign;
					    	(Course_Array[acount]).SetResource(assign);
					    }
					    else if(e=="7")
					    {
			    		       (Course_Array[acount]).ViewRoster();
					    }
					    else if(e=="-1")
					    {
					       	   break;
					    }
					    else if(e=="8")
					    {
					    	log++;
					    	break;
					    }
					    cout<<"Press 1 to view marks"<<endl;
		                cout<<"Press 2 to add marks"<<endl;
	       	            cout<<"Press 3 to view assignments"<<endl;
				        cout<<"Press 4 to add assignments"<<endl;
					    cout<<"Press 5 to view resources"<<endl;
					    cout<<"Press 6 to add resources"<<endl;
					    cout<<"Press 7 to view roster"<<endl;
					    cout<<"Press 8 to log out"<<endl;
					    cout<<"Press -1 to change coursecode"<<endl;
					    cin>>e;

					 }
					 if(log>0)
					 {
					 	break;
					 }

				 }	       
        if(i==19)
         {
                cout<<"Your username or password are invalid"<<endl;
                i==0;
         }
         if(log>0)
         {
         	break;
         }
     }
 }
		
    cout<<"Press 1 if you are a student"<<endl;
	cout<<"Press 2 if you are an instructor"<<endl;
	cout<<"Press -1 to exit"<<endl;
    cin>>x;
}	
	 
	
	in5.close();
	in4.close();
	in3.close();
	in2.close();
	in1.close();
	in0.close();
	return 0;

}
