#include "Operation.cpp"
#include "iostream"
#include "MemoryUnit.cpp"
#include "Ram.cpp"
#include <bitset>
class loadRegister: public Operator
{
  private:
  MemortUnit* Current_ram; 
  MemortUnit* Current_register;
  unsigned char address1;
  int Mem;
  public:
  loadRegister(MemortUnit* Current_ram,MemortUnit* Current_register): Operator(Current_ram,Current_register) {};
  void initialize(auto instruct)
  {
    unsigned char* start=instruct;
    Address1=start;
    unsigned char AddressH=start+4;
    unsigned char AddressH2=Start+8;
    bitset<4> Bits1(AddressH);
    bitset<4> Bits2(AddressH2);
    Mem=int(Bits1+Bits2);
    delete start;
  }
  void apply()
  {
    unsigned char BitPattern=Current_ram->get(address1);
    Current_register->set(Current_register->get(Mem),BitPattern);

  }
}
;