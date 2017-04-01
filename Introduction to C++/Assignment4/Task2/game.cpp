#include<iostream>
#include<string>
#include<iomanip>
#include"square.h"
#include"player.h"
#include"game.h"
using namespace std;
Game::Game()
{
	size=1;
	Square s1("-");
	array=new Square*[size];
	for(int i=0;i<size;i++)
	{
		array[i]=new Square[size];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			array[i][j]=s1;
		}
	}
}
Game::Game(Player p01,Player p02,int Size)
{
	Square s1("-");
	p1=p01;
	p2=p02;
	size=Size;
	array=new Square*[Size];
	for(int i=0;i<Size;i++)
	{
		array[i]=new Square[Size];
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			array[i][j]=s1;
		}
	}
}

void Game::gametable()
{
	cout<<"  ";
	for(int i=0;i<size;i++)
	{
		cout<<setw(5)<<"C"<<i+1;
	}
	cout<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"R"<<i+1;
		for(int j=0;j<size;j++)
		{
			cout<<setw(6)<<getsquare(i,j);
		}
		cout<<endl;
	}
}


void Game::setsquare(Square square,int row,int column)
{
	array[row][column]=square;
}
void Game::setdimension(int a)
{
	size=a;
}
void Game::setplayers(Player p01,Player p02)
{
	p1=p01;
	p2=p02;
}
string Game::getsquare(int row,int column)
{
	Square sq=array[row][column];
	return sq.getposition();
}
