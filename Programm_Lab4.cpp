#include <iostream>
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"
#include "Ssd.h"
#include "Pc.h"

int Cpu::amount = 0;

void setId(Cpu& cpu, int newId) {
	cpu.id = newId;
}

int main() {
	Cpu cpu1("cpu1");
	Cpu cpu2("cpu2");
	std::cout << "\n(1-3): " << std::endl;
	std::cout << "Cpu amount: " << Cpu::getAmount() << "\t// Amount gained using static field and method." << std::endl;

	std::cout << "\n(4): " << std::endl;
	int id;
	cpu1.getId(id);
	std::cout << "'Cpu1' id: " << id << "\t// Id returned using adress." << std::endl;
	cpu2.getId(&id);
	std::cout << "'Cpu2' id: " << id << "\t// Id returned using pointer." << std::endl;

	std::cout << "\n(6) Friend function: " << std::endl;
	setId(cpu2, 5);
	cpu2.getId(&id);
	std::cout << "'Cpu2' id: " << id << "\t// Id changed using friend function." << std::endl;

	std::cout << "\n(7) Friend function: " << std::endl;
	std::cout << cpu1.ParamsToString() << "\t// Params 'cpu1'." << std::endl;
	std::cout << cpu2.ParamsToString() << "\t// Params 'cpu2'." << std::endl;
	Cpu cpu3 = cpu1 + cpu2;
	std::cout << cpu3.ParamsToString() << "\t// Overload '+'." << std::endl;
	cpu3++;
	std::cout << cpu3.ParamsToString() << "\t// Overload '++'." << std::endl;
}