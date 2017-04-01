#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"
//#include <iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{

	head=NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
	ListItem<T>* node = otherLinkedList.head;

    if(node == NULL)
    {
	    head = NULL;
	    return;
    }
    head = new ListItem<T>(node->value);
    ListItem<T>* node1 = head;
    while(node->next != NULL)
    {
	    node = node->next;
	    node1->next = new ListItem<T>(node->value);
	    node1 = node1->next;
    }
	
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while(head != NULL){
		deleteHead();
	}
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
	if(head != NULL)
    {
    	ListItem<T> *newhead = new ListItem<T>(item);
    	newhead->next = head;
    	head->prev = newhead;
    	head = newhead;
    }
    else
    {
    	head = new ListItem<T>(item);
    } 
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
	if(head != NULL)
	{
		ListItem<T> *node = head;
		while(node->next != NULL)
		{
			node = node->next;
		}
		ListItem<T> *newtail = new ListItem<T>(item);
		newtail->prev = node;
		node->next = newtail;
	}
    else
    {
    	head = new ListItem<T>(item);
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
	
	if(head == NULL)
	{
		return;
	}
	else
	{
		ListItem<T> *node = head;
		while(node->value != afterWhat)
		{
			node = node->next;
			if(node == NULL)
			{
				return;
			}
		}
		ListItem<T> *t = new ListItem<T>(toInsert);
		t->next = node->next;
		if(t->next != NULL)
		{
			(t->next)->prev = t;
		}
		t->prev = node;
		node->next = t;
	}	
}

template <class T>
void LinkedList<T>::insertSorted(T item)
{
	bool boolean = true;
	if(head == NULL)
	{
		insertAtHead(item);
	}
	else if(searchFor(item) == NULL)
	{
		ListItem<T> *a;
		a = head;
        while(boolean != false)
		{
			if(a->next == NULL && item > a->value)
		    {
			    insertAtTail(item);
			    boolean = false;
		    }
		    else if(a == head && a->value > item)
		    {
		    	insertAtHead(item);
		    	boolean = false;
		    }
		    else if(a->value < item && (a->next)->value > item)
		    {
			    ListItem<T> *node = new ListItem<T>(item);
		        node->next = a->next;
		        node->prev = a;
		        a->next = node;
		        if(node->next != NULL)
				{
					(a->next)->prev = node;
				}
				boolean = false;
		    }
		    else
		    {
		    	a = a->next;
		    }
		}
	}
	else
	{
		insertAfter(item,item);
	}
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
	return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
	if(head != NULL){
		ListItem<T>* temp = head;
		ListItem<T>* tail;
		if(length() == 1){
			return getHead();
		}else{
			while((temp->next)->next != NULL){
				temp = temp -> next;
			}
			tail = temp->next;
			return tail;
		}
	}
	else{
		return NULL;
	}

}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
	if(head!=NULL)
	{
		ListItem<T> *node = head;
		while(node->value != item)
		{
			node = node->next;
			if(node == NULL)
			{
				//cout<<item + "is not in the list"<<endl; 
				return NULL;
			}
		}
		return node;
	}
	else
	{
		return NULL;
	}	
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		ListItem<T> *node = head;
		while(node->value != item)
		{
			node = node->next;
			if(node == NULL)
			{
				return;
			}
		}
		if(node->next == NULL)
		{
			deleteTail();
		}
		else if(head == node)
		{
			deleteHead();
		}
		else
		{
			(node->prev)->next = node->next;
			(node->next)->prev = node->prev;
			delete node;
		}
	}
}

template <class T>
void LinkedList<T>::deleteHead()
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		ListItem<T> *node;
	    node = head->next;
	    delete head;
	    head = node;
	}	
}

template <class T>
void LinkedList<T>::deleteTail()
{
	if(head == NULL)
	{
		delete head;
	}
	else
	{
		ListItem<T> *node = head;
		while(node->next != NULL)
		{
			node = node->next;
		}
        delete node->next; 
		node->next = NULL;

	}
}

template <class T>
int LinkedList<T>::length()
{
	ListItem<T> *node = head;
	int num = 0;
	while(node != NULL)
	{
		num++;
		node = node->next;
				
	}
	return num;	
}

template <class T>
void LinkedList<T>::reverse()
{
    if(head == NULL)
    {
        return;
    }
	else
    {
        ListItem<T> *a = head;
		int b = 0;
	    while(a->next != NULL)
	    {
		    a = a->next;
	    }
	    while(b < length())
	   	{
		    b++;
		    insertAfter(head->value,a->value);
		    deleteHead();
	    }	
    }
}

template <class T>
void LinkedList<T>::parityArrangement()
{
	LinkedList<T> node(*this);
	ListItem<T> *a = node.head;
	int num = 0;
	 //a = 0;
	while(num!=length()){
		num++;
		//a = num % 2;
		if(num % 2 == 0)
		{
			insertAtTail(a->value);
			deleteElement(a->value);
		}
		a=a->next;
	}	
}


template <class T>
bool LinkedList<T>::isPalindrome()
{
		T arr[length()];
		ListItem<T> * a = head;
		T min;
		for(int i = 0; i < length() ; i++)
		{
			arr[i] = a->value;
            a = a->next;  
		}
		for(int i = 0; i < (length()/2); i++)
		{
			if(arr[i] != arr[length()-1-i])
			{
				return false;
			}  
		}
		if(length() == 0)
		{
			return  false;
		}
		else
		{
			return true;
		}
}
#endif