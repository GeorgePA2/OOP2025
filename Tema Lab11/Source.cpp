//#include "pch.h"
#include <iostream>
#include "Vectorul.h"
using namespace std;

//int compare_ints(int a, int b) {
//	return a - b;
//}

int main() {
	Vector_funny<int> Gigel;
	Gigel += 4;
	Gigel += 5;
	Gigel += 1;
	Gigel += 10;
	Gigel += 9;
	Gigel.sort();
	Gigel.print();
	return 0;
}