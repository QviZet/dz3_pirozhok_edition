#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <exception>
#include <stdexcept>
#include <functional>
#include <conio.h>
#include <windows.h>

void fillReestr(std::vector<std::string>& data, std::string& fileName); // заполнение вектора

void editFile(std::string& fileName); // редактирование файла

bool checkAr(std::vector<std::string>& data); // проверка символов для арифметических вычислений

bool checkLo(std::vector<std::string>& data); // проверка для логических вычислений

int my_pow(int frst, int scnd); // степень для арифметических операций

int konu(int frst, int scnd);   //...^...

int disu(int frst, int scnd);   //...U...

int ksor(int frst, int scnd);   //...(+)...

int inve(int frst, int scnd);   //...inv...

void solverAr(std::vector<std::string>& reestr, bool& flag, int i);

void solverLo(std::vector<std::string>& reestr, bool& flag, int i);