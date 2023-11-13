#ifndef _JumpOperation
#define _JumpOperation
#include"Operation.cpp"
class JumpOperation : public Operator
{
public:
	JumpOperation(MemortUnit* ram, MemortUnit* registor, MemortUnit* controller) : Operator(ram, registor, controller) {}
	virtual void apply()
	{
		unsigned short instruction = controller->readInstruction(1);
		unsigned char r = (instruction & 0x0f00) >> 8;
		unsigned char address = (instruction & 0x00ff);
		if (registors->get(r) == registors->get(0)) 
		{
			controller->set(0, address);
		}
	}
};
#endif
