#include "Cpu.h"
#include <iostream>

Cpu::Cpu() {
	name = "defoultCPU";
	frequency = 1000;
	cores = 1;
	threads = 1;
	power = 10;
	std::cout << "CPU '" << name << "' was created with defoult params.\n";
	amount++;
	id = amount;
}
Cpu::Cpu(std::string name) {
	this->name = name;
	frequency = 1000;
	cores = 1;
	threads = 1;
	power = 10;
	std::cout << "CPU '" << name << "' was created with defoult params.\n";
	amount++;
	id = amount;
}
Cpu::Cpu(std::string name, int frequency, int cores, int threads, int power) {
	this->name = name;
	try {
		if (frequency < 1) throw "InvalidFrequency";
		this->frequency = frequency;
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		this->frequency = 1000;
	}
	try {
		if (cores < 1) throw "InvalidCores";
		this->cores = cores;
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		this->cores = 1;
	}
	try {
		if (threads < 1) throw "InvalidThreads";
		this->threads = threads;
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		this->threads = 1;
	}
	try {
		if (power < 1) throw "InvalidPower";
		this->power = power;
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		this->power = 10;
	}
	std::cout << "CPU '" << name << "' was created.\n";
	amount++;
	id = amount;
}
Cpu::~Cpu() {
	//amount--;
}

int Cpu::getId(int& id) {
	id = this->id;
	return this->id;
}
int Cpu::getId(int* id) {
	*id = this->id;
	return this->id;
}

std::string Cpu::getName() {
	return name;
}
void Cpu::setName(std::string name) {
	this->name = name;
}

int Cpu::getFrequency() {
	return frequency;
}
void Cpu::setFrequency(int frequency) {
	try {
		if (frequency < 1) throw "InvalidFrequency";
		this->frequency = frequency;
		std::cout << "Frequency value was changed.\n";
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		std::cout << "Frequency value has not changed.\n";
	}
}

int Cpu::getCores() {
	return cores;
}
void Cpu::setCores(int cores) {
	try {
		if (cores < 1) throw "InvalidCores";
		this->cores = cores;
		std::cout << "Cores value was changed.\n";
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		std::cout << "Cores value has not changed.\n";
	}
}

int Cpu::getThreads() {
	return threads;
}
void Cpu::setThreads(int threads) {
	try {
		if (threads < 1) throw "InvalidThreads";
		this->threads = threads;
		std::cout << "Threads value was changed.\n";
	}
	catch (const char* e) {
		std::cout << "Error! " << e << ".\n";
		std::cout << "Threads value has not changed.\n";
	}
}

int Cpu::getPower() {
	return power;
}
void Cpu::setPower(int power) {
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

std::string Cpu::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(cores) + " cores, " + std::to_string(threads) + " threads, " + std::to_string(power) + " W.";
}

Cpu Cpu::operator+(const Cpu& cpu) {
	Cpu temp(this->name + "+" + cpu.name, this->frequency + cpu.frequency, this->cores + cpu.cores, this->threads + cpu.threads, this->power + cpu.power);
	return temp;
}
Cpu& Cpu::operator++ () {
	name = "(" + name + ")++";
	frequency += frequency;
	cores += cores;
	threads += threads;
	power += power;
	return *this;
}
Cpu& Cpu::operator++ (int) {
	Cpu cpu = *this;
	++*this;
	return cpu;
}
Cpu& Cpu::operator=(Cpu& cpu) {
	frequency = cpu.frequency;
	cores = cpu.cores;
	threads = cpu.threads;
	power = cpu.power;
	return *this;
}

int Cpu::getAmount() {
	return amount;
}