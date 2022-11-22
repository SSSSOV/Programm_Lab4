#pragma once
#include <string>
class Ram {
private:
	std::string name;
	int frequency;	
	int memory;		
	int power;

public:
	Ram();
	Ram(std::string name);
	Ram(std::string name, int frequency, int memory, int power);
	~Ram();

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

