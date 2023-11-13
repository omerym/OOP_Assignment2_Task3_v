#ifndef _ConsoleOutput
#define _ConsoleOutput
#include <string>
#include <iostream>
#include <iomanip>
#include "MachineOutput.cpp"
using namespace std;
class ConsoleOutput : public MachineOutput
{
	ostream* output;
public:
	ConsoleOutput(ostream* ostream = &cout)
	{
		output = ostream;
	}
	virtual void Print(string s)
	{
		*output << "Output:  " << s << endl;
	}	
	virtual void PrintTitle(string s)
	{
		*output << s;
	}
	virtual void UpdateRam(unsigned char val, unsigned char pos)
	{
		(*output) << hex << setfill('0') << setw(2) << (int)pos << ":       ";
		(*output) << hex << setfill('0') << setw(2) << (int)val << endl;
	}
	virtual void UpdateRegistors(unsigned char val, unsigned char pos)
	{
		(*output) << hex << setfill('0') << setw(2) << (int)pos << ":       ";
		(*output) << hex << setfill('0') << setw(2) << (int)val << endl;
	}
	virtual void UpdateProgramCounter(unsigned char val)
	{
		(*output) << "Program Counter: " << hex << setfill('0') << setw(2) << (int)val << endl;
	}
	virtual void UpdateLastInstruction(unsigned short val)
	{
		(*output) << "Last Instruction: " << hex << setfill('0') << setw(2) << (int)val << endl;
	}
};
#endif // !_ConsoleOutput
