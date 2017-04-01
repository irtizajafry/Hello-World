#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<string>
#include<iomanip>
#include"square.h"
#include"player.h"
using namespace std;
class Game
{
	private: Square **array;
	         Player p1;
	         Player p2;
	         int size;
	         
	public:  Game();
	         Game(Player p01,Player p02,int Size);
		//	 friend Square& operator [][](const int rowindex,const int columnindex); 
			 void setdimension(int a);
			 void setplayers(Player p01,Player p02);  
			 void gametable(); 
			 string getsquare(int row,int column);
			 void setsquare(Square square,int row,int column);  
};
#endif
