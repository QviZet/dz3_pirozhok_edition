#include "Header.h"

std::map <std::string, std::function<int(int, int)>> arOp
{
	{"+", std::plus<int>()},
	{"-", std::minus<int>()},
	{"*", std::multiplies<int>()},
	{"/", std::divides <int>()},
	{"^", my_pow}
};

std::map <std::string, std::function<int(int, int)>> loOp
{
	{"^", konu},
	{"U", disu},
	{"+", ksor},
	{"!", inve},
};

void fillReestr(std::vector<std::string>& data, std::string& fileName)
{
	std::ifstream read(fileName);
	if (!read)
	{
		std::cout << "Ошибка, файл не найден" << std::endl;
		system("pause");
	}
	std::string a;
	while (read.peek() != EOF) {
		read >> a;
		data.push_back(a);
	}
	read.close();
}

std::map<std::string, int> log_operations
{
	{"^", 1}, {"U", 2}, {"+", 3}, {"!", 4}
};

int my_pow(int frst, int scnd) {   //...^...
	int ans = 1;
	for (int i = 0; i < scnd; i++) {
		ans = ans * frst;
	}
	return ans;
}

int konu(int frst, int scnd) {   //...^...
	int ans = frst * scnd;
	return ans;
}

int disu(int frst, int scnd) {   //...U...
	int ans = frst + scnd - (frst * scnd);
	return ans;
}

int ksor(int frst, int scnd) {   //...(+)...
	int ans = frst + scnd - 2 * frst * scnd;
	return ans;
}

int inve(int frst, int scnd) {   //...inv...
	int ans = 1 - scnd;
	return ans;
}

void solverAr(std::vector<std::string>& reestr, bool& flag, int i) {
	reestr[i - 2] = std::to_string(arOp[reestr[i]](stoi(reestr[i - 2]), stoi(reestr[i - 1]))); //заменяем элемент [i - 2] на ans
	reestr.erase(reestr.cbegin() + i); //удаляем элемент [i]
	reestr.erase(reestr.cbegin() + i - 1); //удаляем элемент [i - 1]
	flag = true;
}

void solverLo(std::vector<std::string>& reestr, bool& flag, int i) {
	if (reestr[i] == "!") {
		reestr[i - 1] = std::to_string(loOp[reestr[i]](0, stoi(reestr[i - 1])));
		reestr.erase(reestr.cbegin() + i);
		flag = true;
	}
	else {
		reestr[i - 2] = std::to_string(loOp[reestr[i]](stoi(reestr[i - 2]), stoi(reestr[i - 1])));
		reestr.erase(reestr.cbegin() + i);
		reestr.erase(reestr.cbegin() + i - 1);
		flag = true;
	}
}