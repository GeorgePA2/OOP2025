#pragma once
#include <iostream>

using namespace std;

template<class Key, class Value>
class Map {
private:
	int idx = 0;
	struct Mapare {
		int Index;
		Value val;
		Key cheie;
		Mapare* next;
	}*head;

	Mapare* currect_pos;
public:
	int x = 1, y = 2, z = 3;
	Map() {
		head = nullptr;
		currect_pos = head;
	}
	~Map() {
		while (head) {
			Mapare* temp = head;
			head = head->next;
			delete temp;
		}
	}
	Value& operator[](Key index) {
		Mapare* temp = head;
		while (temp != nullptr) {
			if (temp->cheie == index) {
				return temp->val;
			}
			temp=temp->next;
		}
		Mapare* newNod = new Mapare;
		newNod->Index = idx++;
		newNod->cheie = index;
		newNod->next = nullptr;
		if (head == nullptr) {
			head = newNod;
			currect_pos = head;
		}
		else {
			currect_pos->next = newNod;
			currect_pos = newNod;
		}
		return newNod->val;
	}

	void Set(Key index, Value value) {
		Mapare* temp = head;
		bool ok = true;
		while ((temp != nullptr) && ok) {
			if (temp->cheie == index) {
				temp->val = value;
				ok = false;
			}
			temp = temp->next;
		}
	}
	bool Get(const Key& key, Value& value) {
		Mapare* temp = head;
		bool ok = true;
		while ((temp != nullptr) && ok) {
			if (temp->cheie == key) {
				Key temp_key;
				int nr_cif=0;
				while (temp_key > 0) {
					temp_key /= 10;
					nr_cif++;
				}

				temp->val = value;
				ok = false;
			}
			temp = temp->next;
		}
	}
	int Count() {
		return idx;
	}
	void Clear() {
		while (head) {
			Mapare* temp = head;
			head = head->next;
			delete temp;
		}
		idx = 0;
	}
	bool Delete(const Key& key) {
		Mapare* temp = head;
		bool ok = true;
		while ((temp->next != nullptr) && ok) {
			if (temp->next->cheie == key) {
				temp->next = temp->next->next;
				idx--;
				ok = false;
			}
			temp = temp->next;
		}
		return(!ok);
	}
	class Iterator {
	private:
		Mapare* poz;
	public:
		struct Entry {
			Key& key;
			Value& value;
			int& index;
		};
		Iterator(Mapare* pozitie) :poz(pozitie) {};
		Iterator& operator++() {
			poz = poz->next;
			return (*this);
		}
		bool operator!=(const Iterator& poz2) const {
			return(poz != poz2.poz);
		}
		auto operator*() const {
			return Entry{ poz->cheie, poz->val, poz->Index };
		}
	};
	void print() {
		Mapare* temp = head;
		while (temp != nullptr) {
			cout << "Index: " << temp->Index << " Key: " << temp->cheie << " Value: " << temp->val << endl;
			temp = temp->next;
		}
	}

	Iterator begin() {
		return Iterator(head);
	}
	Iterator end() {
		return Iterator(nullptr);
	}

	//bool Includes(const Map<Key, Value>& map) {
	//	Mapare* newTemp = head;
	//	bool ok = false;
	//	while (newTemp != nullptr) {
	//		ok = false;
	//		for (auto [key, value, index] : map)
	//		{
	//			if (key == newTemp->cheie) {
	//				ok = true;
	//			}
	//		}
	//		if (ok == false) {
	//			return false;
	//		}
	//	}
	//	return true;
	//}
};