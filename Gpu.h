#pragma once
#include <string>
class Gpu {
private:
	std::string name;	
	int frequency;	
	int memory;
	int power;

public:
	Gpu();
	Gpu(std::string name);
	Gpu(std::string name, int frequency, int memory, int power);
	~Gpu();

	std::string getName();
	void setName(std::string name);

	int getFrequency();
	void setFrequency(int frequency);

	int getMemory();
	void setMemory(int memory);

	int getPower();
	void setPower(int power);

	std::string ParamsToString();
};

