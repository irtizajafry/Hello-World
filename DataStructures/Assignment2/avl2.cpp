#ifndef __AVL2_CPP
#define __AVL2_CPP
#include "avl2.h"
#include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL(string filename)
{
	//root = new AvLNode<T>;
	int num = 0;
	int a = 0;
	ifstream In;
	In.open("input_avl.txt");
    
    string word1;
	T word2;
	while(!In.eof())
	{
		
		/*getline(cin,text);
		for(int i = 0; i < text.length(); i++)
		{
			if(text[i] == " ")
			{
				word1 = substr(0,i);
				word2 = substr(i,text.length());
				break;
			}
		}*/
		In>>word1;
		In>>word2;
		if(a == 0)
		{
			root = new AvLNode<T>(word1,word2);
            a++;
			continue;
		}
		insert(word1,word2);
		//cout<<num<<endl;
		num++;
	}
	In.close();	
}

template <class T>
AvL<T>::~AvL()
{
	//delete root;
}

template <class T>
AvLNode<T>* AvL<T>::search(T key1)
{
	AvLNode<T> *temp = root;
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
	return NULL;
}

template <class T>
void AvL<T>::replace(T old_key,T new_key)
{
	/*bst_node<T>* temp = search(old_key);
	delete_node(old_key);
	insert(temp->value,new_key);*/
}

template <class T>
void AvL<T>::delete_node(T scr)
{
}

template <class T>
void AvL<T>::insert(string val, T k)
{

	if(root == NULL)
	{
		root = new AvLNode<T>(val,k);
		return;
	}
	AvLNode<T>* temp = root;
	AvLNode<T>* temp1 = new AvLNode<T>(val,k);

	int a = -5;
	while(temp != NULL)
	{	
		if(temp->key < k)
		{
			if(temp->right == NULL)
			{
				temp->right = temp1;
				break;
			}
			temp = temp->right;	
		}
		else if(temp->key > k)
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

    AvLNode<T>* temp3 = temp;
    int h1,h2,subtract;
  
    while(temp3->parent != NULL)
    {
		temp3 = temp3->parent;
		h1 = nodeHeight(temp3->left);
		h2 = nodeHeight(temp3->right);

		if(h1 - h2 >= 2)
		{
			right_rotate(temp3);
			break;
		}
		if(h2 - h1 >= 2)
		{
		    left_rotate(temp3);
			break;
		} 
    } 
}

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *t)
{
	
	if(t == NULL)
	{
		int a = -1;
		return a;
	}
	if ((t->left) == NULL && (t->right) == NULL)
	{
		int a = 0;
		return a;
	}
	else if((t->left) == NULL && (t->right) != NULL)
	{
		int a = 1 + nodeHeight(t->right);
		return a;
	}
	else if ((t->left) != NULL && (t->right) == NULL)
	{
		int a = 1 + nodeHeight(t->left);
		return a;
	}
	else
	{
		if(nodeHeight(t->left) > nodeHeight(t->right))
		{
			int a = 1 + nodeHeight(t->left);
			return a;
		}
		else
		{
			int a = 1 + nodeHeight(t->right);
			return a;
		}
	}
}


template<class T>
AvLNode<T>* AvL<T>::getRoot()
{
	return root;
}

template<class T>
T* AvL<T>::getTopFive()
{
	//T *x = new T[5] 

}

template<class T>
T AvL<T>::getAverage()
{

}

template<class T>
void AvL<T>::displayAll(AvLNode<T> *P)
{

}

template<class T>
void AvL<T>::right_rotate(AvLNode<T> *t)
{
	 AvLNode<T> *tchild = t->left;
	 AvLNode<T> *tpar = t->parent;

	if(tchild->right == NULL && tchild->left == NULL)
    {
    
    	if(tpar != NULL)
		{
			if(tpar->left == t)
	  		{
				tpar->left = tchild;
				tchild->parent = tpar;
			}
			else if(tpar->right == t)
			{
				tpar->right = tchild;
				tchild->parent = tpar;
			}
			
		}
		tchild->right = t;
		t->left = NULL;
		t->parent = tchild;

		return;
	}
	if(nodeHeight(tchild->left) > nodeHeight(tchild->right))
	{
		if(tpar == NULL)
		{
			root = tchild;
		}		
		else if(tpar != NULL)
	  	{
			if(tpar->left == t)
	  	    {
				tpar->left = tchild;
		 	}
		   	else if(tpar->right == t)
		   	{
				tpar->right = tchild;
			}
		}
		tchild->parent = tpar;
		t->parent = tchild;
		if(tchild->right != NULL)
		{
			tchild->right->parent = t;
		}
		t->left = tchild->right;
		tchild->right = t;
	}
	else if((nodeHeight(tchild->left) < nodeHeight(tchild->right)))
	{
		left_rotate(t->left);
		right_rotate(t);
	}
}

template<class T>
void AvL<T>::left_rotate(AvLNode<T> *t)
{
	 AvLNode<T> *tchild = t->right;
	 AvLNode<T> *tpar = t->parent;

	if(tchild->right == NULL && tchild->left == NULL)
	{
		if(tpar != NULL)
		{
			if(tpar->left == t)
	  		{
				tpar->left = tchild;
				tchild->parent = tpar;
			}
			else if(tpar->right == t)
			{
				tpar->right = tchild;
				tchild->parent = tpar;
			}
			
		}
		tchild->left = t;
		t->right = NULL;
		t->parent = tchild;

		return;
	}
	if(nodeHeight(tchild->right) > nodeHeight(tchild->left))
	{
		if(tpar == NULL)
		{
			root = tchild;
		}		
		
		else if(tpar != NULL)
	  	{
			if(tpar->left == t)
	  	    {
				tpar->left = tchild;
		 	}
		   	else if(tpar->right == t)
		   	{
				tpar->right = tchild;
			}
		}
		tchild->parent = tpar;
		t->parent = tchild;
		t->right = tchild->left;
		tchild->left = t;	
	}
	else if(nodeHeight(tchild->right) < nodeHeight(tchild->left))
	{
		right_rotate(t->right);
		left_rotate(t);
	}	
}

#endif
