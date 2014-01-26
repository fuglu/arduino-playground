#include <Debug.h>
#include <RGB.h>
#include <LED.h>


const int BLINK_INTERVAL = 500;

LED led[] = {LED(2), LED(3), LED(4), LED(5), LED(6), LED(7), LED(8)};
RGB rgb[] = {RGB(9, 10, 11)};

void on();
void off();
void blink();

void setup()
{
	Serial.begin(9600);

	for (int i = 0; i < sizeof(led)/sizeof(LED); i++) {
		led[i].initialize();
	}
	for (int i = 0; i < sizeof(rgb)/sizeof(RGB); i++) {
		rgb[i].initialize();
	}
}

void loop()
{
	off();
	on();
	delay(BLINK_INTERVAL);
	off();
	delay(BLINK_INTERVAL);
	blink();
	delay(BLINK_INTERVAL);
}

void on()
{
	for (int i = 0; i < sizeof(led)/sizeof(LED); i++) {
		led[i].on();
	}
	for (int i = 0; i < sizeof(rgb)/sizeof(RGB); i++) {
		rgb[i].on();
	}
}

void off()
{
	for (int i = 0; i < sizeof(led)/sizeof(LED); i++) {
		led[i].off();
	}
	for (int i = 0; i < sizeof(rgb)/sizeof(RGB); i++) {
		rgb[i].off();
	}
}

void blink()
{
	for (int i = 0; i < sizeof(led)/sizeof(LED); i++) {
		led[i].on();
		delay(BLINK_INTERVAL);
		led[i].off();
	}

	for (int i = 0; i < sizeof(rgb)/sizeof(RGB); i++) {
		rgb[i].red();
		delay(BLINK_INTERVAL);

		rgb[i].green();
		delay(BLINK_INTERVAL);

		rgb[i].blue();
		delay(BLINK_INTERVAL);

		rgb[i].yellow();
		delay(BLINK_INTERVAL);

		rgb[i].cyan();
		delay(BLINK_INTERVAL);

		rgb[i].purple();
		delay(BLINK_INTERVAL);

		rgb[i].white();
		delay(BLINK_INTERVAL);

		rgb[i].off();
	}
}

