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
	this->frequency = frequency;
	this->cores = cores;
	this->threads = threads;
	this->power = power;
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
	this->frequency = frequency;
}

int Cpu::getCores() {
	return cores;
}
void Cpu::setCores(int cores) {
	this->cores = cores;
}

int Cpu::getThreads() {
	return threads;
}
void Cpu::setThreads(int threads) {
	this->threads = threads;
}

int Cpu::getPower() {
	return power;
}
void Cpu::setPower(int power) {
	this->power = power;
}

std::string Cpu::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(cores) + " cores, " + std::to_string(threads) + " threads, " + std::to_string(power) + " W.";
}

Cpu Cpu::operator+(const Cpu& cpu) {
	Cpu temp(this->name + "+" + cpu.name, this->frequency + cpu.frequency, this->cores + cpu.cores, this->threads + cpu.threads, this->power + cpu.power);
	return temp;
}
Cpu& Cpu::operator++ () {
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