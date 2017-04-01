
#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{
    list;
}
    
template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue)
{
	LinkedList<T> n = otherQueue.list;
    ListItem<T> *n1;
    n1 = n.getHead();
    while(n1 != NULL)
    {
    	T item = n1->value;
    	list.insertAtTail(item);
    	n1 = n1->next;
    }
}

template <class T>
Queue<T>::~Queue()
{
    while(list.getHead() != NULL)
	{
		list.deleteHead();
	}
}

template <class T>
void Queue<T>::enqueue(T item)
{
	list.insertAtHead(item);
}

template <class T>
T Queue<T>::front()
{
	if(list.length() == 0)
	{
		return NULL;
	}
    ListItem<T> *tail  = list.getTail();
    return tail->value;
}

template <class T>
T Queue<T>::dequeue()
{	
    if(list.length() == 0)
	{
		return NULL;
	}
	T item = front();
	list.deleteTail();
	return item;
}

template <class T>
int Queue<T>::length()
{
	return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
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


#endif
