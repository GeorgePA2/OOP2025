#include <iostream>
#include <stdio.h>
#include <exception>
using namespace std;

template<class T>
int compare_ints(T x, T y) {
	return x - y;
}

class div0 : public exception
{
	virtual const char* what() const throw()
	{
		return "Impartirea la 0 este imposibila!!";
	}
}div_zero;

class exceptie_spatiu_alocat : public exception
{
	virtual const char* what() const throw()
	{
		return "Insuficient spatiu alocat pentru realizarea aceste operatii!";
	}
}ex_sp;

class no_element_found : public exception
{
	virtual const char* what() const throw()
	{
		return "Nu exista elementul cautat!";
	}
}ex_NA;

class iesire_nafara : public exception
{
	virtual const char* what() const throw()
	{
		return "Operatia nu se poate realiza deoarece depasim spatiul permis!";
	}
}ex_iesire;

template<class T>
class Array {
private:
	int spatiu_alocat;
	T* vector;
	int current_size = 0;
public:
	Array() {
		spatiu_alocat = 0;
		vector = new T[1];
		vector[0] = 0;
	}
	Array(int dimensiune) {
		spatiu_alocat = dimensiune;
		vector = new T[dimensiune + 1];
	}
	~Array() {
		delete[] vector;
	}

	Array(const Array& Copy_Array) {
		try {
			if (Copy_Array.spatiu_alocat != this->spatiu_alocat) {
				throw ex_sp;
			}
			this->current_size = Copy_Array.current_size;
			for (int i = 0; i < Copy_Array.current_size; i++) {
				this->vector[i] = Copy_Array.vector[i];
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}

	Array(Array&& Move_Array) {
		this->vector = Move_Array.vector;
		this->spatiu_alocat = Move_Array.spatiu_alocat;
		this->current_size = Move_Array.current_size;

		Move_Array.vector = nullptr;
		Move_Array.spatiu_alocat = 0;
		Move_Array.current_size = 0;
	}

	Array& operator+(T element) {
		try {
			if (current_size == spatiu_alocat) {
				throw ex_sp;
			}
			vector[current_size] = element;
			current_size++;
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		return *this;
	}

	Array& operator-(T element) {
		try {
			if (current_size == 0) {
				throw ex_iesire;
			}
			for (int i = 0; i < current_size; i++) {
				if (vector[i] == element) {
					for (int j = i; j < current_size - 1; j++) {
						vector[j] = vector[j + 1];
					}
					current_size--;
				}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		return *this;
	}

	Array& operator*(T element) {
		for (int i = 0; i < current_size; i++) {
			vector[i] *= element;
		}
		return *this;
	}

	T& operator[](int index) {
		try {
			if ((index < 0) || (index > current_size)) {
				throw ex_iesire;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		return vector[index];
	}

	bool find(int element) {
		for (int i = 0; i < current_size; i++) {
			if (vector[i] == element) {
				return true;
			}
		}
		return false;
	}

	Array& operator/(T element) {
		try {
			if (element == 0) {
				throw div_zero;
			}
			for (int i = 0; i < current_size; i++) {
				vector[i] /= element;
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		return *this;
	}


	void print() {
		for (int i = 0; i < current_size; i++) {
			cout << vector[i] << " ";
		}
		printf("\n");
	}

	void sort(int(*cmp)(T, T)) {
		for (int i = 0; i < current_size; i++) {
			for (int j = 0; j < current_size; j++) {
				//printf("momentan, pe pozitia %d \n", i);
				if (cmp(vector[i], vector[j]) > 0) {
					T temp = vector[i];
					vector[i] = vector[j];
					vector[j] = temp;
				}
			}
		}
	}
	void sort() {
		for (int i = 0; i < current_size; i++) {
			for (int j = 0; j < current_size; j++) {
				if (vector[i] < vector[j]) {
					T temp = vector[i];
					vector[i] = vector[j];
					vector[j] = temp;
				}
			}
		}
	}
	int Get_Size() {
		return spatiu_alocat;
	}
	int Get_Current_Size() {
		return current_size;
	}
	//iterator
	class Array_Iterator {
		T* poz;
	public:
		Array_Iterator(T* pozitie) :poz(pozitie) {};
		Array_Iterator& operator++() {
			poz++;
			return *this;
		}
		Array_Iterator& operator--() {
			poz--;
			return *this;
		}
		auto operator*() const {
			return *poz;
		}
		bool operator!=(const Array_Iterator& other) const {
			return poz != other.poz;
		}


	};

	Array_Iterator begin() {
		return Array_Iterator(vector);
	}
	Array_Iterator end() {
		return Array_Iterator(vector + current_size);
	}
};