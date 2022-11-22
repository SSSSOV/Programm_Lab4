#pragma once
#include <string>
class Cpu {
private:
	std::string name;
	int frequency;
	int cores;
	int threads;
	int power;

public:
	Cpu();
	Cpu(std::string name);
	Cpu(std::string name, int frequency, int cores, int threads, int power);
	~Cpu();

	std::string getName();
	void setName(std::string name);

	int getFrequency();
	void setFrequency(int frequency);

	int getCores();
	void setCores(int cores);

	int getThreads();
	void setThreads(int threads);

	int getPower();
	void setPower(int power);

	std::string ParamsToString();
};

