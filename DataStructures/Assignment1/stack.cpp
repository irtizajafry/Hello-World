#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
	//ListItem<T> * head = list.getHead();
	//head = NULL;
}
    
template <class T>
Stack<T>::Stack(const Stack<T>& otherStack)
{
	LinkedList<T> *node = new LinkedList<T>(otherStack.list);
	list = *node;
}

template <class T>
Stack<T>::~Stack()
{
	//ListItem<T> * head = list.getHead();
	while(list.getHead() != NULL)
	{
		list.deleteHead();
	}
	//list.getHead = NULL;
}

template <class T>
void Stack<T>::push(T item)
{
	list.insertAtHead(item); 
}

template <class T>
T Stack<T>::top()
{
	
	ListItem<T> *head = list.getHead();
	if(head == NULL)
	{
		return 0;
	}
	T item  = head->value;
	return item;
}

template <class T>
T Stack<T>::pop()
{
	T item = top();
	if(item == 0)
	{
		return 0;
	}
	list.deleteHead();
	return item;
}

template <class T>
int Stack<T>::length()
{
	return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
	if(length() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
template <class T>
T Stack<T>::getMin()
{
	ListItem<T> *head = list.getHead();
	T arr[list.length()];
	for(int i = 0; i < list.length() ; i++)
	{
		arr[i] = head->value;
        head = head->next;  
    }
    T min;
    min = arr[0];
    for(int i = 0; i < list.length(); i++)
	{
	    if(min>arr[i])
	    {
	    	min = arr[i];
	    }
    }
    return min;
	    
}

#endif
