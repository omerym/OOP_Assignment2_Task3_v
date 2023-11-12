#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class StoreMemCell: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  public:
  StoreMemCell(MemortUnit* Current_ram,MemortUnit* Current_register): Operator(Current_ram,Current_register) {};
  void apply(unsigned char regPos, unsigned char Address)
  {
    unsigned char BitPattern=Current_register->get(regPos);
    Current_ram->set(Address,BitPattern);
  }
}
;