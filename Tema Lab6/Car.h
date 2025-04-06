#pragma once
#include <iostream>
#include "Weather.h"
class Car {
protected:
	int fuel_cons, fuel_cap, speed_snow, speed_sun, speed_rain;
	char* car_name;
	float distance_snow, distance_rain, distance_sunny;
	bool finished;
public:
	virtual void SetFuelCap(const int fuel) = 0;
	virtual void SetFuelCons(const int fuel) = 0;
	virtual void SetSpeedSnow(const int speed) = 0;
	virtual void SetSpeedSun(const int speed) = 0;
	virtual void SetSpeedRain(const int speed) = 0;
	virtual void SetCarName(const char* name) = 0;
	virtual void SetDistances() = 0;
	virtual void CanFinish(int length, int weather) = 0;
	virtual bool Finish() = 0;
	virtual float Dist(int weather) = 0;
	virtual char* GetName() = 0;
};