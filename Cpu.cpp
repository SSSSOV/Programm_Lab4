#include "Cpu.h"
#include <iostream>

Cpu::Cpu() : Part("defaultCPU", 10) {
	frequency = 1000;
	cores = 1;
	threads = 1;
	std::cout << "CPU '" << name << "' was created with default params.\n";
}
Cpu::Cpu(std::string name) : Part(name, 10) {
	frequency = 1000;
	cores = 1;
	threads = 1;
	std::cout << "CPU '" << name << "' was created with default params.\n";
}
Cpu::Cpu(std::string name, int frequency, int cores, int threads, int power) : Part(name, power) {
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
	std::cout << "CPU '" << name << "' was created.\n";
}
Cpu::~Cpu() {
	//amount--;
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

std::string Cpu::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(cores) + " cores, " + std::to_string(threads) + " threads, " + std::to_string(power) + " W.";
}
void operator << (std::ostream& o, Cpu cpu) {
	std::cout << cpu.ParamsToString() + "\n";
}
Cpu operator >> (std::istream& o, Cpu& cpu) {
	std::cin >> cpu.name >> cpu.frequency >> cpu.cores >> cpu.threads >> cpu.power;
	return cpu;
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

void Cpu::operator=(Part* part) {
	name = part->getName();
	frequency = 1000;
	cores = 1;
	threads = 1;
	power = part->getPower();
}

int Cpu::Benchmark() {
	return frequency * threads;
}