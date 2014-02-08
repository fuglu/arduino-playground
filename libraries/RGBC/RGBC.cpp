#include <Arduino.h>
#include <Debug.h>
#include "RGBC.h"


RGBC::RGBC(int red_pin, int green_pin, int blue_pin)
	: red_pin(red_pin), green_pin(green_pin), blue_pin(blue_pin)
{
	state = LOW;
	current_millis = millis();
}

RGBC::~RGBC()
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

void RGBC::initialize()
{
	pinMode(red_pin, OUTPUT);
	pinMode(green_pin, OUTPUT);
	pinMode(blue_pin, OUTPUT);
	state = LOW;
}

void RGBC::on()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBC::off()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = LOW;
}

void RGBC::red()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBC::green()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBC::blue()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBC::yellow()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGBC::cyan()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBC::purple()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBC::white()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGBC::blink_red(int interval)
{
	blink(&RGBC::red, interval);
}

void RGBC::blink_green(int interval)
{
	blink(&RGBC::green, interval);
}

void RGBC::blink_blue(int interval)
{
	blink(&RGBC::blue, interval);
}

void RGBC::blink_yellow(int interval)
{
	blink(&RGBC::yellow, interval);
}

void RGBC::blink_cyan(int interval)
{
	blink(&RGBC::cyan, interval);
}

void RGBC::blink_purple(int interval)
{
	blink(&RGBC::purple, interval);
}

void RGBC::blink_white(int interval)
{
	blink(&RGBC::white, interval);
}

void RGBC::blink(void (RGBC::*on_func)(), int interval)
{
	int now = millis();

	if(now - current_millis > interval) {
		current_millis = now;

		if (state == LOW)
			(this->*on_func)();
		else
			off();
	}
}
