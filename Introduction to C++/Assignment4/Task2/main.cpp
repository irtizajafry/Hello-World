//#if SQUARE_H

#include <iostream>
#include <string>
#include <stdio.h>      /* printf, NULL */    /* srand, rand */
#include <time.h>
#include <cstdlib>
#include <iomanip>
//#include"square.h"
//#include"player.h"
//#include"game.h"
using namespace std;



int main()
{
	int x;
	cout<<"Enter dimensions. You can only enter 3,5,7,9: ";
	cin>>x;
	while(x!=3 && x!=5 && x!=7 && x!=9)
	{
		cout<<"Invalid input.Enter again: ";
		cin>>x;
	}
	
	string FIRST1,LAST1,SIGN1;
	cout<<"Player 1"<<endl;
	cout<<"Enter first name: ";
	cin>>FIRST1;
	cout<<"Enter last name: ";
	cin>>LAST1;
	cout<<"Enter symbol: ";
	cin>>SIGN1;
	
	Player p1(FIRST1,LAST1,SIGN1);
	cout<<endl;
    string FIRST2,LAST2,SIGN2;
	cout<<"Player 2"<<endl;
	cout<<"Enter first name: ";
	cin>>FIRST2;
	cout<<"Enter last name: ";
	cin>>LAST2;
	cout<<"Enter symbol: ";
	cin>>SIGN2;
	Player p2(FIRST2,LAST2,SIGN2);
	cout<<endl;
    
    
	Square s1;
	srand (time(NULL)); 
    int b=rand()%2+1;
    if(b==1)
    {
    	cout<<p1.get1stname()<<"'s turn"<<endl;
    	s1.setposition(SIGN1);
    }
    else
    {
    	cout<<p2.get1stname()<<"'s turn"<<endl;
    	s1.setposition(SIGN2);
    }
    
	Game g1(p1,p2,x);
	g1.gametable();	
	int l=0;
	int xx=x*x;
	while(l<=xx)
	{
	    int ROW,COLUMN;
	    cout<<"Enter row: ";
	    cin>>ROW;
	    cout<<"Enter column: ";
	    cin>>COLUMN;
	    while(ROW<1 || ROW>x)
        {
        	cout<<"Invalid row.Enter again: ";
        	cin>>ROW;
        }
        while(COLUMN<1 || COLUMN>x)
        {
        	cout<<"Invalid column.Enter again: ";
        	cin>>COLUMN;
        }
        while(g1.getsquare(ROW-1,COLUMN-1)!="-")
        {
    	    cout<<"Already filled.Enter again"<<endl;
    	    cout<<"Enter row: ";
    	    cin>>ROW;
    	    cout<<"Enter column: ";
	        cin>>COLUMN;
        }
        
        g1.setsquare(s1,ROW-1,COLUMN-1);
        g1.gametable();	
        int count1=0;
        int count2=0;
        for(int i=0;i<x;i++)
        {
        	for(int j=0;j<x-2;j++)
        	{
        		if(g1.getsquare(i,j)==SIGN1 && g1.getsquare(i,j+1)==SIGN1 && g1.getsquare(i,j+2)==SIGN1)
        		{
        			cout<<"Player 1 wins"<<endl;
        			return 0;
        		}
        		if(g1.getsquare(i,j)==SIGN2 && g1.getsquare(i,j+1)==SIGN2 && g1.getsquare(i,j+2)==SIGN2)
        		{
        			cout<<"Player 2 wins"<<endl;
        			return 0;
        		}     		
        	}
        }	

         for(int i=0;i<x-2;i++)
        {
        	for(int j=0;j<x;j++)
        	{
        		if(g1.getsquare(i,j)==SIGN1 && g1.getsquare(i+1,j)==SIGN1 && g1.getsquare(i+2,j)==SIGN1)
        		{
        			cout<<"Player 1 wins"<<endl;
        			return 0;
        		}
        		if(g1.getsquare(i,j)==SIGN2 && g1.getsquare(i+1,j)==SIGN2 && g1.getsquare(i+2,j)==SIGN2)
        		{
        			cout<<"Player 2 wins"<<endl;
        			return 0;
        		}     		
        	}
        }	
         for(int i=0;i<x-2;i++)
        {
        	for(int j=0;j<x-2;j++)
        	{
        		if(g1.getsquare(i,j)==SIGN1 && g1.getsquare(i+1,j+1)==SIGN1 && g1.getsquare(i+2,j+2)==SIGN1)
        		{
        			cout<<"Player 1 wins"<<endl;
        			return 0;
        		}
        		if(g1.getsquare(i,j)==SIGN2 && g1.getsquare(i+1,j+1)==SIGN2 && g1.getsquare(i+2,j+2)==SIGN2)
        		{
        			cout<<"Player 2 wins"<<endl;
        			return 0;
        		}     		
        	}
        }
        for(int i=0;i<x-2;i++)
        {
        	for(int j=0;j<x-2;j++)
        	{
        		if(g1.getsquare(i,x-j-1)==SIGN1 && g1.getsquare(i+1,x-j-2)==SIGN1 && g1.getsquare(i+2,x-j-3)==SIGN1)
        		{
        			cout<<"Player 1 wins"<<endl;
        			return 0;
        		}
        		if(g1.getsquare(i,x-j-1)==SIGN2 && g1.getsquare(i+1,x-j-2)==SIGN2 && g1.getsquare(i+2,x-j-3)==SIGN2)
        		{
        			cout<<"Player 2 wins"<<endl;
        			return 0;
        		} 
        	}
        }
     
        if(s1.getposition()==SIGN1)
        {
        	s1.setposition(SIGN2);
        	cout<<p2.get1stname()<<"'s turn"<<endl;
        }
        else
        {
        	s1.setposition(SIGN1);
        	cout<<p1.get1stname()<<"'s turn"<<endl;
        }

        l++; 
    }
    cout<<"Game is a draw"<<endl;

	return 0;
}	
