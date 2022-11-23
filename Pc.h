#pragma once
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"
#include "Ssd.h"

class Pc {
private:
	Cpu* cpu;
	Gpu* gpu;
	Ram* ram;
	Ssd* ssd;

public:
	Pc();
	Pc(Cpu* cpu, Gpu* gpu, Ram* ram, Ssd* ssd);
	~Pc();

	void getCpu(Cpu* cpu);
	void setCpu(Cpu* cpu);

	void getGpu(Gpu* gpu);
	void setGpu(Gpu* gpu);

	void getRam(Ram* ram);
	void setRam(Ram* ram);

	void getSsd(Ssd* ssd);
	void setSsd(Ssd* ssd);

	void InfoPC();
	int Benchmark();
	int Consumption();
};

