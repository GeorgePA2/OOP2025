#include "Sort.h"
#include <stdlib.h>
#include <iostream>

Sort::Sort(int minimum, int maximum, int nr_elemente) : minimum(minimum), maximum(maximum), nr_elemente(nr_elemente) {
	this->vector = new int[nr_elemente];
	for (int i = 0; i < nr_elemente; i++) {
		this->vector[i] = minimum + rand() % (maximum - minimum);
	}
}
Sort::Sort(int nr, int array[]) {
	this->nr_elemente = nr;
	this->vector = new int[nr_elemente];
	for (int i = 0; i < nr_elemente; i++) {
		this->vector[i] = array[i];
	}
}
Sort::~Sort() {
	printf("Constructorul gigel \n");
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
