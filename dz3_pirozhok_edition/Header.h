#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <exception>
#include <stdexcept>
#include <functional>

class ar {
	int frst, scnd;
	int ans = 1;
public:
	ar();
	ar(int f, int s);
	~ar();
	int sloz();
	int vych();
	int umno();
	int dele();
	int step();
};

int step(ar& newAr);

class lo {
	int frst, scnd;
	int ans = 1;
public:
	lo();
	lo(int f, int s);
	~lo();
	int konu();
	int disu();
	int inve();
	int ksor();
};

void fillReestr(std::vector<std::string>& data, std::string& fileName);

void solverAr(std::vector<std::string>& reestr, ar& newAr, std::string& cur, bool flag);

void solverLo(std::vector<std::string>& reestr, lo& newLo, std::string& cur, bool flag);