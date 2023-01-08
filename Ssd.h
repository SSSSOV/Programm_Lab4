#pragma once
#include <string>
#include "Part.h"

class Ssd: public Part {
private:
	int speed;
	int memory;	

public:
	Ssd();
	Ssd(std::string name);
	Ssd(std::string name, int speed, int memory, int power);
	~Ssd();

	int getSpeed();
	void setSpeed(int speed);

	int getMemory();
	void setMemory(int memory);

	std::string ParamsToString();
	friend void operator << (std::ostream&, Ssd);
	friend Ssd operator >> (std::istream&, Ssd&);

	void operator= (Part*);

	int Benchmark();
};