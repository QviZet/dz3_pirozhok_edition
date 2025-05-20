#include "Header.h"

std::map<std::string, int> log_operations
{
	{"^", 1}, {"U", 2}, {"+", 3}, {"!", 4}
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

void solverAr(std::vector<std::string>& reestr, ar& newAr, std::string& cur, bool flag) {
	std::map <std::string, std::function<int(ar&)>> operations
	{
		{"+", sloz(newAr)},
		{"-", std::minus<int>()},
		{"*", std::multiplies<int>()},
		{"/", std::divides <int>()},
		{"^", step(newAr)}
	};
}

void solverLo(std::vector<std::string>& reestr, lo& newLo, std::string& cur, bool flag) {

}