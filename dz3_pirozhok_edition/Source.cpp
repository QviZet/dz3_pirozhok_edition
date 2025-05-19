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

				if (reestr[i] == "+") {
					reestr[i - 2] = std::to_string(newAr.sloz()); //заменяем элемент [i - 2] на ans
					reestr.erase(reestr.cbegin() + i); //удаляем элемент [i]
					reestr.erase(reestr.cbegin() + i - 1);//удаляем элемент [i - 1]
					flag = true;
				}
				else if (reestr[i] == "-") {
					reestr[i - 2] = std::to_string(newAr.vych());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				else if (reestr[i] == "*") {
					reestr[i - 2] = std::to_string(newAr.umno());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				else if (reestr[i] == "/") {
					reestr[i - 2] = std::to_string(newAr.dele());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				else if (reestr[i] == "^") {
					reestr[i - 2] = std::to_string(newAr.step());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				std::cout << "\n";
				for (size_t i = 0; i < reestr.size(); i++) {
					std::cout << reestr[i] << " ";
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

				lo newAr(stoi(reestr[i - 2]), stoi(reestr[i - 1])); //создаём объект класса lo(булевая операция)

				if (reestr[i] == "^") {
					reestr[i - 2] = std::to_string(newAr.konu());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				else if (reestr[i] == "U") {
					reestr[i - 2] = std::to_string(newAr.disu());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				else if (reestr[i] == "+") {
					reestr[i - 2] = std::to_string(newAr.ksor());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}
				else if (reestr[i] == "!") {
					reestr[i - 2] = std::to_string(newAr.disu());
					reestr.erase(reestr.cbegin() + i);
					reestr.erase(reestr.cbegin() + i - 1);
					flag = true;
				}

				std::cout << "\n";
				for (size_t i = 0; i < reestr.size(); i++) {
					std::cout << reestr[i] << " ";
				}
				std::cout << "\n";
				if (flag == true) break;
			}
		}
	}
	std::cout << "\n";
	reestr.erase(reestr.cbegin() + 1);
	for (size_t i = 0; i < reestr.size(); i++) {
		std::cout << reestr[i] << " ";
	}

	return 0;
}