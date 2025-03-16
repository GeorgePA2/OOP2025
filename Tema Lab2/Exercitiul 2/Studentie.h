#pragma once
class Studentie
{
	char* nume;
	float math;
	float english;
	float history;
	float avg;
public:
	void SetNume(const char* numestudent);
	char* getNume();
	void SetMath(float math);
	float getNotaMath();
	void SetEng(float english);
	float GetNotaEng();
	void SetHist(float history);
	float GetNotaHist();
	float AVG();


};

