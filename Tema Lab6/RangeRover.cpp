#include "RangeRover.h"


RangeRover::RangeRover() {
	SetFuelCap(80);
	SetFuelCons(40);
	SetSpeedSun(120);
	SetSpeedRain(80);
	SetSpeedSnow(75);
	SetCarName("RangeRover");
	SetDistances();
}

void RangeRover::SetFuelCap(const int fuel)
{
	this->fuel_cap = fuel;
}

void RangeRover::SetFuelCons(const int fuel)
{
	this->fuel_cons = fuel;
}

void RangeRover::SetSpeedSnow(const int speed)
{
	this->speed_snow = speed;
}

void RangeRover::SetSpeedSun(const int speed)
{
	this->speed_sun = speed;
}

void RangeRover::SetSpeedRain(const int speed)
{
	this->speed_rain = speed;
}
void RangeRover::SetDistances()
{	
	this->distance_rain = (fuel_cap / fuel_cons) * speed_rain;
	this->distance_snow = (fuel_cap / fuel_cons) * speed_snow;
	this->distance_sunny = (fuel_cap / fuel_cons) * speed_sun;
}

void RangeRover::CanFinish(int length, int weather)
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
