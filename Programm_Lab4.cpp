#include <iostream>
#include "Cpu.h"
#include "Gpu.h"
#include "Ram.h"
#include "Ssd.h"
#include "Pc.h"

int Cpu::amount = 0;

class people {
protected:
	std::string name;
	int age;
public:
	void Init(std::string name, int age) {
		this->name = name;
		this->age = age > 0 ? age : 1;
	}
	virtual void Display() = 0;
};

class user : public people {
public:
	void Display() {
		std::cout << "(user) " << name << ", " << age << "\n";
	}
};

class admin : public people {
public:
	void Display() {
		std::cout << "(admin) " << name << ", " << age << "\n";
	}
};

template <class C> class storage {
private:
	C strg[3];
	int index;
public:
	storage() {
		index = 0;
		std::cout << "Storage created.\n";
	}
	~storage() {
		std::cout << "Storage deleted.\n";
	}

	void push(C element) {
		if (index == 3) {
			std::cout << "Storage is full!\n";
			return;
		}
		strg[index] = element;
		index++;
		std::cout << "Element pushed in stotage.\n";
	}

	C pop() {
		if (index == 0) {
			std::cout << "Storage is empty!\n";
			return;
		}
		index--;
		return strg[index];
		std::cout << "Element poped from stotage.\n";
	}

	int getAmount() {
		return index;
	}
};

int main() {
	std::cout << "\tOverload method ParamsToString():" << "\n\n";
	Cpu* cpu1 = new Cpu();
	std::cout << cpu1->ParamsToString() << "\n\n";
	std::cout << cpu1->Part::ParamsToString() << "\n\n";

	std::cout << "\tCalling the base class constructor:" << "\n\n";
	Cpu* cpu2 = new Cpu("Ryzen 5", 4200, 6, 12, 65);
	std::cout << cpu2->ParamsToString() << "\n\n";

	std::cout << "\tOverload the operator = for derived classes:" << "\n\n";
	Part* part1 = new Part();
	*cpu2 = part1;
	std::cout << cpu2->ParamsToString() << "\n\n";

	std::cout << "\tOverload the operators << and >>:" << "\n\n";
	std::cout << *part1;
	std::cout << "\n";
	Ssd* ssd1 = new Ssd();
	std::cout << *ssd1;
	std::cout << "\n";

	std::cout << "\tOverload the virtual method:" << "\n\n";
	std::cout << *part1;
	std::cout << part1->Benchmark() << "\n";
	std::cout << ssd1->Benchmark() << "\n";

	std::cout << "\tAbstract class:" << "\n\n";
	people* people = new user();
	people->Init("Klass", 19);
	people->Display();
	people = new admin();
	people->Init("Kyklin", 20);
	people->Display();

	std::cout << "\n\tTemplates class:" << "\n\n";
	storage<Part> storage;
	storage.push(*part1);
	std::cout << "Amount items in storage:" << storage.getAmount()<<"\n";
	storage.push(*cpu1);
	std::cout << "Amount items in storage:" << storage.getAmount() << "\n";
	storage.push(*cpu2);
	std::cout << "Amount items in storage:" << storage.getAmount() << "\n";
	storage.push(*ssd1);
}