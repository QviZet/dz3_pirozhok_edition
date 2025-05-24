#include "Header.h"

int main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "ru");
	std::string mod = std::string(argv[1]);
	std::string fileName = argv[2];
	std::vector<std::string> reestr;

	fillReestr(reestr, fileName);

	bool flag = false;//флаг для перехода на новую итерацию цикла после выполнения любой операции

	if (mod == "ar") //блок для работы с арифметическим выражением
	{
		if (checkAr(reestr)) return 0;

		while (reestr.size() >= 3) {
			for (size_t i = 2; i < reestr.size(); i++) {

				flag = false;//обновляем флаг

				if (reestr[i] == "+" || reestr[i] == "-" || reestr[i] == "*" || reestr[i] == "/" || reestr[i] == "^") {
					solverAr(reestr, flag, i);
				}
				if (flag == true) break;//если сработал флаг то переходим на новую итерацию не доходя до конца массива
			}
		}
	}
	else if (mod == "log") //блок для работы с логическим выражением
	{
		if (checkLo(reestr)) return 0;

		while (reestr.size() >= 2) {
			for (size_t i = 1; i < reestr.size(); i++) {

				flag = false;

				if (reestr[i] == "^" || reestr[i] == "U" || reestr[i] == "+" || reestr[i] == "!") {
					solverLo(reestr, flag, i);
				}
				if (flag == true) break;
			}
		}
	}
	else if (mod == "edit") //блок для редактирования файла
	{
		editFile(fileName);
		return 0;
	}
	try { //исключение для режима работы
		if (mod != "edit" && mod != "log" && mod != "ar") throw std::string(mod);
	}
	catch (std::string data)
	{
		std::cout << "exception -> unknown mode:\t" << data << std::endl;
		exit(0);
	}

	std::cout << reestr[0];
	return 0;
}