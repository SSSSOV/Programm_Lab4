#include "Ram.h"
#include <iostream>

Ram::Ram() : Part("defaultRAM", 10) {
	frequency = 1000;
	memory = 1;
	std::cout << "RAM '" << name << "' was created with default params.\n";
}
Ram::Ram(std::string name) : Part(name, 10) {
	frequency = 1000;
	memory = 1;
	std::cout << "RAM '" << name << "' was created with default params.\n";
}
Ram::Ram(std::string name, int frequency, int memory, int power) : Part(name, power) {
	this->frequency = frequency;
	this->memory = memory;
	std::cout << "RAM '" << name << "' was created.\n";
}
Ram::~Ram() {
	//std::cout << "RAM '" << name << "' was removed.\n";
}

int Ram::getFrequency() {
	return frequency;
}
void Ram::setFrequency(int frequency) {
	this->frequency = frequency;
}

int Ram::getMemory() {
	return memory;
}
void Ram::setMemory(int memory) {
	this->memory = memory;
}

std::string Ram::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(memory) + " Gb, " + std::to_string(power) + " W.";
}
void operator << (std::ostream& o, Ram ram) {
	std::cout << ram.ParamsToString() + "\n";
}
Ram operator >> (std::istream& o, Ram& ram) {
	std::cin >> ram.name >> ram.frequency >> ram.memory >> ram.power;
	return ram;
}

void Ram::operator=(Part* part) {
	name = part->getName();
	frequency = 1000;
	memory = 1;
	power = part->getPower();
}

int Ram::Benchmark() {
	return frequency * memory;
}