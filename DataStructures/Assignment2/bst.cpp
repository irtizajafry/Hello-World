


#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include "time.h"
using namespace std;
template <class T>
bst<T>::bst()
{
	root = NULL;
}

template <class T>
void bst<T>::insert(string val,T key1)
{	
	if(root == NULL)
	{
		root = new bst_node<T>(val,key1);
		return;
	}
	bst_node<T>* temp = root;
	bst_node<T>* temp1 = new bst_node<T>(val,key1);

	int a = -1;
		while(temp != NULL)
		{	
			if(temp->key < key1)
			{
				if(temp->right == NULL)
				{
					temp->right = temp1;
					break;
				}
				temp = temp->right;		
			}
			else if(temp->key > key1)
			{
				if(temp->left == NULL)
				{
					temp->left = temp1;
					break;
				}
				temp = temp->left;
			}
		}
		temp1->parent = temp;
}
template <class T>
bst_node<T>* bst<T>::search(T key1)
{
	bst_node<T> *temp = root;
	if(temp->key == key1)
	{
		return temp;
	}
	int m = 0;
	while(temp != NULL)
	{
		if(temp->key == key1)
		{
			return temp;
		}
		else if(temp->key < key1)
		{
			if(temp->right == NULL)
			{
				break;
			}
			temp = temp->right;		
		}
		else if(temp->key > key1)
		{
			if(temp->left == NULL)
			{
				break;
			}
			temp = temp->left;
		}
	}
	cout<<"No key found"<<endl;
}

template <class T>
void bst<T>::delete_node(T key1)
{
   	bst_node<T> *temp = search(key1);
   	if(temp->right == NULL && temp->left == NULL)
   	{
   		bst_node<T> *temp1 = temp->parent;
   		if(temp1->right->key == temp->key)
   		{
   			temp1->right = NULL;
   		}
   		else
   		{
   			temp1->left = NULL;
   		}
   		temp->parent = NULL;
   		delete temp;
   		return;
   	}
   	else if((temp->right == NULL && temp->left != NULL) || (temp->right != NULL && temp->left == NULL))
   	{
   		bst_node<T> *tempar = temp->parent;
   		bst_node<T> *temchild;
   		int a = 0;
   		if(tempar->right->key == temp->key)
   		{
   			a = 1;
   		}
   		else if(tempar->left->key == temp->key)
   		{
   			a = 2;
   		}
   		if(temp->right == NULL)
   		{
   			temchild = temp->left;
   			if(a == 1)
   			{
   				tempar->right = temchild;
   			}
   			else if(a == 2)
   			{
   				tempar->left = temchild;
   			}
   			temp->right = NULL;
   			temp->parent = NULL;
   		}
   		else if(temp->left == NULL)
   		{
   			temchild = temp->right;
   			if(a == 1)
   			{
   				tempar->right = temchild;
   			}
   			else if(a == 2)
   			{
   				tempar->left = temchild;
   			}
   			temp->right = NULL;
   			temp->parent = NULL;
   		}
   		temchild->parent = tempar;
   		delete temp;

   	}
   	else if(temp->right != NULL && temp->left != NULL)
   	{
   		bst_node<T>* t = getmax(temp->key);
	    T tkey = t->key;
	    string tvalue = t->value;
	    delete_node(t->key);
	    temp->key = tkey;
   	}
}

template<class T>
bst_node<T>* bst<T>::getmax(T key)
{
	bst_node<T>* temp  = search(key);
	temp = temp->left;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

template <class T>
int bst<T>::height( bst_node<T> *temp)
{
	if ((temp->left) == NULL && (temp->right) == NULL)
	{
		return 0;
	}
	else if((temp->left) == NULL && (temp->right) != NULL)
	{
		int a = 1 + height(temp->right);
		return a;
	}
	else if ((temp->left) != NULL && (temp->right) == NULL)
	{
		int a = 1 + height(temp->left);
		return a;
	}
	else
	{
		if(height(temp->left) > height(temp->right))
		{
			int a = 1 + height(temp->left);
			return a;
		}
		else
		{
			int a = 1 + height(temp->right);
			return a;
		}
	}	
}

template<class T>
void bst<T>::replace(T old_key,T new_key)
{
	bst_node<T>* temp = search(old_key);
	delete_node(old_key);
	insert(temp->value,new_key);
}

template <class T>
bst_node<T>* bst<T>::getroot()
{
	return root;
}
#endif
