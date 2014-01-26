#include <Arduino.h>
#include <Debug.h>
#include "LED.h"


LED::LED(int pin)
	: pin(pin)
{
	state = LOW;
	current_millis = millis();
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
	state = LOW;
}

void LED::on()
{
	digitalWrite(pin, HIGH);
	state = HIGH;
}

void LED::off()
{
	digitalWrite(pin, LOW);
	state = LOW;
}

void LED::toggle()
{
	if (state == LOW)
		on();
	else
		off();
}

void LED::blink(int interval)
{
	int now = millis();

	if((now - current_millis) > interval) {
		current_millis = now;

		if (state == LOW)
			on();
		else
			off();
	}
}

