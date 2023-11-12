#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class loadToRegister: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  public:
  loadToRegister(MemortUnit* Current_ram,MemortUnit* Current_register): Operator(Current_ram,Current_register) {};
  void apply(unsigned char regPos, unsigned char BitV)
  {
    Current_register->set(regPos,BitV);

  }
}
;