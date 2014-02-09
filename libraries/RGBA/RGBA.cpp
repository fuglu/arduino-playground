#include <Arduino.h>
#include <Debug.h>
#include "RGBA.h"


RGBA::RGBA(int red_pin, int green_pin, int blue_pin)
	: red_pin(red_pin), green_pin(green_pin), blue_pin(blue_pin)
{
	state = LOW;
	current_millis = millis();
}

RGBA::~RGBA()
{
	int pins[] = {red_pin, green_pin, blue_pin};

	for (int i = 0; i < sizeof(pins)/sizeof(int); i++) {
		if (pins[i] == 13) {
			pinMode(pins[i], OUTPUT);
		} else {
			pinMode(pins[i], INPUT);
		}
	}
}

void RGBA::initialize()
{
	pinMode(red_pin, OUTPUT);
	pinMode(green_pin, OUTPUT);
	pinMode(blue_pin, OUTPUT);
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = LOW;
}

void RGBA::on()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBA::off()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = LOW;
}

void RGBA::red()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBA::green()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBA::blue()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBA::yellow()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBA::cyan()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBA::purple()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBA::white()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBA::blink_red(int interval)
{
	blink(&RGBA::red, interval);
}

void RGBA::blink_green(int interval)
{
	blink(&RGBA::green, interval);
}

void RGBA::blink_blue(int interval)
{
	blink(&RGBA::blue, interval);
}

void RGBA::blink_yellow(int interval)
{
	blink(&RGBA::yellow, interval);
}

void RGBA::blink_cyan(int interval)
{
	blink(&RGBA::cyan, interval);
}

void RGBA::blink_purple(int interval)
{
	blink(&RGBA::purple, interval);
}

void RGBA::blink_white(int interval)
{
	blink(&RGBA::white, interval);
}

void RGBA::blink(void (RGBA::*on_func)(), int interval)
{
	int now = millis();

	if(now - current_millis > interval) {
		current_millis = now;

		if (state == HIGH)
			(this->*on_func)();
		else
			off();
	}
}
