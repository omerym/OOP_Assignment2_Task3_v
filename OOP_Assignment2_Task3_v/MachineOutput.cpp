#ifndef _MachineOutput
#define _MachineOutput
#include <string>
using namespace std;
class MachineOutput
{
public:
	virtual void Print(string s) = 0;
};
#endif // !_MachineOutput
