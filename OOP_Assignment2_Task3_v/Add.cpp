#ifndef _AddOperation
#define _AddOperation
#include"Operation.cpp"
class AddOperation : public Operator
{
public:
	AddOperation(MemortUnit* ram, MemortUnit* registor, MemortUnit* controller) : Operator(ram,registor,controller) {}
	virtual void apply()
	{
          float s,t,r;
            float value1 = registor[s];
            float value2 = registor[t];
            float sum  = value1+value2;
            registor[r] = sum;
  
		
	}
};
#endif