#ifndef _Decoder
#define _Decoder

#include <exception>
#include <unordered_map>
#include <iostream>
#include "MemoryUnit.cpp"
#include "Operation.cpp"
#include "StopOperation.cpp"
#include "LoadRegistor.cpp"
using namespace std;
class Decoder
{
public:
	Decoder(MemortUnit* ram, MemortUnit* registors, MemortUnit* controller)
	{
		map[0xc000] = new StopOperation(ram, registors, controller);
		map[0x1000] = new LoadRegistor(ram, registors, controller);
	}
	Operator* getOperation(unsigned short instruction)
	{
		instruction &= 0xf000;
		return map[instruction];
	}
	~Decoder()
	{
		for (auto& it : map)
		{
			delete it.second;
		}
	}
};
#endif
