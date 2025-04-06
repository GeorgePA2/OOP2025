#include "Volvo.h"

Volvo::Volvo() {
	SetFuelCap(100);
	SetFuelCons(25);
	SetSpeedRain(30);
	SetSpeedSnow(30);
	SetSpeedSun(30);
	SetCarName("Volvo");
	SetDistances();
}

void Volvo::SetFuelCap(const int fuel)
{
	this->fuel_cap = fuel;
}

void Volvo::SetFuelCons(const int fuel)
{
	this->fuel_cons = fuel;
}

void Volvo::SetSpeedSnow(const int speed)
{
	this->speed_snow = speed;
}

void Volvo::SetSpeedSun(const int speed)
{
	this->speed_sun = speed;
}

void Volvo::SetSpeedRain(const int speed)
{
	this->speed_rain = speed;
}
void Volvo::SetDistances()
{
	this->distance_rain = (fuel_cap / fuel_cons) * speed_rain;
	this->distance_snow = (fuel_cap / fuel_cons) * speed_snow;
	this->distance_sunny = (fuel_cap / fuel_cons) * speed_sun;
}

void Volvo::CanFinish(int length, int weather)
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
