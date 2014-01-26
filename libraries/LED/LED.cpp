#include <Arduino.h>
#include <Debug.h>
#include "LED.h"


LED::LED(int pin)
	: pin(pin)
{
}

LED::~LED()
{
	if (pin == 13) {
		pinMode(pin, OUTPUT);
	} else {
		pinMode(pin, INPUT);
	}
}

void LED::initialize()
{
	pinMode(pin, OUTPUT);

}

void LED::on()
{
	digitalWrite(pin, HIGH);

}

void LED::off()
{
	digitalWrite(pin, LOW);
}

