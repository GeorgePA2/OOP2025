#include "Sort.h";
#include <iostream>

using namespace std;

int main() {
	Sort v(10, 50, 5);
	int vect[] = { 1, 4, 5, 6, 0 };
	Sort a(5, vect);
	printf("Elementele din v sunt: ");
	v.Print();
	printf("Elementele din a sunt: ");
	a.Print();
	v.InsertSort(true);
	printf("Elementele din v sortate prin InsertSort sunt: ");
	v.Print();
	a.InsertSort(false);
	printf("Elementele din a sortate prin InsertSort sunt: ");
	a.Print();


	return 0;
}