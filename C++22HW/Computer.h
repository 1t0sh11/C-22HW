#pragma once
#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Computer
{
	int size;
public:
	string name;
	int frequency;
	int ram;
	bool dvd;
	float price;
	
	Computer(string name, double frequency, int ram, bool dvd, double price);
	void print() const;

};
void printVector(const std::vector<Computer>& vec);
