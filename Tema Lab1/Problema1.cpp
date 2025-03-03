#include <iostream>
#include <cstring>
using namespace std;
void covertstringtoint(const char * s, int&converts) {
	converts = 0;
	int n = strlen(s)-1;
	for (int i = 0; i < n; i++) {
		//printf("numarul actual este %c \n", s[i]);
		if (s[i] < '0' || s[i] > '9') {
			converts = 0;
			return;
		}
		converts = converts * 10 + (s[i] - '0');
	}
}
int main() 
{
	FILE* fila;
	fopen_s(&fila, "in.txt", "r");
	int numaractual, suma = 0;
	if (fila == NULL) {
		printf("EROARE! FISIERUL NU EXISTA!");
		return 1;
	}
	else {
		char numar[256];
		while (fgets(numar, 200, fila)) {
			numaractual = 0;
			covertstringtoint(numar, numaractual);
			suma = suma + numaractual;
		}
	}
	printf("Suma este: %d \n", suma);
	return 0;
}
