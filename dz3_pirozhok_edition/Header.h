#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

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