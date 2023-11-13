#include <iostream>
#include "MemoryUnit.cpp"
#ifndef _Operation
#define _Operation
class Operator
{
protected:
	MemortUnit* ram;
	MemortUnit* registors;
	MemortUnit* controller;
public:
	virtual void apply() = 0;
	Operator(MemortUnit* ram, MemortUnit* registors, MemortUnit* controller)
	{
		this->ram = ram;
		this->registors = registors;
		this->controller = controller;
	}
};
#endif