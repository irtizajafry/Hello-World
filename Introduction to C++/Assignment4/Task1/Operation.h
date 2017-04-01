#ifndef OPERATION_H
#define OPERATION_H

class Operation
{
    private:  Fraction *operands;
              Fraction result;
              int result1;
              int operandCount;
              string symbol;

    public:   Operation();
              ~Operation();
          //    Operation(const Operation& operation);
			  /*void setsymbol(string Symbol);
              string getsymbol();
			  void setOpcount(int count);
			  int getOpcount();
			  void setOperand()  */  
			  Operation& operator = (const Operation& operation);
              Operation(Fraction* Operands,int Result1, int OperandCount, string Symbol);  
              Operation(Fraction* Operands,Fraction Result, int OperandCount, string Symbol);
              friend ostream& operator << (ostream& out,const Operation& operation);
			  friend istream& operator >> (istream& in,const Operation& operation);
};
#endif
