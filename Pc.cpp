#include "Pc.h"
#include <iostream>

Pc::Pc() {
	cpu = new Cpu();
	gpu = new Gpu();
	ram = new Ram();
	ssd = new Ssd();
	printf("PC was created with defoult params.\n\n");
}
Pc::Pc(Cpu* cpu, Gpu* gpu, Ram* ram, Ssd* ssd) {
	this->cpu = cpu;
	this->gpu = gpu;
	this->ram = ram;
	this->ssd = ssd;
	printf("PC was created.\n\n");
}
Pc::~Pc() {
	cpu->~Cpu();
	gpu->~Gpu();
	ram->~Ram();
	ssd->~Ssd();
	printf("PC was removed.\n\n");
}

void Pc::getCpu(Cpu* cpu) {
	cpu = this->cpu;
}
void Pc::setCpu(Cpu* cpu) {
	std::cout << "CPU was changed for pc.\n'" << this->cpu->getName() << "' -> '" << cpu->getName() << "'\n\n";
	this->cpu = cpu;
}

void Pc::getGpu(Gpu* gpu) {
	gpu = this->gpu;
}
void Pc::setGpu(Gpu* gpu) {
	std::cout << "GPU was changed for pc.\n'" << this->gpu->getName() << "' -> '" << gpu->getName() << "'\n\n";
	this->gpu = gpu;
}

void Pc::getRam(Ram* ram) {
	ram = this->ram;
}
void Pc::setRam(Ram* ram) {
	std::cout << "RAM was changed for pc.\n'" << this->ram->getName() << "' -> '" << ram->getName() << "'\n\n";
	this->ram = ram;
}

void Pc::getSsd(Ssd* ssd) {
	ssd = this->ssd;
}
void Pc::setSsd(Ssd* ssd) {
	std::cout << "SSD was changed for pc.\n'" << this->ssd->getName() << "' -> '" << ssd->getName() << "'\n\n";
	this->ssd = ssd;
}

void Pc::InfoPC() {
	std::cout << "Info about PC :" << std::endl;
	std::cout << "(CPU): ";
	std::cout << cpu->ParamsToString() << std::endl;
	std::cout << "(GPU): ";
	std::cout << gpu->ParamsToString() << std::endl;
	std::cout << "(RAM): ";
	std::cout << ram->ParamsToString() << std::endl;
	std::cout << "(SSD): ";
	std::cout << ssd->ParamsToString() << std::endl << std::endl;
}

int Pc::Benchmark() {
	return cpu->getFrequency() * cpu->getCores() + gpu->getFrequency() * gpu->getMemory() + ram->getFrequency() * ram->getMemory() + ssd->getSpeed();
}

int Pc::Consumption() {
	return cpu->getPower() + gpu->getPower() + ram->getPower() + ssd->getPower();
}
