#pragma once
#include <iostream>
using namespace std;
template<class T>
int compare_ints(T x, T y) {
	return x - y;
}
template <class T>
class Vector {
private:
	T* vector;
	int size=0;
public:
	Vector() {
		size = 25;
		vector = new T[size];
		for (int i = 0; i < size; i++) {
			vector[i] = i;
		}
	}
	Vector(int size1) {
		size = size1;
		vector = new T[size];
		for (int i = 0; i < size; i++) {
			vector[i] = i;
		}
	}
	Vector(const Vector& copyvector) {
		if (this->size != 0) {
			delete[] this->vector;
			}
		this->size = copyvector.size;
		this->vector = new T[size];
		for (int i = 0; i < this->size; i++) {
			this->vector[i] = copyvector.vector[i];
		}
	}
	void sort(int(*cmp)(T, T)) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (cmp(vector[i], vector[j]) > 0) {
					T temp = vector[i];
					vector[i] = vector[j];
					vector[j] = temp;
				}
			}
		}
	}
	void sort() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (vector[i] < vector[j]) {
					T temp = vector[i];
					vector[i] = vector[j];
					vector[j] = temp;
				}
			}
		}
	}
	void insert(int index, T element) {
		if ((index >= 0) && (index < size)) {
			//cout << "elementu este " << element << endl;
			//printf("T size este %d \n", sizeof(T));
			vector[index] = element;
		}
	}
	void remove(int index) {
		size--;
		for (int i = index; i < size; i++) {
			vector[i] = vector[i + 1];
		}
	}

	T operator[](int index) {
		if ((index > size))  {
			return 0;
		}
		return vector[index];
	}
	void print() {
		//printf("sizeof(T) este %d \n", sizeof(T));
		printf("Elementele vectorului sunt:");
		for (int i = 0; i < size; i++){
			cout << vector[i] << " ";
			}
		printf("\n");
	}
	~Vector() {
		delete[] vector;
	}


};
