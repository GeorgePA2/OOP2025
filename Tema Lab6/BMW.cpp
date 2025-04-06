#include "BMW.h"

BMW::BMW()
{
	SetFuelCap(75);
	SetFuelCons(25);
	SetSpeedRain(15);
	SetSpeedSun(50);
	SetSpeedSnow(20);
	SetCarName("BMW");
	SetDistances();
}

void BMW::SetFuelCap(const int fuel)
{
	this->fuel_cap = fuel;
}

void BMW::SetFuelCons(const int fuel)
{
	this->fuel_cons = fuel;
}

void BMW::SetSpeedSnow(const int speed)
{
	this->speed_snow = speed;
}

void BMW::SetSpeedSun(const int speed)
{
	this->speed_sun = speed;
}

void BMW::SetSpeedRain(const int speed)
{
	this->speed_rain = speed;
}

void BMW::SetDistances()
{
	this->distance_rain = (fuel_cap / fuel_cons) * speed_rain;
	this->distance_snow = (fuel_cap / fuel_cons) * speed_snow;
	this->distance_sunny = (fuel_cap / fuel_cons) * speed_sun;
}

void BMW::CanFinish(int length, int weather)
{
	if (weather == 0) {
		if (distance_sunny < length) {
			this->finished = false;
		}
		else {
			this->finished = true;
		}
	}
	if (weather == 1) {
		if (distance_rain < length) {
			this->finished = false;
		}
		else {
			this->finished = true;
		}
	}
	if (weather == 2) {
		if (distance_snow < length) {
			this->finished = false;
		}
		else {
			this->finished = true;
		}
	}
}
