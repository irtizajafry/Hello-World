#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "stack.cpp"
#include "stack.h"

// include your stack.h file here
using namespace std;

int main(){
    Stack<int> mystack;
    for (int i = 0; i < 25000; i++)
    {
        mystack.push(i);
    }
    
    int min=mystack.getMin(); //getMin function of the stack that gives the minumum value stored in the stack in O(1)
    assert(min == 0);

    cout<<"Test one passed"<<endl;

    for(int i=0;i<25000;i++){
        mystack.pop();
    } 

    for(int i=1;i<12500;i++){
        mystack.push(i);
    }

    mystack.push(0);

    for(int i= 24999; i>=12500; i--){
        mystack.push(i);
    }

    min=mystack.getMin(); //getMin function of the stack that gives the minumum value stored in the stack in O(1)

    assert(min == 0);

    cout<<"Test two passed"<<endl;

    for(int i=1;i<24999;i++){
        mystack.pop();
    } 
    Stack<int> s;
    int randomnumber=rand()% 25000 +1;
    min=randomnumber;
    s.push(randomnumber);
    for(int i=0; i<=25000; i++){
        randomnumber=rand()% 25000 +1;
        s.push(randomnumber);
        if(min > randomnumber)
            min=randomnumber;
    }

    int stackgetMin=s.getMin(); //getMin function of the stack that gives the minumum value stored in the stack in O(1)
    assert(stackgetMin == min);
    cout<<"Test three passed"<<endl;
    Stack<int> emptyStack;
    emptyStack.getMin();
   
}