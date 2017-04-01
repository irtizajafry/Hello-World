#ifndef STACK_H
#define STACK_H
#include "Operation.cpp"
class Stack
{
	private:  Operation *list;
	          int size;
	         	
    
    public:   Stack();
              Stack(Operation *O,int Size);
              ~Stack();
              void Push(Operation &op1);
              void decrease();
              void Pop();
              void Print();
};
#endif
