#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
#include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL()
{
	root = NULL;
}

template <class T>
AvL<T>::~AvL()
{

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

template<class T>
AvLNode<T>* AvL<T>::getmax(T key)
{
	AvLNode<T>* temp  = search(key);
	temp = temp->left;
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

template <class T>
void AvL<T>::replace(T ok, T nk)
{
}

template <class T>
void AvL<T>::delete_node(T key1)
{
	AvLNode<T> *temp = search(key1);
   	if(temp->right == NULL && temp->left == NULL)
   	{
   		AvLNode<T> *temp1 = temp->parent;
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
   		AvLNode<T> *tempar = temp->parent;
   		AvLNode<T> *temchild;
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
	    AvLNode<T>* t = getmax(temp->key);
	    T tkey = t->key;
	    string tvalue = t->value;
	    delete_node(t->key);
	    temp->key = tkey;
   	}
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
		    //if(temp->key != 32)
		 	//{
				left_rotate(temp3);
				break;
			//}	
		} 
    } 

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
		left_rotate(tchild);
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
		right_rotate(tchild);
		left_rotate(t);
	}	
}

/*void Avl<T>
template<class T>
void AvL<T>::left_right_rotate(AvLNode<T> *t)
{


}
template<class T>
void AvL<T>::right_left_rotate(AvLNode<T> *t)
{

}*/


#endif
