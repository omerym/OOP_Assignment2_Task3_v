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
	cout << "Enter path to a program to load: ";
	char c[200];
	cin >> c;
	fstream fs;
	fs.open(c);
	int ofset;
	cout << "Enter program starting position: ";
	cin >> ofset;
	FileReader fr(&fs);
	ConsoleOutput co;
	Machine machine(&co);
	fr.read(machine.getRam(), ofset);
	bool run = true;
	while (machine.isRunning() && run)
	{
		int code;
		cout << "Enter operation code: \n0: step the program\n1: print the program counter\n"<<
			"2: print last instruction\n3: print ram\n4: print registors\n5: print machine state\n10: exit\n\n";
		cin >> code;
		switch (code)
		{
		case 0:
			machine.step();
			break;
		case 1:
			co.UpdateProgramCounter(machine.getConroller()->get(0));
			break;
		case 2:
			co.UpdateLastInstruction(machine.getConroller()->readInstruction(1));
			break;
		case 3:
			co.PrintTitle("Ram:\n");
			machine.getRam()->update();
			break;
		case 4:
			co.PrintTitle("Registors:\n");
			machine.getRegistors()->update();
			break;
		case 5:
			machine.update();
			break;
		case 10:
			run = false;
			break;
		default:
			break;
		}
	}
	cout << "Program finished.\n";
	machine.update();
	cout << "Program finished.\n";
	return 0;
}
