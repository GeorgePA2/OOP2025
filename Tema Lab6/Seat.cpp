#include "Seat.h"

Seat::Seat() {
	SetFuelCap(200);
	SetFuelCons(15);
	SetSpeedRain(20);
	SetSpeedSnow(15);
	SetSpeedSun(25);
	SetCarName("Seat");
	SetDistances();
}

void Seat::SetFuelCap(const int fuel)
{
	this->fuel_cap = fuel;
}

void Seat::SetFuelCons(const int fuel)
{
	this->fuel_cons = fuel;
}

void Seat::SetSpeedSnow(const int speed)
{
	this->speed_snow = speed;
}

void Seat::SetSpeedSun(const int speed)
{
	this->speed_sun = speed;
}

void Seat::SetSpeedRain(const int speed)
{
	this->speed_rain = speed;
}

void Seat::SetDistances()
{
	this->distance_rain = (fuel_cap / fuel_cons) * speed_rain;
	this->distance_snow = (fuel_cap / fuel_cons) * speed_snow;
	this->distance_sunny = (fuel_cap / fuel_cons) * speed_sun;
}

void Seat::CanFinish(int length, int weather)
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
