#ifndef _AddOperation
#define _AddOperation
#include"Operation.cpp"
class AddOperation : public Operator
{
public:
	AddOperation(MemortUnit* ram, MemortUnit* registor, MemortUnit* controller) : Operator(ram,registor,controller) {}
	virtual void apply()
	{
          unsigned short instruct= controller->readInstruction(1);
          unsigned char endplace= (instruct & 0x0f00)>>8;
	  unsigned char Bit1=ram->get((instruct & 0x000f)); 
          unsigned char Bit2=ram->get((instruct & 0x00f0)>>4);
          registors->set((unsigned char)endplace,(Bit1+Bit2));	
	}
};
#endif
