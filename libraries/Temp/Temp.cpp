#include <Arduino.h>
#include "Temp.h"

Temp::Temp(int temp_pin)
	: temp_pin(temp_pin)
{
}

Temp::~Temp()
{
}

double Temp::celsius()
{
	double voltage = analogRead(temp_pin) * 0.004882814;
	return (voltage - 0.5) * 100;
}

