#include "Part.h"
#include <iostream>

Part::Part() {
	name = "defaultPart";
	power = 10;
	amount++;
	id = amount;
}
Part::Part(std::string name, int power) {
	this->name = name;
	try {
		if (power < 1) throw "InvalidPower";
		this->power = power;
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		this->power = 10;
	}
	amount++;
	id = amount;
}

int Part::getId(int& id) {
	id = this->id;
	return this->id;
}
int Part::getId(int* id) {
	*id = this->id;
	return this->id;
}

std::string Part::getName() {
	return name;
}
void Part::setName(std::string name) {
	this->name = name;
}

int Part::getPower() {
	return power;
}
void Part::setPower(int power) {
	try {
		if (power < 1) throw "InvalidPower";
		this->power = power;
		std::cout << "Power value was changed.\n";
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		std::cout << "Power value has not changed.\n";
	}
}

std::string Part::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(power) + " W, " + std::to_string(Benchmark()) + " pts.";
}
void operator << (std::ostream& o, Part part) {
	std::cout << part.ParamsToString() + "\n";
}
Part operator >> (std::istream& o, Part& part){
	std::cin >> part.name >> part.power;
	return part;
}

int Part::getAmount() {
	return amount;
}

int Part::Benchmark() {
	return 0;
}