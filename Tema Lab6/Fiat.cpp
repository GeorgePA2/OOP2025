#include "Fiat.h"


Fiat::Fiat() {
	SetFuelCap(125);
	SetFuelCons(50);
	SetSpeedRain(50);
	SetSpeedSun(75);
	SetSpeedSnow(60);
	SetCarName("Fiat");
	SetDistances();
}
void Fiat::SetFuelCap(const int fuel)
{
	this->fuel_cap = fuel;
}

void Fiat::SetFuelCons(const int fuel)
{
	this->fuel_cons = fuel;
}

void Fiat::SetSpeedSnow(const int speed)
{
	this->speed_snow = speed;
}

void Fiat::SetSpeedSun(const int speed)
{
	this->speed_sun = speed;
}

void Fiat::SetSpeedRain(const int speed)
{
	this->speed_rain = speed;
}

void Fiat::SetDistances()
{
	this->distance_rain = (fuel_cap / fuel_cons) * speed_rain;
	this->distance_snow = (fuel_cap / fuel_cons) * speed_snow;
	this->distance_sunny = (fuel_cap / fuel_cons) * speed_sun;
}

void Fiat::CanFinish(int length, int weather)
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
