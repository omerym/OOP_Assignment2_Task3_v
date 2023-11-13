#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class loadToRegister: public Operator
{
  public:
  loadToRegister(MemortUnit* Current_ram,MemortUnit* Current_register, MemortUnit* controller): Operator(Current_ram,Current_register,controller) {};

  void apply()
  {
    unsigned short instruct= controller->readInstruction(1);
    unsigned char reg= (instruct & 0x0f00)>>8;
    unsigned char address=(instruct & 0x00ff);
    registors->set((unsigned char)reg,address);

  }
}
;
