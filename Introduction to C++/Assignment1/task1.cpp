
// Example program
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
 // int handi [3]={40,80,120};
 // int rice [3]={30,50,80};
 // int salad [3]={5,10,20};
 // int fruit [3]={20,40,80};
 // int sweet [3]={10,30,70};
   
  
  int a=0;
  cout<<"Enter no of items: ";
  cin>>a;
  
  string food[3]={"none","none","none"};
  string portion[3]={"null","null","null"};
  int Price[3]={0,0,0};
  
  int count=0;
  int price=0;
  int d=0;
  
  for (int i=0; i<a; i++)
  {
   cout<<"1 for handi,2 for rice,3 for salad,4 for fruit, 5 for sweet: ";
   cout<<"Enter the food item number: ";
   int b;
   cin>>b;   
    if (b==1)
    {
      food[i]="handi";
      int c;
      cout<<"Enter 1 for quarter, 2 for half, 3 for handi: "; 
      cin>>c;
      if (c==1)
      {
          price = 40;
          portion[i] = "quarter";
          Price[i] = 40;
      }
      else if (c==2)
      {
          price = 80;
          portion[i] = "half";
          Price[i] = 80;
      }
      else if (c==3)
      {
          price = 120;
          portion[i] = "full";
          Price[i] = 120; 
      }
      else
      {
      	  cout<<"Invalid Input"<<endl;
		  return 0;
	  }
    }
    else if (b==2)
    {
      food[i]="rice";
      int c;
      cout<<"Enter 1 for quarter, 2 for half, 3 for handi: "; 
      cin>>c;
      if (c==1)
      {
           price = 30;
           portion[i] = "quarter";
           Price[i] = 30;
           
      }
      else if (c==2)
      {
          price = 50;
          portion[i] = "half";
          Price[i] = 50;
      }
      else if (c==3)
      {
          price = 80;
          portion[i] = "full";
          Price[i] = 80;
      }
      else
      {
      	  cout<<"Invalid Input"<<endl;
	      return 0;
	  }
    }
  
    else if (b==3)
    {
      food[i]="salad";
      int c;
      cout<<"Enter 1 for quarter, 2 for half, 3 for handi: "; 
      cin>>c;
      if (c==1)
      {
           price = 10;
           portion[i] = "quarter";
           Price[i] = 10;
      }
      else if (c==2)
      {
          price = 20;
          portion[i] = "half";
          Price[i] = 20;
      }
      else if (c==3)
      {
          price = 30;
          portion[i] = "full";
          Price[i] = 30;
      }
      else
      {
      	  cout<<"Invalid Input"<<endl;
		  return 0;
	  }
    }
    
    else if (b==4)
    {
      food[i]="fruit";
      int c;
      cout<<"Enter 1 for quarter, 2 for half, 3 for handi: "; 
      cin>>c;
      if (c==1)
      {
           price = 20;
           portion[i] = "quarter";
           Price[i] = 20;
      }
      else if (c==2)
      {
          price = 40;
          portion[i] = "half";
          Price[i] = 40;
      }
      else if (c==3)
      {
          price = 80;
          portion[i] = "full";
          Price[i] = 80;
      }
      else
      {
      	  cout<<"Invalid Input"<<endl;
		  return 0;
	  }
    }
    
     else if (b==5)
    {
      food[i]="sweet";
      int c;
      cout<<"Enter 1 for quarter, 2 for half, 3 for handi: "; 
      cin>>c;
      if (c==1)
      {
           price = 20;
           Price[i] = 20;
           portion[i] = "quarter";
      }
      else if (c==2)
      {
          price = 50;
          Price[i] = 50;
          portion[i] = "half";
      }
      else if (c==3)
      {
          price = 80;
          portion[i] = "full";
          Price[i] = 80;
      }
      else
      {
      	  cout<<"Invalid Input"<<endl; 
		  return 0;
	  }
    }
    else if(b==-1)
    {
    	return 0;
	}
		
	else
    {
        cout<<"Invalid Input"<<endl;
        return 0;
    }
    d=d+price;
    count=count+1;
  }
  
  
{
    /** SOURCE: http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c **/
    time_t t = time(0);   // get time now
    class tm * now = localtime( & t );
    
    switch((now->tm_mon + 1))
    {
        case 1 : cout<<"Date: " << now->tm_mday << ", " << "January" << " " << (now->tm_year + 1900) << endl;break;
        case 2 : cout<<"Date: " << now->tm_mday << ", " << "February" <<" " << (now->tm_year + 1900) << endl;break;
        case 3 : cout<<"Date: " << now->tm_mday << ", " << "March" << " " << (now->tm_year + 1900) << endl;break;
        case 4 : cout<<"Date: " << now->tm_mday << ", " << "April" << " " << (now->tm_year + 1900) << endl;break;
        case 5 : cout<<"Date: " << now->tm_mday << ", " << "May" << " " << (now->tm_year + 1900) << endl;break;
        case 6 : cout<<"Date: " << now->tm_mday << ", " << "June" << " " << (now->tm_year + 1900) << endl;break;
        case 7 : cout<<"Date: " << now->tm_mday << ", " << "July" << " " << (now->tm_year + 1900) << endl;break;
        case 8 : cout<<"Date: " << now->tm_mday << ", " << "August" << " " << (now->tm_year + 1900) << endl;break;
        case 9 : cout<<"Date: " << now->tm_mday << ", " << "September" << " " << (now->tm_year + 1900) << endl;break;
        case 10 : cout<<"Date: " << now->tm_mday << ", " << "October" << " " << (now->tm_year + 1900) << endl;break;
        case 11 : cout<<"Date: " << now->tm_mday << ", " << "November" << " " << (now->tm_year + 1900) << endl;break;
        case 12 : cout<<"Date: " << now->tm_mday << ", " << "December" << " " << (now->tm_year + 1900) << endl;break;
    }   
    now->tm_hour= now->tm_hour;
    if (now->tm_hour>12)
    {
        int a = now->tm_hour-12;
        
        cout << "Time: " << a << ":" << now->tm_min <<" pm"<< endl;
    }
    else
    {
    cout << "Time: " << now->tm_hour << ":" << now->tm_min <<" am"<< endl;
    }
}
      
                                                                 
  cout<<"Sr.No"<<"   Item "<<"   Portion "<<"   Price "<<endl;
  for(int i=0;i<count;i++)
  {
  cout<<i+1<<"       "<<food[i]<<"      "<<portion[i]<<"      "<<Price[i]<<endl;
  }
   
  cout<<"    Item Count: "<<count<<endl;
  cout<<"    Total: "<<d<<endl;
  
  return 0;
}

