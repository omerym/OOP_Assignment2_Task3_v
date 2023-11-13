#ifndef _JumpOperation
#define _JumpOperation
#include"Operation.cpp"
class JumpOperation : public Operator
{
public:
	JumpOperation(MemortUnit* ram, MemortUnit* registor, MemortUnit* controller) : Operator(ram,registor,controller) {}
	virtual void apply()
	{
        int r,address,counter;
        if(registor[r] == registor[0]){
            counter = address;
        }
	
	}
};
#endif