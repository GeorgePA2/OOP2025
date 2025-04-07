#include <iostream>
using namespace std;

int operator"" _Kelvin(unsigned long long int x) {
    return x - 273.15;
}
int operator"" _Fahrenheit(unsigned long long int x) {
    return (x - 32) / 1.8;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    printf("300 Kelvin in Celsius este %f iar 120 F to Celsius este %f", a, b);
    return 0;
}
