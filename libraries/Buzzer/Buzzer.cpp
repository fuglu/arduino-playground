#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer(int buzzer_pin)
	: buzzer_pin(buzzer_pin)
{
	pinMode(buzzer_pin, OUTPUT);
}

Buzzer::~Buzzer()
{
	if (buzzer_pin == 13) {
		pinMode(buzzer_pin, OUTPUT);
	} else {
		pinMode(buzzer_pin, INPUT);
	}
}

void Buzzer::initialize()
{
	pinMode(buzzer_pin, OUTPUT);
}

void Buzzer::play(int note, unsigned long duration)
{
	tone(buzzer_pin, note, duration);
	delay(duration);
	noTone(buzzer_pin);
}
