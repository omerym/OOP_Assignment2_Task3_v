#ifndef _ConsoleOutput
#define _ConsoleOutput
#include <string>
#include <iostream>
#include "MachineOutput.cpp"
using namespace std;
class ConsoleOutput : public MachineOutput
{
	ostream* output;
public:
	ConsoleOutput(ostream *ostream = &cout)
	{
		output = ostream;
	}
	virtual void Print(string s)
	{
		*output << s << endl;
	}
};
#endif // !_ConsoleOutput
