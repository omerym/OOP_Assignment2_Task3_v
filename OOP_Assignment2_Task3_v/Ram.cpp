#ifndef _Ram
#define _Ram

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "MemoryUnit.cpp"
using namespace std;
class Ram : public MemortUnit
{
public:
	Ram(int size, MachineOutput *output) : MemortUnit(size,output) {};
	virtual void set(unsigned char pos, unsigned char value)
	{
		MemortUnit::set(pos, value);
		if (pos == 0)
		{
			ostringstream oss;
			oss << hex << setfill('0') <<setw(2) << (int)value;
			output->Print(oss.str());
		}
	}
};
#endif // !_Ram
