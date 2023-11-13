#ifndef _MachineOutput
#define _MachineOutput
#include <string>
using namespace std;
class MachineOutput
{
public:
	virtual void Print(string s) = 0;
	virtual void PrintTitle(string s) = 0;
	virtual void UpdateRam(unsigned char val, unsigned char pos) = 0;
	virtual void UpdateRegistors(unsigned char val, unsigned char pos) = 0;
	virtual void UpdateProgramCounter(unsigned char val) = 0;
	virtual void UpdateLastInstruction(unsigned short val) = 0;
};
#endif // !_MachineOutput
