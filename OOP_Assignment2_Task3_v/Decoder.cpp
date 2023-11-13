#ifndef _Decoder
#define _Decoder

#include <exception>
#include <unordered_map>
#include <iostream>
#include "MemoryUnit.cpp"
#include "Operation.cpp"
#include "StopOperation.cpp"
#include "LoadRegister.cpp"
#include "LoadToRegister.cpp"
#include "StoreMemCell.cpp"
#include "Move.cpp"
#include "Add.cpp"
#include "JumpOperation.cpp"
#include "Operation.cpp"
using namespace std;
class Decoder
{
private: 
unordered_map<unsigned short,Operator*>map;
public:
	
	Decoder(MemortUnit* ram, MemortUnit* registors, MemortUnit* controller)
	{
		map[0x1000] = new LoadRegister(ram, registors, controller);
		map[0x2000] = new LoadToRegister(ram, registors, controller);
		map[0x3000] = new StoreMemCell(ram, registors, controller);
		map[0x4000] = new Move(ram, registors, controller);
		map[0x5000] = new Add(ram, registors, controller);
		map[0xb000] = new JumpOperation(ram, registors, controller);
		map[0xc000] = new StopOperation(ram, registors, controller);
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
