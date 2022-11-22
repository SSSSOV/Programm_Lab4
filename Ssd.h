#pragma once
#include <string>
class Ssd {
private:
	std::string name;
	int speed;
	int memory;	
	int power;

public:
	Ssd();
	Ssd(std::string name);
	Ssd(std::string name, int speed, int memory, int power);
	~Ssd();

	std::string getName();
	void setName(std::string name);

	int getSpeed();
	void setSpeed(int speed);

	int getMemory();
	void setMemory(int memory);

	int getPower();
	void setPower(int power);

	std::string ParamsToString();
};

