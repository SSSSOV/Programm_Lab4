#pragma once
#include <string>
#include "Part.h"

class Gpu: public Part {
private:
	int frequency;	
	int memory;

public:
	Gpu();
	Gpu(std::string name);
	Gpu(std::string name, int frequency, int memory, int power);
	~Gpu();

	int getFrequency();
	void setFrequency(int frequency);

	int getMemory();
	void setMemory(int memory);

	std::string ParamsToString();
	friend void operator << (std::ostream&, Gpu);
	friend Gpu operator >> (std::istream&, Gpu&);

	void operator= (Part*);

	int Benchmark();
};