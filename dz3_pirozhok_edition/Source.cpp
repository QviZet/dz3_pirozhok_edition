#include "Header.h"

int main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "ru");
	std::string mod = std::string(argv[1]);
	std::string fileName = argv[2];
	std::vector<std::string> reestr;

	fillReestr(reestr, fileName);
	
	bool flag = false;//флаг для перехода на новую итерацию цикла после выполнения любой операции

	if (mod == "ar")
	{
		if (checkAr(reestr)) return 0;
		
		while (reestr.size() >= 3) {
			size_t checkSize = reestr.size(); //переменная для выхода из цикла в случае если встретятся лишние символы
			for (size_t i = 2; i < reestr.size(); i++) {

				flag = false;//обновляем флаг

				if (reestr[i] == "+" || reestr[i] == "-" || reestr[i] == "*" || reestr[i] == "/" || reestr[i] == "^") {
					solverAr(reestr, flag, i);
				}
				if (flag == true) break;//если сработал флаг то переходим на новую итерацию не доходя до конца массива
			}
			if (checkSize == reestr.size()) break; //если встретились лишние символы то за итерацию размер массива не поменялся и происходит выход из цикла
		}
	}
	else if (mod == "log")
	{
		if (checkLo(reestr)) return 0;

		while (reestr.size() >= 2) {
			size_t checkSize = reestr.size();
			for (size_t i = 1; i < reestr.size(); i++) {

				flag = false;

				if (reestr[i] == "^" || reestr[i] == "U" || reestr[i] == "+" || reestr[i] == "!") {
					solverLo(reestr, flag, i);
				}
				if (flag == true) break;
			}
			if (checkSize == reestr.size()) break;
		}
	}
	else if (mod == "edit")
	{
		editFile(fileName);
		return 0;
	}
	try{
		if (mod!="edit" && mod != "log" && mod != "ar") throw std::string(mod);
	}
	catch (std::string data)
	{
		std::cout << "exception -> unknown mode:\t" << data << std::endl;
		exit(0); 
	}

	try {
		if (reestr.size() > 1) throw std::vector<std::string>(reestr);
	}
	catch (std::vector<std::string> data)
	{
		std::cout << "exception -> extra elements:\t";
		for (size_t i = 1; i < reestr.size(); i++){
			std::cout << reestr[i]<<"\t";
		}
		exit(0);
	}

	std::cout << reestr[0];
	return 0;
}