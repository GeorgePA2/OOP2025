#include "Number.h";
#include <iostream>

using namespace std;

int main() {
	Number e("255", 10);
	e.SwitchBase(16);
	Number f("10101", 2);
	Number baza10("15", 10);
	Number n1("14", 10);
	Number n3("15", 10);
	Number n4("20", 10);
	Number n2 = n1 + n3 - n4;
	n2.Print();
	f = 14;
	Number n5 = 13;
	f.Print();
	if (f > baza10) {
		printf("fuckshitpiss \n");
	}
	if (f < baza10) {
		printf("L bozo \n");
	}
	baza10.SwitchBase(2);
	baza10.Print();
	Number e1("16", 10);
	e1 += n1;
	e1.Print();
	e.Print();
	f.Print();
	f.SwitchBase(16);
	f.Print();
	e.SwitchBase(16);
	e.Print();
	baza10.SwitchBase(30);
	baza10.Print();
	n2.Print();
	return 0;
}