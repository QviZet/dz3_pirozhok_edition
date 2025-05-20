#include "Header.h"

int main(int argc, const char* argv[]) {
	std::string mod = std::string(argv[1]);
	std::string fileName = argv[2];
	std::vector<std::string> reestr;

	fillReestr(reestr, fileName);
	
	bool flag = false;//флаг для перехода на новую итерацию цикла после выполнения любой операции

	try
	{
		if (mod == "ar")
		{
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
		else if (mod == "log")
		{
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
		else
		{
			throw "unknown mode";
		}

	}
	catch (...)
	{
		std::cout << "except:" << std::endl;
	}
	std::cout << reestr[0];

	return 0;
}