#include "Studentie.h"
#include <iostream>;

void Studentie::SetNume(const char* numestudent) {
	int i = strlen(numestudent);
	this->nume = new char[i + 1];
	memcpy(this->nume, numestudent, i + 1);
	}
char* Studentie::getNume() {
	return this->nume;
}
void Studentie::SetMath(float math) {
	this->math = math;
}
float Studentie::getNotaMath() {
	return this->math;
}
void Studentie::SetEng(float english) {
	this->english = english;
}
float Studentie::GetNotaEng() {
	return this->english;
}
void Studentie::SetHist(float history) {
	this->history = history;
}
float Studentie::GetNotaHist() {
	return this->history;
}
float Studentie::AVG() {
	this->avg = (this->history + this->english + this->math) / 3;
	return this->avg;
}
