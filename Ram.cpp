#include "Ram.h"
#include <iostream>

Ram::Ram() {
	name = "defoultRAM";
	frequency = 1000;
	memory = 1;
	power = 10;
	std::cout << "RAM '" << name << "' was created with defoult params.\n";
}
Ram::Ram(std::string name) {
	this->name = name;
	frequency = 1000;
	memory = 1;
	power = 10;
	std::cout << "RAM '" << name << "' was created with defoult params.\n";
}
Ram::Ram(std::string name, int frequency, int memory, int power) {
	this->name = name;
	this->frequency = frequency;
	this->memory = memory;
	this->power = power;
	std::cout << "RAM '" << name << "' was created.\n";
}
Ram::~Ram() {
	std::cout << "RAM '" << name << "' was removed.\n";
}

std::string Ram::getName() {
	return name;
}
void Ram::setName(std::string name) {
	this->name = name;
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

int Ram::getPower() {
	return power;
}
void Ram::setPower(int power) {
	this->power = power;
}

std::string Ram::ParamsToString() {
	return name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(memory) + " Gb, " + std::to_string(power) + " W.";
}