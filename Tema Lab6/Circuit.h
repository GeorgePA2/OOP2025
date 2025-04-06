#pragma once
#include "Weather.h"
#include "BMW.h";
#include "Fiat.h";
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"
class Circuit
{
private:
    Car* Cars[5];
    int position[5] = { 0 };
    int clasament[5] = { 0 };
    float timetofinish[5] = { 0 };
    int current_weather;
    int last_post = 4;
    int car_count, loser_count, winner_count;
    int circuit_length;

public:
    Circuit();
    void SetLength(int length);
    void AddCar(Car* newcar);
    void SetWeather(int weather);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

