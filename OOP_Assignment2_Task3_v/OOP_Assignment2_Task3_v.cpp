// OOP_Assignment2_Task3.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <fstream>
#include "Machine.cpp"
#include "ConsoleOutput.cpp"
#include "FileReader.cpp"

using namespace std;

int main()
{
	char c[] = "C:\\Users\\Omer\\Desktop\\A.txt";
	fstream fs;
	fs.open(c);
	FileReader fr(&fs);
	ConsoleOutput out;
	Machine m(&out);
	MemortUnit* ram = m.getRam();
	MemortUnit* cont = m.getConroller();
	MemortUnit* reg = m.getRegistors();
	fr.read(ram);
	m.update();
	m.step();
	m.update();
	m.step();
	m.update();
	return 0;
}
