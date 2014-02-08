#include <RGBA.h>

RGBA led = RGBA(11,10,9);

void setup()
{
	led.initialize();
}

void loop()
{
	led.red();
	delay(4000);
	led.green();
	delay(4000);
	led.blue();
	delay(4000);
	led.cyan();
	delay(4000);
	led.yellow();
	delay(4000);
	led.purple();
	delay(4000);
	led.white();
	delay(4000);
}
