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
		//index = index * 2;
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
				value = temp->val;
				ok = false;
			}
			temp = temp->next;
		}
		return !ok;
	}
	Value Get_Value(Key key) {
		Mapare* temp = head;
		bool ok = true;
		while (temp != nullptr) {
			if (temp->cheie == key) {
				return temp->value;
			}
			temp = temp->next;
		}
		return nullptr;
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

///////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////
	//bool Includes(const Map<Key, Value>& map) {
	//	Mapare* newMap1 = map.head;
	//	while (newMap1 != nullptr) {
	//		Mapare* newTemp = head;
	//		bool ok = false;
	//		Key cheita = newMap1->cheie;
	//		while (newTemp != nullptr) {
	//			if (newTemp.Get_Value(cheita)==newMap1.Get_Value(cheita)) {
	//				ok = true;
	//			}
	//			newTemp = newTemp->next;
	//		}
	//		if (ok == false) {
	//			return false;
	//		}
	//		newMap1 = newMap1.next;
	//	}
	//	return true;
	//}
};