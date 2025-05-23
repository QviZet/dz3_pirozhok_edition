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
	if (!read) { //проверяем существование файла
		std::cout << "Ошибка, файл не найден" << std::endl;
		system("pause");
	}
	std::string a;  //инициализируем строковую переменную
	while (read.peek() != EOF) {
		read >> a;  //записываем элемент выражения
		data.push_back(a);  //помещаем элемент в массив
	}
	read.close();
}

void editFile(std::string& fileName) {
	std::ifstream potok(fileName);
	
	if (!potok)
	{
		std::cout << "Ошибка, файл не найден" << std::endl;
		system("pause");
	}
	std::string a;
	getline(potok,a);
	std::cout << a <<std::endl;
	potok.close();
	std::ofstream potok1(fileName);

	COORD coord;
	std::string Input;
	getline(potok, a);
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi); //записываем информацию о буфере экрана в консоли в bi
	coord.X = bi.dwCursorPosition.X; //получаем координаты курсора (это будут координаты начала строки после ее вывода)
	coord.Y = bi.dwCursorPosition.Y;
	std::cout << a;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //устанавливаем курсор на ранее полученные координаты
	getline(std::cin, Input);
	potok1 << Input;

	potok1.close();
}

bool checkAr(std::vector<std::string>& data) {
	bool mark = false;
	std::vector<std::string> chAr{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "-", "*", "/", "^" };
	for (size_t i = 0; i < data.size(); i++) {
		for (size_t j = 0; j < chAr.size(); j++) {
			if (data[i] == chAr[j]) {
				mark = true;
			}
		}
		try {
			if (mark == false) throw std::string(data[i]);
		}
		catch (std::string data)
		{
			std::cout << "exception -> unknown argument:\t" << data << std::endl;
			return true;
		}
		mark = false;
	}
	return false;
}

bool checkLo(std::vector<std::string>& data) {
	bool mark = false;
	std::vector<std::string> chLo{ "0", "1", "^", "U", "+", "!" };
	for (size_t i = 0; i < data.size(); i++) {
		for (size_t j = 0; j < chLo.size(); j++) {
			if (data[i] == chLo[j]) {
				mark = true;
			}
		}
		try {
			if (mark == false) throw std::string(data[i]);
		}
		catch (std::string data)
		{
			std::cout << "exception -> unknown argument:\t" << data << std::endl;
			return true;
		}
		mark = false;
	}
	return false;
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