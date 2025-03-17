#include "Sort.h";
#include <iostream>

using namespace std;

int main() {
	Sort v(10, 50, 5);
	int vect[5] = { 1, 4, 5, 6, 0 };
	Sort a(5, vect);
	Sort s("14,16,7,17,23");
	printf("Elementele din v sunt: ");
	v.Print();
	printf("Elementele din a sunt: ");
	a.Print();
	v.InsertSort(true);
	printf("Elementele din v sortate prin InsertSort sunt: ");
	v.Print();
	s.InsertSort();
	printf("Elementele din s sortate descrescator prin InsertSort sunt: ");
	s.Print();
	a.BubbleSort(false);
	printf("Elementele din a sortate prin BubbleSort descrescator sunt: ");
	a.Print();


	return 0;
}