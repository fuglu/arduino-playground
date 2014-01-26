#include <Arduino.h>
#include "Button.h"


Button::Button(int pin)
	: pin(pin)
{
}

Button::~Button()
{
	if (pin == 13) {
		pinMode(pin, OUTPUT);
	} else {
		pinMode(pin, INPUT);
	}
}

void Button::initialize()
{
	pinMode(pin, INPUT);
}

bool Button::isPressed()
{
	return digitalRead(pin);
}

