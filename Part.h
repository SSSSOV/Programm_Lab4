#pragma once
#include <string>

class Part {
protected:
	static int amount;
	int id;
	std::string name;
	int power;

public:
	Part();
	Part(std::string, int);

	int getId(int&);
	int getId(int*);

	std::string getName();
	void setName(std::string name);

	int getPower();
	void setPower(int power);

	std::string ParamsToString();
	friend void operator << (std::ostream&, Part);
	friend Part operator >> (std::istream&, Part&);

	static int getAmount();

	virtual int Benchmark();
};