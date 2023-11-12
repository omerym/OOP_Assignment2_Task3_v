// OOP_Assignment2_Task3.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Machine.cpp"
#include "ConsoleOutput.cpp"
#include "FloatAdder.cpp"

using namespace std;

int main()
{
	ConsoleOutput out;
	Machine m(&out, 2);
	MemortUnit* ram = m.getRam();
	MemortUnit* cont = m.getConroller();
	MemortUnit* reg = m.getRegistors();
	ram->writeInstruction(2, 0x6012);
	return 0;
}
