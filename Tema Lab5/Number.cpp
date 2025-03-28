#include "Number.h"
#include <iostream>

Number::Number(const char* value, int base) {
	this->numar = 0;
	this->base = base;
	if ((base < 2) || (base > 16)) {
		printf("EROARE! BAZA TREBUIE SA FIE UN NR CUPRINS INTRE 2 SI 16!!! /n");
	}
	else {
		int i = 0;
		while (value[i] != '\0') {
			//printf("value[i] este: %c \n", value[i]);
			if (value[i] <= '9') {
				this->numar = this->numar * base + (value[i] - '0');
				int r = value[i] - '0';
				//printf("progress per cifra: %c \n", r);
			}
			else {
				this->numar = this->numar * base + (value[i] - 'A' + 10);

				//printf("progress per cifra: %d \n", this->numar);
			}
			i++;
		}
		this->digits = i;
		this->number = new char[this->digits+1];
		//printf("wtf: %c \n", this->number);
		int j = 0;
		while (j < this->digits) {
			this->number[j] = value[j];
			j++;
			//printf("progress: %d \n", this->number[j]);
		}
		this->number[j] = '\0';

	}
}
Number::Number(const int& num) {
	this->numar = num;
	this->base = 10;
	SwitchBase(10);
}
Number::Number() : numar(0), base(10){}
Number::Number(const Number& d) {
	this->numar = d.numar;
	this->base = d.base;
	this->digits = d.digits;
	this->number = new char[this->digits + 1];
	memcpy(this->number, d.number, this->digits+1);
}
Number& Number::operator=(int num) {
	this->numar = num;
	SwitchBase(this->base);
	return (*this);
}
Number& Number::operator+=(Number n) {
	this->numar += n.numar;
	int based = this->base;
	if (based < n.base) {
		based = n.base;
	}
	SwitchBase(based);
	return (*this);
}
Number& Number::operator-=(Number n) {
	this->numar -= n.numar;
	int based = this->base;
	if (based < n.base) {
		based = n.base;
	}
	SwitchBase(based);
	return (*this);
}
Number& Number::operator*=(Number n) {
	this->numar *= n.numar;
	int based = this->base;
	if (based < n.base) {
		based = n.base;
	}
	SwitchBase(based);
	return (*this);
}
Number& Number::operator/=(Number n) {
	this->numar *= n.numar;
	int based = this->base;
	if (based < n.base) {
		based = n.base;
	}
	SwitchBase(based);
	return (*this);
}
Number operator+(const Number& n1, const Number& n2) {
	int newbase = n1.base;
	 if (n1.base < n2.base) {
		 newbase = n2.base;
	}
	 int value = n1.numar + n2.numar;
	 //int value1 = value;
	 //int i = 0;
	 //while (value1 > 0) {
		// i++;
		// value1 /= newbase;
	 //}
	 //char* temp = new char[i + 1];
	 //int j = 0;
	 //while (j < i) {
		// /*printf("restul impartirii este : %d \n", numero2 % 10);*/
		// if (value % newbase < 10) {
		//	 temp[j] = value % newbase + '0';
		// }
		// else {
		//	 temp[j] = value % newbase % 10 + 'A';
		// }
		// value /= newbase;
		// j++;
	 //}
	 //temp[i] = '\0';
	 //for (j = 0; j < i / 2; j++) {
		// char t = temp[j];
		// temp[j] = temp[i - j - 1];
		// temp[i - j - 1] = t;
	 //}

	 Number result;
	 result = value;
	 result.SwitchBase(newbase);

/*	 delete[] temp;
	 temp = NULL*/;

	 return result;

}
bool Number::operator>(const Number& n) {
	if (this->numar > n.numar) {
		return true;
	}
	return false;
}

bool Number::operator<(const Number& n) {
	if (this->numar < n.numar) {
		return true;
	}
	return false;
}

bool Number::operator==(const Number& n) {
	if (this->numar == n.numar) {
		return true;
	}
	return false;
}

bool Number::operator!=(const Number& n) {
	if (this->numar != n.numar) {
		return true;
	}
	return false;
}

bool Number::operator<=(const Number& n) {
	if (this->numar <= n.numar) {
		return true;
	}
	return false;
}

bool Number::operator>=(const Number& n) {
	if (this->numar >= n.numar) {
		return true;
	}
	return false;
}
Number operator-(const Number& n1, const Number& n2) {
	int newbase = n1.base;
	if (n1.base < n2.base) {
		newbase = n2.base;
	}
	int value = n1.numar - n2.numar;

	Number result;
	result = value;
	result.SwitchBase(newbase);

	return result;

}
void Number::SwitchBase(int newBase) {
	if (newBase < 2 || newBase > 16) {
		printf("EROARE! BAZA INTRODUSA TREBUIE SA FIE CUPRINSA INTRE 2 SI 16!!!! \n");
			return;
	}
	else{
		if (number != NULL) {
			delete[] number;
			number = NULL;
		}
		this->base = newBase;
		int numero2 = this->numar;
		int i = 0;
		while (numero2 > 0) {
			numero2 /= newBase;
			i++;
		}
		this->digits = i;
		this->number = new char[this->digits + 1];
		char* temp = new char[this->digits + 1];
		numero2 = this->numar;
		int j = 0;
		while (j < this->digits) {
			/*printf("restul impartirii este : %d \n", numero2 % 10);*/
			if (numero2 % newBase < 10) {
				temp[j] = numero2 % newBase + '0';
			}
			else {
				temp[j] = numero2 % newBase % 10 + 'A';
			}
			numero2 /= newBase;
			j++;
		}
		temp[i] = '\0';
		i--;
		j = 0;
		while (i >= 0) {
			this->number[j] = temp[i];
			j++;
			i--;
		}
		this->number[this->digits] = '\0';
	}
}


Number::~Number() {
	if (number != nullptr) {
		delete[] number;
		number = nullptr;
	}
	/*printf("destructorul gigel /n");*/
}
void Number::Print() {
	printf("Numarul este: %s \n", this->number);
}
int Number::GetDigitsCount() {
	return this->digits;
}
int Number::GetBase() {
	return this->base;
}
