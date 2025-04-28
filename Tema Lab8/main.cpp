#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) const {
		if (p1.second != p2.second) {
			return p1.second < p2.second;
		}
		return p1.first > p2.first;
	}
};

string to_lower_case(string setence) {
	for (int i = 0; i < setence.size(); i++) {
		if ((setence[i] >= 'A') && (setence[i] <= 'Z')) {
			setence[i] += 32;
			//cout << "litera acum este: " << setence[i]<< endl;
		}
	}
	return setence;
}

void count_words(string sentence, map<string, int>&word_counter) {
	int start = 0;
	string word;
	sentence = to_lower_case(sentence);
	//cout << sentence << endl;
	for (int i = 0; i < sentence.size(); i++) {
		if ((sentence[i] == ' ') || (sentence[i] == '?') || (sentence[i] == '.') || (sentence[i] == '!') || (sentence[i] == ',') || (sentence[i] == ';')){
			int lungime = i - start;
			word = sentence.substr(start, lungime);
			word_counter[word]++;
			start = i + 1;
			//cout << word << endl;
			i++;
		}
		while ((sentence[i] == ' ') || (sentence[i] == '?') || (sentence[i] == '.') || (sentence[i] == '!') || (sentence[i] == ',') || (sentence[i] == ';')) {
		//	printf("avem spatiu....\n");
			i++;
			start++;
		}

	}
}

int main() {

	string file_name;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> Coada_de_prioritati;
	printf("Va rog sa cititi numele filei de la tastatura: ");
	cin >> file_name;
	ifstream fin(file_name.c_str());
	//ifstream fin("Text.txt"); 
	string propozitie, cuvant;
	while (fin >> cuvant) {
		propozitie += cuvant + " ";
	}
	//printf("propozitia este: %s \n", propozitie.c_str());

	map<string, int> MyMap;
	map<string, int>::iterator MapIterator;
	count_words(propozitie, MyMap);
	for (MapIterator = MyMap.begin(); MapIterator != MyMap.end(); MapIterator++) {
		Coada_de_prioritati.push(pair<string, int>(MapIterator->first, MapIterator->second));
	}
	while (Coada_de_prioritati.empty() == false) {
		cout << Coada_de_prioritati.top().first << " => " << Coada_de_prioritati.top().second << endl;
		Coada_de_prioritati.pop();
	}
	fin.close();
	return 0;
}