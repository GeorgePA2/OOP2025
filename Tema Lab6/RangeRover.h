#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
public:
    void SetFuelCap(const int fuel);
    void SetFuelCons(const int fuel);
    void SetSpeedSnow(const int speed);
    void SetSpeedSun(const int speed);
    void SetSpeedRain(const int speed);
	void SetCarName(const char* name) {
		int i = 0;
		while (name[i] != '\0') {
			i++;
		}
		this->car_name = new char[i+1];
		int j=0;
		while (j < i) {
			this->car_name[j] = name[j];
			j++;
		}
		this->car_name[i] = '\0';
	}
    void SetDistances();
    void CanFinish(int length, int weather);
	bool Finish() {
		return this->finished;
	}
	float Dist(int weather) {
		if (weather == 0) {
			return this->speed_sun;
		}
		if (weather == 1) {
			return this->speed_rain;
		}
		if (weather == 2) {
			return this->speed_snow;
		}
	}
	char* GetName() {
		return this->car_name;
	}
	RangeRover();
};


