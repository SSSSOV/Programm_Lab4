#include "Gpu.h"
#include <iostream>

Gpu::Gpu() {
	name = "defoultGPU";
	frequency = 1000;
	memory = 1;
	power = 10;
	std::cout << "GPU '" << name << "' was created with defoult params.\n";
}
Gpu::Gpu(std::string name) {
	this->name = name;
	frequency = 1000;
	memory = 1;
	power = 10;
	std::cout << "GPU '" << name << "' was created with defoult params.\n";
}
Gpu::Gpu(std::string name, int frequency, int memory, int power) {
	this->name = name;
	this->frequency = frequency;
	this->memory = memory;
	this->power = power;
	std::cout << "GPU '" << name << "' was created.\n";
}
Gpu::~Gpu() {
	std::cout << "GPU '" << name << "' was removed.\n";
}

std::string Gpu::getName() {
	return name;
}
void Gpu::setName(std::string name) {
	this->name = name;
}

int Gpu::getFrequency() {
	return frequency;
}
void Gpu::setFrequency(int frequency) {
	this->frequency = frequency;
}

int Gpu::getMemory() {
	return memory;
}
void Gpu::setMemory(int memory) {
	this->memory = memory;
}

int Gpu::getPower() {
	return power;
}
void Gpu::setPower(int power) {
	this->power = power;
}

std::string Gpu::ParamsToString() {
	return name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(memory) + " Gb, " + std::to_string(power) + " W.";
}
