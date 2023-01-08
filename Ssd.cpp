#include "Ssd.h"
#include <iostream>

Ssd::Ssd() : Part("defaultSSD", 10) {
	speed = 1000;
	memory = 1;
	std::cout << "SSD '" << name << "' was created with default params.\n";
}
Ssd::Ssd(std::string name) : Part(name, 10) {
	speed = 1000;
	memory = 1;
	std::cout << "SSD '" << name << "' was created with default params.\n";
}
Ssd::Ssd(std::string name, int speed, int memory, int power) : Part(name, power) {
	this->speed = speed;
	this->memory = memory;
	std::cout << "SSD '" << name << "' was created.\n";
}
Ssd::~Ssd() {
	//std::cout << "RAM '" << name << "' was removed.\n";
}

int Ssd::getSpeed() {
	return speed;
}
void Ssd::setSpeed(int speed) {
	this->speed = speed;
}

int Ssd::getMemory() {
	return memory;
}
void Ssd::setMemory(int memory) {
	this->memory = memory;
}

std::string Ssd::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(speed) + " Mb\\s, " + std::to_string(memory) + " Gb, " + std::to_string(power) + " W.";
}
void operator << (std::ostream& o, Ssd ssd) {
	std::cout << ssd.ParamsToString() + "\n";
}
Ssd operator >> (std::istream& o, Ssd& ssd) {
	std::cin >> ssd.name >> ssd.speed >> ssd.memory >> ssd.power;
	return ssd;
}

void Ssd::operator=(Part* part) {
	name = part->getName();
	speed = 1000;
	memory = 1;
	power = part->getPower();
}

int Ssd::Benchmark() {
	return speed;
}