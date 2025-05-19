#include "Header.h"

std::map<std::string, int> ar_operations
{
	{"+", 1}, {"-", 2}, {"*", 3}, {"/", 4}, {"^", 5}
};

std::map<std::string, int> log_operations
{
	{"^", 1}, {"U", 2}, {"!", 3}, {"+", 4}
};

ar::ar() {
	frst = scnd = 0;
}

ar::ar(int f, int s) {
	frst = f;
	scnd = s;
}

ar::~ar() {

}

int ar::sloz() {   //...+...
	ans = frst + scnd;
	return ans;
}

int ar::vych() {   //...-...
	ans = frst - scnd;
	return ans;
}

int ar::umno() {   //...*...
	ans = frst * scnd;
	return ans;
}

int ar::dele() {   //.../...
	ans = frst / scnd;
	return ans;
}

int ar::step() {   //...^...
	for (int i = 0; i < scnd; i++) {
		ans = ans * frst;
	}
	return ans;
}


//......................methods...logic_operations...


lo::lo() {
	frst = scnd = 0;
}

lo::lo(int f, int s) {
	frst = f;
	scnd = s;
}

lo::~lo() {

}

int lo::konu() {   //...^...
	ans = frst * scnd;
	return ans;
}

int lo::disu() {   //...U...
	ans = frst + scnd - (frst + scnd);
	return ans;
}

int lo::ksor() {   //...(+)...
	ans = frst + scnd - 2 * frst * scnd;
	return ans;
}

int lo::inve() {   //...inv...
	ans = 1 - frst;
	return ans;
}


//........................................functions...


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