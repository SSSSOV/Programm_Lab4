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
	const int amount_on_shelf = 5, amount_shelfs = 3;
	Cpu* rack_with_cpus[amount_shelfs][amount_on_shelf]{};

	// Creating cpu with invalid frequency.
	rack_with_cpus[0][0] = new Cpu("Ryzen", -4, 324, 2, 4);
	std::cout << rack_with_cpus[0][0]->ParamsToString() << "\n\n";

	// Setting for cpu invalid cores.
	rack_with_cpus[0][0]->setCores(0);
	std::cout << rack_with_cpus[0][0]->ParamsToString() << "\n\n";

	// Setting for cpu correct cores.
	rack_with_cpus[0][0]->setCores(3);
	std::cout << rack_with_cpus[0][0]->ParamsToString() << "\n\n";
}