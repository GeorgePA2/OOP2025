#include "Numberlist.h";
#include <iostream>;

using namespace std;

int main() {
	Numberlist n;
	n.Init();
	n.Add(15);
	n.Add(443);
	n.Add(5);
	n.Add(65);
	n.Add(78);
	n.Sort();
	n.Print();
	//while (c >= 10) {
	//	printf("EROARE! TASTATI UN NUMAR MAI MIC DECAT 10!!! ");
	//		cin >> c;
	//}

	return 0;
}