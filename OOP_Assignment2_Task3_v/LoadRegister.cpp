#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
#include <bitset>
#include "machine.cpp"
class loadRegister: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  MemortUnit* controller;
  unsigned char address1;
  int Mem;
  public:
  loadRegister(MemortUnit* Current_ram,MemortUnit* Current_register, MemortUnit* controller): Operator(Current_ram,Current_register,controller) {};

  void apply()
  {
    unsigned short instruct= controller->readInstruction(1);
    unsigned char reg= (instruct & 0x0f00)>>8;
    unsigned char address=(instruct & 0x00ff);
    unsigned char BitPattern=Current_ram->get((unsigned char)address);
    Current_register->set((unsigned char)reg,BitPattern);

  }
}
;