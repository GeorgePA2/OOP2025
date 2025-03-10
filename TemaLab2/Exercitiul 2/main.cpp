#include "Studentie.h"
#include "global.h"
#include <iostream>;

using namespace std;

int main() {
	Studentie p, q;
	const char* Vasile = "Vasile";
	const char* Gheorghe = "Gheorghe";
	q.SetNume(Vasile);
	q.SetEng(10);
	q.SetHist(4.5);
	q.SetMath(5.6);
	p.SetNume(Gheorghe);
	printf("Numele studentului este: %s \n", p.getNume());
	p.SetEng(7.5);
	printf("Nota studentului la engleza este: %F \n", p.GetNotaEng());
	p.SetHist(8.9);
	printf("Nota studentului la istorie este: %F \n", p.GetNotaHist());
	p.SetMath(6.5);
	printf("Nota studentului la matematica este: %f \n", p.getNotaMath());
	printf("Media studentului este : % f \n", p.AVG());

	printf("Compara nume: %d \n", comparaStudenti(p, q));
	printf("Compara mate: %d \n", comparaMath(p, q));
	printf("Compara istorie: %d, \n", comparaHist(p, q));
	printf("Compara engleza: %d \n", comparaEng(p, q));
	printf("Compara medie: %d \n", comparaAVG(p, q));

	return 0;
}