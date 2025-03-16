#include "Canvas.h"
#include <iostream>

using namespace std;

int main() {
	Canvas c(20, 20);
	c.SetPoint(0, 0, '[');
	c.SetPoint(0, 1, ']');
	c.SetPoint(1, 0, 'e');
	c.SetPoint(1, 12, 'e');
	c.SetPoint(10, 19, 'e');
	c.DrawRect(3, 2, 10, 5, '0');
	c.FillRect(3, 2, 10, 5, '4');
	c.Print();
	c.Clear();
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
	c.DrawLine(0, 1, 6, 4, 'k');
	c.DrawLine(4, 3, 5, 10, 'r');
	c.Print();

	return 0;
}