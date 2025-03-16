#include <iostream>
#include "Math.h";

using namespace std;

int main() {
	Math m;
	printf("2+3=%d \n", m.Add(2, 3));
	printf("2+3+4=%d \n", m.Add(2, 3, 4));
	printf("8.4+4.5=%d \n", m.Add(8.5, 4.5));
	printf("8.4+4.5+1.0=%d \n", m.Add(8.5, 4.5, 1.0));
	printf("2*8=%d \n", m.Mul(2, 8));
	printf("2*8*4=%d \n", m.Mul(2, 8, 4));
	printf("2.5*8.4=%d \n", m.Mul(2.5, 8.4));
	printf("2.5*8.4*4.3=%d \n", m.Mul(2.5, 8.4, 4.3));
	printf("Suma numerelor 1, 2, 3, 4, 5 este %d \n", m.Add(5, 1, 2, 3, 4, 5));
	printf("2023 + 2024 = %c \n", m.Add("2023", "2024"));
	return 0;
}