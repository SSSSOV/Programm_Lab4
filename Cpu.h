#pragma once
#include <string>
class Cpu {
private:
	static int amount;
	int id;
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

	int getId(int&);
	int getId(int*);

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

	Cpu operator+ (const Cpu&);
	Cpu& operator++ ();
	Cpu& operator++ (int);
	Cpu& operator= (Cpu&);

	static int getAmount();

	friend void setId(Cpu& cpu, int newId);
};


