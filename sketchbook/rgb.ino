#include <RGB.h>

const int BLINK_INTERVAL = 2000;

RGB led = RGB(10, 11, 12);

void setup()
{
	led.initialize();
}

void loop()
{
	led.red();
	delay(BLINK_INTERVAL);

	led.green();
	delay(BLINK_INTERVAL);

	led.blue();
	delay(BLINK_INTERVAL);
}
