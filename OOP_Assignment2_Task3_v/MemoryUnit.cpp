#ifndef _MemoryUnit
#define _MemoryUnit
#include "MachineOutput.cpp"
#include <exception>
using namespace std;
class MemortUnit
{
public:
	MemortUnit(int size, MachineOutput *output);
	~MemortUnit();
	int size();
	unsigned char get(unsigned char pos);
	unsigned short readInstruction(unsigned char pos);
	void writeInstruction(unsigned char pos,unsigned short instruction);
	virtual void set(unsigned char pos, unsigned char value);
unsigned char *at(unsigned char pos);

protected:
	MachineOutput *output;
private:
	int _size;
	unsigned char* _data;
};

MemortUnit::MemortUnit(int size, MachineOutput* output)
{
	_size = size;
	this->output = output;
	_data = new unsigned char[size];
}

MemortUnit::~MemortUnit()
{
	delete [] _data;
}
int MemortUnit::size()
{
	return _size;
}
unsigned char MemortUnit::get(unsigned char pos)
{
	if (pos < 0 || pos >= _size)
	{
		throw out_of_range("Outside memory position");
	}
	return _data[pos];
}
unsigned short MemortUnit::readInstruction(unsigned char pos)
{
	short l = get(pos) << 8;
	short r = get(pos + 1);
	return r | l;
}
void MemortUnit::writeInstruction(unsigned char pos, unsigned short instruction)
{
	set(pos, (instruction & 0xff00) >> 8);
	set(pos + 1, (instruction & 0x00ff));
}
void MemortUnit::set(unsigned char pos, unsigned char value)
{
	if (pos < 0 || pos >= _size)
	{
		throw out_of_range("Outside memory position");
	}
	_data[pos] = value;
}
unsigned char * MemortUnit::at(unsigned char pos)
{
	if (pos < 0 || pos >= _size)
	{
		throw out_of_range("Outside memory position");
	}
	return _data + pos;
}
#endif // !_MemoryUnit
