#include "Math.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>

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
	int sizeresult = size1 + size2;
	/*int sizeresult;*/
	//if (size1 > size2) {
	//	sizeresult = size1 + 1;
	//}
	//else {
	//	sizeresult = size2 + 1;
	//}
	//char* c = new char[sizeresult + 1];
	//int i = size1 - 1;
	//int j = size2 - 1;
	//int k = sizeresult - 1;
	//while (i >= 0) {
	//	while (j >= 0) {
	//		
	//	}
	//}

}