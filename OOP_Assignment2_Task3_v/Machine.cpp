#ifndef _Machine
#define _Machine

#include <exception>
#include <iostream>
#include "Decoder.cpp"
#include "Ram.cpp"
#include "MachineOutput.cpp"
using namespace std;
class Machine
{
public:
	Machine(MachineOutput *output, int startPos = 0)
	{
		this->output = output;
		ram = new Ram(256, output);
		registors = new MemortUnit(16, output);
		controller = new MemortUnit(4, output);
		controller->set(0, startPos);
		decoder = new Decoder(ram, registors, controller);
	}
	MemortUnit* getRam()
	{
		return ram;
	}	
	MemortUnit* getRegistors()
	{
		return registors;
	}
	MemortUnit* getConroller()
	{
		return controller;
	}
	void step()
	{
		fetch();
		Operator* op = decode();
		execute(op);
	}
	bool isRunning()
	{
		return running;
	}
	~Machine()
	{
		delete ram;
		delete registors;
		delete controller;
		delete decoder;
	}
private:
	void fetch()
	{
		unsigned char counter = controller->get(0);
		controller->writeInstruction(1, ram->readInstruction(counter));
		controller->set(0, counter + 2);
	}
	Operator* decode()
	{
		return decoder->getOperation(controller->readInstruction(1));
	}
	void execute(Operator* op)
	{
		if (op == NULL)
		{
			output->Print("Invalid instruction");
		}
		else
		{
			op->apply();
		}
		running = controller->get(3) != 0;
	}
	bool running = true;
	Ram* ram;
	MemortUnit* registors;
	// 0 -> program counter
	// 1,2 -> current instruction
	// 3 -> != 0 : running, == 0 : stopped
	MemortUnit* controller;
	Decoder* decoder;
	MachineOutput* output;
};
#endif
