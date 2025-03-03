//#define _CRT_SECURE_NO_WARNINGS  ///strict pentru a utiliza strcpy(), strcpy_s imi cauzeaza erori pe care nu o pot rezolva
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int nrcuvinte;
	printf("Insereaza numarul de cuvinte pe care propozitia ta o are:");
	scanf_s("%d", &nrcuvinte);
	char cuvinte[100][20];
	char propozitie[512];
	printf("Tasteaza propozitia: ");
	int i, j;
	for (i = 0; i < nrcuvinte; i++) {
		scanf_s("%s", propozitie, sizeof(propozitie));
		strcpy_s(cuvinte[i], sizeof(cuvinte[i]), propozitie);
	}
	i = 0;
	for (i = 0; i < nrcuvinte; i++) {
		for (j = i+1; j < nrcuvinte; j++) {
			if (strlen(cuvinte[i]) < strlen(cuvinte[j])) {
				swap(cuvinte[i], cuvinte[j]);
			}
		}

	}
	for (i = 0; i < nrcuvinte; i++) {
		printf("%s \n", cuvinte[i]);
	}


	return 0;
}
