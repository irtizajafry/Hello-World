#ifndef __TREE_CPP
#define __LIST_CPP
#include "tree.h"
#include <fstream>

Tree::Tree()
{
	//head = new TreeItem;
}

Tree::Tree(string file)
{
	/*ifstream in;
	in.open("input_test.txt");
	in*/
}
Tree::~Tree()
{
	/*while(head != NULL)
	{
		delete 
	}*/
}

void Tree::insert(string item)
{
	/*if(head == NULL)
	{
		head = new TreeItem;
	}
	else
	{
        TreeItem *point = head;
        if(point->Fchild == NULL)
        {
        	point = point->Fchild;
        	point->value = item;
        	head->Fchild = point;
        	point->Parent = head;
        	return;
        }
        while(point->Fchild != NULL)
        {
        	point = point->Fchild;
        }
		head->Fchild = 
	}*/
}

vector<string> Tree::Locate(string qry)
{
}

string Tree::LComAc(string a, string b)
{
}

TreeItem* Tree::getHead()
{
	return head;
}

int Tree::countFiles()
{
}

#endif
