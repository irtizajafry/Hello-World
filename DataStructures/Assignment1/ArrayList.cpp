#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "ArrayList.h"

using namespace std;

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& otherArrayList)
{
	array = new T[otherArrayList.capacity];
	capacity = otherArrayList.capacity;
	size = otherArrayList.size;
	for(int i = 0; i < size; i++)
	{
		array[i] = otherArrayList.array[i];
 	}
}

template <class T>
ArrayList<T>::~ArrayList()
{
	delete[] array;
	array = NULL;
}

template <class T>
void ArrayList<T>::insertAtHead(T item)
{
	if(size == capacity)
	{
		resize();
	}
	T* bigger_array = new T[capacity];
	for(int i = 0;i < size; i++)
	{
		bigger_array[i+1] = array[i];
	}
	bigger_array[0] = item;
	delete array;
	array = bigger_array;
	size++;	
}

template <class T>
void ArrayList<T>::insertAtTail(T item)
{
	if(size == capacity)
	{
		resize();
	}
	array[size]=item;
	size++;
	
}

template <class T>
void ArrayList<T>::insertAfter(T toInsert, T afterWhat)
{
    if(size == capacity)
	{
		resize();
	}
	int a = searchFor(afterWhat);
	if(a == size - 1)
	{
		insertAtTail(toInsert);
	}
	else
	{
		for(int i = size; i > a; i--)
	    {
		    array[i] = array[i-1];
	    }
	    array[a] = toInsert;
	    size++;
	}
}

template <class T>
void ArrayList<T>::insertSorted(T item)
{
	if(size == capacity)
	{
		resize();
	}
	int m = 0;
	bool r = true;
	while(r)
	{
		if(item < array[m])
	    {
		    insertAtHead(item);
		    r = false;
	    }
	    else if(item > array[size-1])
	    {
	     	insertAtTail(item);
	     	r = false;
    	}
    	else if(item < array[m+1] && item > array[m])
    	{
    		insertAfter(item, getAt(m));
            r = false;
    	}
    	else
    	{
    		m++;
    	}
	}
}

template <class T>
T ArrayList<T>::getAt(int i)
{
	return array[i];
}
	

template <class T>
int ArrayList<T>::searchFor(T item)
{
	int a = 0;
	for(int i = 0;i < size; i++)
	{
		if(array[i] == item)
		{
			a = i;
			return a;
		}
	}
}

template <class T>
void ArrayList<T>::deleteElement(T item)
{
	if(searchFor(item) == 0)
	{
		deleteHead();
	}
	else if(searchFor(item) == (size-1))
	{
		deleteTail();
	}
	else
	{
		for(int i = 0; i < size; i++)
	    {
		    if(array[i] == item)
		    {
			    for(int j = i; j < size; j++)
			    {
			     	array[j] = array[j+1];
				    size--;
			    }
			    return;
	  	    }
	    }
	}
}

template <class T>
void ArrayList<T>::deleteAt(int i)
{
	if(length() == 0)
	{
		return;
	}
	else
	{
		for(int a = i; a < size; a++)
		{
			array[a] = array[a+1];
		}
	}
	size--;
}

template <class T>
void ArrayList<T>::deleteHead()
{
	T* bigger_array = new T[capacity];
	for(int i = 0; i < size-1; i++)
	{
		bigger_array[i] = array [i+1];
	}
	delete array;
	array = bigger_array;
	size--;
}

template <class T>
void ArrayList<T>::deleteTail()
{
    T* bigger_array = new T[capacity];	
	for(int i = 0; i < size-1; i++)
	{
		bigger_array[i] = array [i];
	}
	delete array;
	array = bigger_array;
	size--;
}

template <class T>
void ArrayList<T>::resize()
{
	T* bigger_array = new T[capacity * 2];
    for (int i = 0; i < size; i++)
    {
        bigger_array[i] = array[i];
    }
    delete[] array;
    array = bigger_array;
    capacity = capacity * 2;
	
}

template <class T>
int ArrayList<T>::length()
{
	return size;
}

template <class T>
void ArrayList<T>::reverse()
{
	T* bigger_array = new T[capacity];
	for(int i = 0; i < size; i++)
	{
		bigger_array[i] = array[size-1-i]; 
	}
	delete array;
	array = bigger_array;
}

#endif




