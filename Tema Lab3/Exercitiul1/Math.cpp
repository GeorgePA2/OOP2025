#include "Math.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdarg.h>

using namespace std;

int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c) {
	return a + b + c;
}
int Math::Add(double a, double b) {
	return a + b;
}
int Math::Add(double a, double b, double c) {
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return a * b;
}
int Math::Mul(double a, double b, double c) {
	return a * b * c;
}
int Math::Add(int count, ...) {
	va_list numbers;
	va_start(numbers, count);
	int suma = 0;
	for (int i = 0; i < count; i++) {
		suma += va_arg(numbers, int);
	}
	va_end(numbers);
	return suma;

	return 0;
}
char* Math::Add(const char* a, const char* b) {
	if (a == nullptr || b == nullptr) {
		return nullptr;
	}

	int size1 = strlen(a);
	int size2 = strlen(b);

	int a_nr = 0, b_nr = 0, nr_final, nr, size_fin = 0;
	for (int i = 0; i < size1; i++) {
		int cif = a[i] - '0';
		a_nr = cif + a_nr * 10;
	}
	//cout << "Numarul a_nr este: " << a_nr << endl;
	for (int j = 0; j < size2; j++) {
		int cif = b[j] - '0';
		b_nr = cif + b_nr * 10;
	}
	//cout << "Numarul b_nr este: " << b_nr << endl;
	nr_final = a_nr + b_nr;
	//cout << "Suma nr este " << nr_final << endl;
	nr = nr_final;
	while (nr > 0) {
		size_fin++;
		nr /= 10;
	}
	char* c = new char[size_fin+1];
	c[size_fin] = '\0';
	for (int i = size_fin - 1; i >= 0; i--) {
		c[i] = (nr_final % 10) + '0';
		cout << c[i] << " pe pozitia" << i << endl;
		nr_final /= 10;
	}
	cout << "c este "<< c << endl;
	return c;

	/*int size1 = strlen(a);
	int size2 = strlen(b);

	char* c = new char[size1 + size2 + 1];
	strcpy_s(c, sizeof(a), a);
	strcat_s(c, sizeof(b), b);
	return c;*/

	//use strcpy_s

	
	//int size1 = strlen(a);
	//int size2 = strlen(b);
	//int sizeresult = size1 + size2;
	//int sizeresult;
	//if (size1 > size2) {
	//	sizeresult = size1 + 1;
	//}
	//else {
	//	sizeresult = size2 + 1;
	//}
	//char* c = new char[sizeresult + 1];
	//int i = size1 - 1;
	//int j = size2 - 1;
	////if (i > j) {
	////	int t = i;
	////	i = j;
	////	j = t;
	////}
	////int k = sizeresult - 1;
	////int cif3;
	////while (j >= 0) {
	////	int cif1 = a[i] - '0';
	////	int cif2 = b[i] - '0';
	////	int ok = 0;
	////	if (cif1 + cif2 >= 10) {
	////		cif3 = 1;
	////		if (cif1 + cif2 + cif3 == 0) {

	////		}
	////	}
	////}

}