#include "Circuit.h"
#include "Weather.h"
#include "BMW.h";
#include "Fiat.h";
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"
Circuit::Circuit()
{
	this->car_count = 0;
	this->circuit_length = 300;
	this->current_weather = 0;
	this->loser_count = 0;
	this->winner_count = 0;
}

void Circuit::SetLength(int length)
{
	this->circuit_length = length;
}


void Circuit::AddCar(Car* newcar)
{
	this->Cars[car_count] = newcar;
	//printf("Numele masinii este %s \n", Cars[car_count]->GetName());
	car_count++;
}

void Circuit::SetWeather(int weather)
{
	this->current_weather = weather;
}

void Circuit::Race()
{
	for (int i = 0; i < car_count; i++) {
		Cars[i]->CanFinish(circuit_length, current_weather);
		//if (Cars[i]->Finish() == true) {
		//	printf("beep\n");
		//}
		//else {
		///	printf("boop\n");
		//}
		timetofinish[i] = circuit_length / (Cars[i]->Dist(current_weather));
	//	printf("timetofinish[%d] = %f / %d \n", i, Cars[i]->Dist(current_weather), circuit_length);
	//	printf("timetofinish[%d] = %f \n", i, timetofinish[i]);
	}
	for (int i = 0; i < car_count; i++) {
		this->position[i] = 0;
		if (Cars[i]->Finish() == false) {
			this->position[i] = this->last_post + 1;
			this->last_post--;
			timetofinish[i] = 0;
		//	printf("Masina care nu a putut incheia cursa este %s, aflata pe locul %d \n", Cars[i]->GetName(), position[i]);
		//	printf("ultima pozitie este %d \n", last_post+1);
		}
	}
	for (int i = 0; i < car_count; i++) {
		for (int j = 0; j < car_count; j++) {
			if ((timetofinish[i] > timetofinish[j]) && ((timetofinish[i]!=0) || (timetofinish[j]==0))) {
				position[i]++;
			//	printf("Pozitia masinii %s s-a schimbat la %d, depasind Masina %s \n", Cars[i]->GetName(), position[i], Cars[j]->GetName());
			}
		}
	}
	//printf("Masinile de pe primele %d pozitii sunt: ", last_post);
	for (int i = 0; i < car_count; i++) {
		//printf("%s ", Cars[position[i]-1]->GetName());
		clasament[position[i]-1] = i;
	}
	//printf("\n");
	

}

void Circuit::ShowFinalRanks()
{
	printf("Clasamentul Cursei este:\n");
	for (int i = 0; i < car_count; i++) {
		printf("Pe locul %d cu un timp de %f ore se afla %s \n", (i + 1), timetofinish[clasament[i]], Cars[clasament[i]]->GetName());
		//printf("Pe locul %d cu o viteza de %f se afla \n", (i + 1), timetofinish[i]);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("Masinile care nu au putut incheia cursa:\n");
	for (int i = 0; i < car_count; i++) {
		if (Cars[i]->Finish() == false) {
			printf("%s ", Cars[i]->GetName());
		}
	}
}
