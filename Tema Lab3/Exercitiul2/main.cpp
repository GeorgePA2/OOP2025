#include "Canvas.h"
#include <iostream>

using namespace std;

int main() {
	Canvas c(30, 30);
	c.SetPoint(0, 0, '[');
	c.SetPoint(0, 1, ']');
	c.SetPoint(1, 0, 'e');
	c.SetPoint(1, 12, 'e');
	c.SetPoint(10, 13, 'e');
	c.DrawRect(3, 6, 10, 10, '0');
	c.FillRect(3, 2, 10, 5, '4');
	c.FillCircle(15, 15, 6, '4');
	c.FillCircle(15, 15, 4, ' ');
	c.DrawLine(0, 20, 20, 26, '-');
	c.Print();
	c.Clear();
	printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
	//c.FillCircle(5, 5, 4, '3');
	c.DrawCircle(5, 5, 4, '1');
	c.SetPoint(4, 3, '0');
	c.SetPoint(4, 7, '0');
	c.DrawRect(0, 10, 10, 15, '1');
	c.Print();

	return 0;
}