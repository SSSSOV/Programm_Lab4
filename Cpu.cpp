#include "Cpu.h"
#include <iostream>

Cpu::Cpu() {
	name = "defoultCPU";
	frequency = 1000;
	cores = 1;
	threads = 1;
	power = 10;
	std::cout << "CPU '" << name << "' was created with defoult params.\n";
}
Cpu::Cpu(std::string name) {
	this->name = name;
	frequency = 1000;
	cores = 1;
	threads = 1;
	power = 10;
	std::cout << "CPU '" << name << "' was created with defoult params.\n";
}
Cpu::Cpu(std::string name, int frequency, int cores, int threads, int power) {
	this->name = name;
	this->frequency = frequency;
	this->cores = cores;
	this->threads = threads;
	this->power = power;
	std::cout << "CPU '" << name << "' was created.\n";
}
Cpu::~Cpu() {
	std::cout << "CPU '" << name << "' was removed.\n";
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
	return name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(cores) + " cores, " + std::to_string(threads) + " threads, " + std::to_string(power) + " W.";
}