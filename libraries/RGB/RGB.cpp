#include <Arduino.h>
#include <Debug.h>
#include "RGB.h"


RGB::RGB(int red_pin, int green_pin, int blue_pin)
	: red_pin(red_pin), green_pin(green_pin), blue_pin(blue_pin)
{
	state = LOW;
	current_millis = millis();
}

RGB::~RGB()
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

void RGB::initialize()
{
	pinMode(red_pin, OUTPUT);
	pinMode(green_pin, OUTPUT);
	pinMode(blue_pin, OUTPUT);
	state = LOW;
}

void RGB::on()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGB::off()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = LOW;
}

void RGB::red()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGB::green()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGB::blue()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGB::yellow()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
	state = HIGH;
}

void RGB::cyan()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGB::purple()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGB::white()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
	state = HIGH;
}

void RGB::blink_red(int interval)
{
	blink(&RGB::red, interval);
}

void RGB::blink_green(int interval)
{
	blink(&RGB::green, interval);
}

void RGB::blink_blue(int interval)
{
	blink(&RGB::blue, interval);
}

void RGB::blink_yellow(int interval)
{
	blink(&RGB::yellow, interval);
}

void RGB::blink_cyan(int interval)
{
	blink(&RGB::cyan, interval);
}

void RGB::blink_purple(int interval)
{
	blink(&RGB::purple, interval);
}

void RGB::blink_white(int interval)
{
	blink(&RGB::white, interval);
}

void RGB::blink(void (RGB::*on_func)(), int interval)
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
