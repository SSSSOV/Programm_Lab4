#pragma once
#include <string>
#include "Part.h"

class Ram: public Part {
private:
	int frequency;	
	int memory;		

public:
	Ram();
	Ram(std::string name);
	Ram(std::string name, int frequency, int memory, int power);
	~Ram();

	int getFrequency();
	void setFrequency(int frequency);

	int getMemory();
	void setMemory(int memory);

	std::string ParamsToString();
	friend void operator << (std::ostream&, Ram);
	friend Ram operator >> (std::istream&, Ram&);

	void operator= (Part*);

	int Benchmark();
};