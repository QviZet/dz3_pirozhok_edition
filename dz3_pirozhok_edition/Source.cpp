#include "Header.h"

int main(int argc, const char* argv[]) {
	std::string mod = std::string(argv[1]);
	std::string fileName = argv[2];
	std::vector<std::string> reestr;
	fillReestr(reestr, fileName);

	bool flag = false;//флаг для перехода на новую итерацию цикла после выполнения любой операции

	if (mod == "ar") {
		while (reestr.size() >= 3) {
			for (size_t i = 2; i < reestr.size(); i++) {

				flag = false;//обновляем флаг

				ar newAr(stoi(reestr[i - 2]), stoi(reestr[i - 1])); //создаём объект класса ar(арифметическая операция)

				if (reestr[i] == "+" || reestr[i] == "-" || reestr[i] == "*" || reestr[i] == "/" || reestr[i] == "^") {
					solverAr(reestr, newAr, reestr[i], flag);
				}
				std::cout << "\n";
				if (flag == true) break;//если сработал флаг то переходим на новую итерацию не доходя до конца массива
			}
		}
	}
	else {
		while (reestr.size() >= 3) {
			for (size_t i = 2; i < reestr.size(); i++) {

				flag = false;

				lo newLo(stoi(reestr[i - 2]), stoi(reestr[i - 1])); //создаём объект класса lo(булевая операция)

				if (reestr[i] == "^" || reestr[i] == "U" || reestr[i] == "+" || reestr[i] == "!") {
					solverLo(reestr, newLo, reestr[i], flag);
				}
				std::cout << "\n";
				if (flag == true) break;
			}
		}

		if (reestr.size() == 2) { //обрабатываем ситуацию инверсии последним действием
			reestr[0] = std::to_string(1 - stoi(reestr[0]));
			reestr.erase(reestr.cbegin() + 1);
		}
	}
	std::cout << "\n";
	reestr.erase(reestr.cbegin() + 1);
	for (size_t i = 0; i < reestr.size(); i++) {
		std::cout << reestr[i] << " ";
	}

	return 0;
}