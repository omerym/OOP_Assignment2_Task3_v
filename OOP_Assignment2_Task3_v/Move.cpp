#ifndef _Move
#define _Move

#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class StoreMemCell: public Operator
{
  public:
  StoreMemCell(MemortUnit* Current_ram,MemortUnit* Current_register, MemortUnit* controller): Operator(Current_ram,Current_register,controller) {};

  void apply()
  {
    unsigned short instruct= controller->readInstruction(1);
    unsigned char R= (instruct & 0x00f0)>>4;
    unsigned char S=(instruct & 0x000f);
    ram->set(R,S);

  }
}
;
#endif
