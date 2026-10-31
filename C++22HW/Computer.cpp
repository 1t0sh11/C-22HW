#include "Computer.h"

Computer::Computer(string name, double frequency, int ram, bool dvd, double cost)
{
	this->name = name;
	this->frequency = frequency;
	this->ram = ram;
	this->dvd = dvd;
	this->cost = cost;
}

void Computer::print() const
{
	cout << "Name: " << name << "\nFrequency: " << frequency << "\nRam amount: " << "\nIs there dvd: " << dvd << "\nCost: " << cost << endl;
}

void printVector(const std::vector<Computer>& vec)
{
	for (int i = 0; i < 5; ++i) {
		cout << vector[i] << endl;
	}
}
