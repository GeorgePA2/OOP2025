#include <iostream>
#include "global.h";
#include "Studentie.h"

int comparaStudenti(Studentie S1, Studentie S2) {
	if (strcmp(S1.getNume(), S2.getNume()) < 0) {
		return -1;
	}
	if (strcmp(S1.getNume(), S2.getNume()) == 0) {
		return 0;
	}
	if (strcmp(S1.getNume(), S2.getNume()) > 0) {
		return 1;
	}
}

int comparaMath(Studentie S1, Studentie S2) {
	if (S1.getNotaMath() < S2.getNotaMath()) {
		return -1;
	}
	if (S1.getNotaMath() == S2.getNotaMath()) {
		return 0;
	}
	if (S1.getNotaMath() > S2.getNotaMath()) {
		return 1;
	}
}
int comparaHist(Studentie S1, Studentie S2) {
	if (S1.GetNotaHist() < S2.GetNotaHist()) {
		return -1;
	}
	if (S1.GetNotaHist() == S2.GetNotaHist()) {
		return 0;
	}
	if (S1.GetNotaHist() > S2.GetNotaHist()) {
		return 1;
	}
}

int comparaEng(Studentie S1, Studentie S2) {
	if (S1.GetNotaEng() < S2.GetNotaEng()) {
		return -1;
	}
	if (S1.GetNotaEng() == S2.GetNotaEng()) {
		return 0;
	}
	if (S1.GetNotaEng() > S2.GetNotaEng()) {
		return 1;
	}
}

int comparaAVG(Studentie S1, Studentie S2) {
	if (S1.AVG() < S2.AVG()) {
		return -1;
	}
	if (S1.AVG() == S2.AVG()) {
		return 0;
	}
	if (S1.AVG() > S2.AVG()) {
		return 1;
	}
}