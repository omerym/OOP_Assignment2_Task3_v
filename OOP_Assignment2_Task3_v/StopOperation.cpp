#ifndef _StopOperation
#define _StopOperation
#include"Operation.cpp"
class StopOperation : public Operator
{
public:
	StopOperation(MemortUnit* ram, MemortUnit* registor, MemortUnit* controller) : Operator(ram,registor,controller) {}
	virtual void apply()
	{
		controller->set(3, 0);
	}
};
#endif