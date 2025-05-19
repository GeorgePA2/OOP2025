#include <iostream>
#include <stdio.h>
#include <exception>
#include "Arrays.h"

int compare_ints(int x, int y) {
	return x - y;
}

using namespace std;

	int main() {
		Array<int> newvector(10);
		newvector + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11;
		newvector + 12;
		newvector - 1 - 2 - 3;
		newvector * 9 * 10;
		newvector / 0;
		newvector / 10 / 3;
		newvector[4] = 4;
		printf("Elemente initiale sunt: \n");
		for (auto val : newvector) {
			cout << val << " ";
		}
		printf("\nElemente au fost ordonate descrescator astfel: \n");
		newvector.sort(compare_ints);
		newvector.print();
		printf("Elemente au fost ordonate crescator astfel: \n");
		newvector.sort();
		newvector.print();
		return 0;
	}