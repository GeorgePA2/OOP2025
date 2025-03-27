#pragma once
class Number
{
	int numar, digits, base;
	char* number;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();

	// add operators and copy/move constructor
	Number(const Number& d); //copy constructor
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	bool operator>(const Number& n);
	bool operator>=(const Number& n);
	bool operator<(const Number& n);
	bool operator<=(const Number& n);
	bool operator==(const Number& n);
	bool operator!=(const Number& n);
	Number& operator=(int num);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
