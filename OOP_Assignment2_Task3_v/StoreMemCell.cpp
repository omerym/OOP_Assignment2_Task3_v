#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class StoreMemCell: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  MemortUnit* controller;
  unsigned char address1;
  int Mem;
  public:
  StoreMemCell(MemortUnit* Current_ram,MemortUnit* Current_register, MemortUnit* controller): Operator(Current_ram,Current_register,controller) {};

  void apply()
  {
    unsigned short instruct= controller->readInstruction(1);
    unsigned char reg= (instruct & 0x0f00)>>8;
    unsigned char address=(instruct & 0x00ff);
    unsigned char BitPattern=Current_register->get((unsigned char)reg);
    Current_ram->set((unsigned char)address,BitPattern);

  }
}
;