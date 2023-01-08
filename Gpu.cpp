#include "Gpu.h"
#include <iostream>

Gpu::Gpu() : Part("defaultGPU", 10) {
	frequency = 1000;
	memory = 1;
	std::cout << "GPU '" << name << "' was created with default params.\n";
}
Gpu::Gpu(std::string name) : Part(name, 10) {
	frequency = 1000;
	memory = 1;
	std::cout << "GPU '" << name << "' was created with default params.\n";
}
Gpu::Gpu(std::string name, int frequency, int memory, int power) : Part(name, power) {
	this->frequency = frequency;
	this->memory = memory;
	std::cout << "GPU '" << name << "' was created.\n";
}
Gpu::~Gpu() {
	//std::cout << "GPU '" << name << "' was removed.\n";
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

std::string Gpu::ParamsToString() {
	return "#" + std::to_string(id) + " " + name + ", " + std::to_string(frequency) + " Ghz, " + std::to_string(memory) + " Gb, " + std::to_string(power) + " W.";
}
void operator << (std::ostream& o, Gpu gpu) {
	std::cout << gpu.ParamsToString() + "\n";
}
Gpu operator >> (std::istream& o, Gpu& gpu) {
	std::cin >> gpu.name >> gpu.frequency >> gpu.memory >> gpu.power;
	return gpu;
}

void Gpu::operator=(Part* part) {
	name = part->getName();
	frequency = 1000;
	memory = 1;
	power = part->getPower();
}

int Gpu::Benchmark() {
	return frequency * memory;
}