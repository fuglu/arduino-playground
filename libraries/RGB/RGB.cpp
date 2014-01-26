#include <Arduino.h>
#include <Debug.h>
#include "RGB.h"


RGB::RGB(int red_pin, int green_pin, int blue_pin)
	: red_pin(red_pin), green_pin(green_pin), blue_pin(blue_pin)
{
}

RGB::~RGB()
{
	if (red_pin == 13 || green_pin == 13 || blue_pin == 13) {
		if (red_pin == 13) {
			pinMode(red_pin, OUTPUT);
			pinMode(green_pin, INPUT);
			pinMode(blue_pin, INPUT);
		}
		if (green_pin == 13) {
			pinMode(red_pin, INPUT);
			pinMode(green_pin, OUTPUT);
			pinMode(blue_pin, INPUT);
		}
		if (blue_pin == 13) {
			pinMode(red_pin, INPUT);
			pinMode(green_pin, INPUT);
			pinMode(blue_pin, OUTPUT);
		}
	} else {
		pinMode(red_pin, INPUT);
		pinMode(green_pin, INPUT);
		pinMode(blue_pin, INPUT);
	}
}

void RGB::initialize()
{
	pinMode(red_pin, OUTPUT);
	pinMode(green_pin, OUTPUT);
	pinMode(blue_pin, OUTPUT);
}

void RGB::on()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
}

void RGB::off()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
}

void RGB::red()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, LOW);
}

void RGB::green()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
}

void RGB::blue()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
}

void RGB::yellow()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, LOW);
}

void RGB::cyan()
{
	digitalWrite(red_pin, LOW);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
}

void RGB::purple()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, LOW);
	digitalWrite(blue_pin, HIGH);
}

void RGB::white()
{
	digitalWrite(red_pin, HIGH);
	digitalWrite(green_pin, HIGH);
	digitalWrite(blue_pin, HIGH);
}

