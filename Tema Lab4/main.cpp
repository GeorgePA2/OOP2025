#include "Sort.h";
#include <iostream>

using namespace std;

int main() {
	Sort random(10, 50, 5);
	Sort list;
	int vect[5] = { 1, 4, 5, 6, 0 };
	Sort a(5, vect);
	Sort va(7, 34, 23, 15, 17, 1, 56, 100);
	Sort s("14,16,7,17,23");
	printf("Elementele din random sunt: ");
	random.Print();
	printf("Elementele din a sunt: ");
	a.Print();
	printf("Elementele declarate variadic sunt ");
	va.Print();
	printf("Elementele din vectorul creat printr-o lista de initializare este ");
	list.Print();
	random.InsertSort(true);
	printf("Elementele din random sortate prin InsertSort sunt: ");
	random.Print();
	s.Print();
	s.QuickSort();
	printf("Elementele din s sortate descrescator prin QuickSort sunt: ");
	s.Print();
	a.BubbleSort(false);
	printf("Elementele din a sortate prin BubbleSort descrescator sunt: ");
	a.Print();


	return 0;
}