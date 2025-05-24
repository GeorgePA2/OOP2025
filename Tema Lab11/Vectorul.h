#pragma once
#include <iostream>
using namespace std;

//template<class T>
//int compare_ints(T val1, T val2) {
//	return val2 - val1;
//}

template<class T>
class Vector_funny {
private:
	struct Lista {
		T information;
		Lista* next;
	}*head;

	Lista* current_pos = nullptr;
public:
	Vector_funny() {
		head = nullptr;
		current_pos = head;
	}
	~Vector_funny() {
		while (head != nullptr) {
			head = head->next;
		}
	}
	Vector_funny& operator+=(T element) {
		Lista* temp = new Lista;
		temp->information = element;
		temp->next = nullptr;
		if (current_pos == nullptr) {
			head = temp;
			current_pos = head;
		}
		else {
			current_pos->next = temp;
			current_pos = current_pos->next;
		}
		return *this;
	}

	//void sort(int(*cmp)(T, T)) {
	//	Lista* temp = new Lista;
	//	temp = head;
	//	while (temp != nullptr) {
	//		Lista* temp2 = new Lista;
	//		temp2 = head;
	//		while (temp2!= nullptr) {
	//			if (cmp(temp2->information, temp->information)) {
	//				cout << temp2->information << "se interschimba cu " << temp->information << endl;
	//				T temporary = temp->information;
	//				temp->information = temp2->information;
	//				temp2->information = temporary;
	//			}
	//			temp2 = temp2->next;
	//		}
	//		temp = temp->next;
	//	}

	//}

	void sort() {
		Lista* temp = new Lista;
		temp = head;
		while (temp != nullptr) {
			Lista* temp2 = new Lista;
			temp2 = head->next;
			while (temp2 != nullptr) {
				if (temp2->information > temp->information) {
					cout << temp2->information << " se interschimba cu " << temp->information << endl;
					T temporary = temp2->information;
					temp->information = temp2->information;
					temp2->information = temporary;
				}
				temp2 = temp2->next;
			}
			temp = temp->next;
		}

	}

	void print() {
		Lista* temp = new Lista;
		temp = head;
		while (temp -> next != nullptr) {
			cout << temp->information << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};