#include "Sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <iostream>

Sort::Sort(int minimum, int maximum, int nr_elemente) : nr_elemente(nr_elemente) {
	this->vector = new int[nr_elemente];
	srand(time(0));
	for (int i = 0; i < nr_elemente; i++) {
		this->vector[i] = minimum + rand() % (maximum - minimum);
	}
}
Sort::Sort(): vector(new int[4] { 24, 12, 45, 5 }) {
	this->nr_elemente = 4;
}
Sort::Sort(int nr, int array[]) : nr_elemente(nr) {
	this->vector = new int[nr_elemente];
	for (int i = 0; i < nr_elemente; i++) {
		this->vector[i] = array[i];
	}
}
Sort::Sort(int nr, ...): nr_elemente(nr) {
	this->vector = new int[nr_elemente+1];
		va_list numbers;
		va_start(numbers, nr);
		for (int i = 0; i < nr; i++) {
			vector[i] = va_arg(numbers, int);
		}
		va_end(numbers);

	}
Sort::Sort(const char* sir) {
	int i = 0, nr = 0, numar;
	if (sir != nullptr) {
		while (sir[i] != '\0') {
			if (sir[i] == ',') {
				nr++;
			}
			i++;
		}
		nr++;
		this->nr_elemente = nr;
		this->vector = new int[nr];
		i = 0;
		int j = 0;
		while (sir[i] != NULL) {
			numar = 0;
			while ((sir[i] != ',') && (sir[i] != '\0')) {
				numar = numar * 10 + sir[i] - '0';
				i++;
			}
			this->vector[j] = numar;
			j++;
			i++;
		}
	}

}
Sort::~Sort() {
	delete[] vector;
}

void Sort::InsertSort(bool ascendent) {
		for (int i = 1; i < this->nr_elemente; ++i) {
			int key = vector[i];
			int j = i - 1;
			while (j >= 0 && vector[j] > key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
			vector[j + 1] = key;
		}
		if (ascendent == false) {
			for (int i = 0; i < this->nr_elemente / 2; i++) {
				int t = vector[i];
				vector[i] = vector[nr_elemente - i-1];
				vector[nr_elemente - i-1] = t;
			}
		}
}
void Sort::QuickSort(bool ascendent) {

}
void Sort::BubbleSort(bool ascendent) {
	bool swapped;

	for (int i = 0; i < this->nr_elemente - 1; i++) {
		swapped = false;
		for (int j = 0; j < this->nr_elemente - i - 1; j++) {
			if (vector[j] > vector[j + 1]) {
				int t = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = t;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
	if (ascendent == false) {
		for (int i = 0; i < this->nr_elemente / 2; i++) {
			int t = vector[i];
			vector[i] = vector[nr_elemente - i - 1];
			vector[nr_elemente - i - 1] = t;
		}
	}
}
int Sort::GetElementsCount() {
	return this->nr_elemente;
}
int Sort::GetElementFromIndex(int index) {
	return this->vector[index];
}
void Sort::Print() {
	for (int i = 0; i < GetElementsCount(); i++) {
		printf(" %d", GetElementFromIndex(i));
	}
	printf("\n");
}
