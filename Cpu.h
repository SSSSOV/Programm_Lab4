#pragma once
#include <string>
#include "Part.h"

class Cpu: public Part {
private:
	int frequency;
	int cores;
	int threads;


public:
	Cpu();
	Cpu(std::string name);
	Cpu(std::string name, int frequency, int cores, int threads, int power);
	~Cpu();

	int getFrequency();
	void setFrequency(int frequency);

	int getCores();
	void setCores(int cores);

	int getThreads();
	void setThreads(int threads);

	std::string ParamsToString();
	friend void operator << (std::ostream&, Cpu);
	friend Cpu operator >> (std::istream&, Cpu&);

	Cpu operator+ (const Cpu&);
	Cpu& operator++ ();
	Cpu& operator++ (int);
	Cpu& operator= (Cpu&);
	void operator= (Part*);

	int Benchmark();
};