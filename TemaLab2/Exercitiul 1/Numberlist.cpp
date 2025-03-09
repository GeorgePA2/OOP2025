#include "Numberlist.h"
#include <iostream>
using namespace std;

void Numberlist::Init() {
	this->count = 0;
}
bool Numberlist::Add(int x) {
	if (this->count >= 10) {
		return false;
	}
	this->numbers[count] = x;
	this->count += 1;
	return true;
}

void Numberlist::Sort() {
	for (int i = 0; i < this->count; i++) {
		for (int j = i + 1; j < this->count; j++) {
			if (this->numbers[i] > this->numbers[j]) {
				int c = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = c;
			}
		}
	}
}
void Numberlist::Print() {
	printf("vectorul curent este: ");
	for (int i = 0; i < this->count; i++) {
		printf("%d ", this->numbers[i]);
	}
}