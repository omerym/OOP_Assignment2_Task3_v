#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
class MoveReg: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  public:
  MoveReg(MemortUnit* Current_ram,MemortUnit* Current_register): Operator(Current_ram,Current_register) {};
  void apply(unsigned char FirstRegPos, unsigned char SecondRegPos)
  {
    unsigned char BitPattern=Current_register->get(FirstRegPos);
    Current_register->set(SecondRegPos,BitPattern);
  }
}
;