#include "Ssd.h"
#include <iostream>

Ssd::Ssd() {
	name = "defoultSSD";
	speed = 1000;
	memory = 1;
	power = 10;
	std::cout << "SSD '" << name << "' was created with defoult params.\n";
}
Ssd::Ssd(std::string name) {
	this->name = name;
	speed = 1000;
	memory = 1;
	power = 10;
	std::cout << "SSD '" << name << "' was created with defoult params.\n";
}
Ssd::Ssd(std::string name, int speed, int memory, int power) {
	this->name = name;
	this->speed = speed;
	this->memory = memory;
	this->power = power;
	std::cout << "SSD '" << name << "' was created.\n";
}
Ssd::~Ssd() {
	//std::cout << "RAM '" << name << "' was removed.\n";
}

std::string Ssd::getName() {
	return name;
}
void Ssd::setName(std::string name) {
	this->name = name;
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

int Ssd::getPower() {
	return power;
}
void Ssd::setPower(int power) {
	this->power = power;
}

std::string Ssd::ParamsToString() {
	return name + ", " + std::to_string(speed) + " Mb\\s, " + std::to_string(memory) + " Gb, " + std::to_string(power) + " W.";
}