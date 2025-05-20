#include "Header.h"

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
int sloz(ar& newAr) {
	int ans = newAr.step();
	return ans;
}

int ar::vych() {   //...-...
	ans = frst - scnd;
	return ans;
}
int vych(ar& newAr) {
	int ans = newAr.step();
	return ans;
}

int ar::umno() {   //...*...
	ans = frst * scnd;
	return ans;
}
int umno(ar& newAr) {
	int ans = newAr.step();
	return ans;
}

int ar::dele() {   //.../...
	ans = frst / scnd;
	return ans;
}
int dele(ar& newAr) {
	int ans = newAr.step();
	return ans;
}

int ar::step() {   //...^...
	for (int i = 0; i < scnd; i++) {
		ans = ans * frst;
	}
	return ans;
}
int step(ar& newAr) {
	int ans = newAr.step();
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