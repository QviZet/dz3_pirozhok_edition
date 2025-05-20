#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <exception>
#include <stdexcept>
#include <functional>

void fillReestr(std::vector<std::string>& data, std::string& fileName);

int my_pow(int frst, int scnd);

int konu(int frst, int scnd);   //...^...

int disu(int frst, int scnd);   //...U...

int ksor(int frst, int scnd);   //...(+)...

int inve(int frst, int scnd);   //...inv...

void solverAr(std::vector<std::string>& reestr, int frst, int scnd, std::string& cur, bool flag);

void solverLo(std::vector<std::string>& reestr, int frst, int scnd, std::string& cur, bool flag);