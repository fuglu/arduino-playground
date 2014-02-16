#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int trigger_pin, int echo_pin)
	: trigger_pin(trigger_pin), echo_pin(echo_pin)
{
}

Sonar::~Sonar()
{
	if (trigger_pin == 13) {
		pinMode(trigger_pin, OUTPUT);
	} else {
		pinMode(trigger_pin, INPUT);
	}

	if (echo_pin == 13) {
		pinMode(echo_pin, OUTPUT);
	} else {
		pinMode(echo_pin, INPUT);
	}
}

void Sonar::initialize()
{
	pinMode(trigger_pin, OUTPUT);
	pinMode(echo_pin, INPUT);
}

int Sonar::cm()
{
	digitalWrite(trigger_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigger_pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(trigger_pin, LOW);

	unsigned long duration = pulseIn(echo_pin, HIGH);
	return (int) (duration / 29 / 2);
}

