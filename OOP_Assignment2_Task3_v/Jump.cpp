#ifndef _JumpOperation
#define _JumpOperation
#include"Operation.cpp"
class JumpOperation : public Operator
{
public:
	JumpOperation(MemortUnit* ram, MemortUnit* registor, MemortUnit* controller) : Operator(ram,registor,controller) {}
	virtual void apply()
	{
        unsigned char r,address;
        if(registors->get(r) ==registors->get(0)){
            controller->set(0,ram->get(address);
        }
	}
};
#endif
