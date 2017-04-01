#ifndef __OPERATION_CPP
#define __OPERATION_CPP

#include<iostream>
#include<string>
#include"Fraction.cpp"
#include"Operation.h"
using namespace std;

Operation::Operation()
{
	operands=new Fraction[2];
	operandCount=0;
	symbol=" ";
}
Operation::Operation(Fraction* Operands,int Result1, int OperandCount, string Symbol)
 {
 	operands=new Fraction[2];
 	operands[0]=Operands[0];
 	operands[1]=Operands[1];
 	operandCount=OperandCount;
 	symbol=Symbol;
 	result1=Result1;
 }
 /*
Operation::Operation(const Operation& operation)
{
	result=operation.result;
	operandCount=operation.operandCount;
	symbol=operation.symbol;
	operands=new Fraction[operandCount];
	for(int i=0;i<operandCount;i++)
	{
		operands[i]=(operation.operands)[i];
	}
} 
 */
 Operation::~Operation()
 {
 	delete [] operands;
 }
 
Operation::Operation(Fraction* Operands,Fraction Result, int OperandCount, string Symbol)
{
	operands=new Fraction[OperandCount];
	for(int i=0;i<OperandCount;i++)
	{
		operands[i]=Operands[i];
	}
	operandCount=OperandCount;
	symbol=Symbol;
	result=Result;
}

istream& operator >> (istream& ins,const Operation& operation)
{
	ins>>(operation.operands)[0];
	if(operation.operandCount>1)
	{
		ins>>(operation.operands)[1];
	}
	return ins;
}                        

ostream& operator << (ostream& outs,const Operation& operation)
{
    outs<<"Symbol: "<<operation.symbol<<endl;;
    outs<<"Operand1: "<<(operation.operands)[0]<<endl;;
    if(operation.operandCount>1)
    {
    	outs<<"Operand2: "<<(operation.operands)[1]<<endl;;
    }
    if(operation.symbol=="==")
    {
    	outs<<"Result: "<<operation.result1<<endl;
	}
	else
	{
		outs<<"Result: "<<operation.result<<endl;
	}   	
    return outs;
}

Operation& Operation::operator = (const Operation& operation)
{
	result=operation.result;
	operandCount=operation.operandCount;
	symbol=operation.symbol;
	operands=new Fraction[operandCount];
	for(int i=0;i<operandCount;i++)
	{
		operands[i]=(operation.operands)[i];
	}
} 
#endif
