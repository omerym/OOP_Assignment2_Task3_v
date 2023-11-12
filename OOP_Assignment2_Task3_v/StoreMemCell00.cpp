#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class StoreMemCell00: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  public:
  StoreMemCell00(MemortUnit* Current_ram,MemortUnit* Current_register): Operator(Current_ram,Current_register) {};
  void apply(unsigned char regPos)
  {
    unsigned char BitPattern=Current_register->get(regPos);
    Current_ram->set(0,BitPattern);
  }
}
;