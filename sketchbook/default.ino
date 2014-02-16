#include <Debug.h>
#include <RGBA.h>

RGBA led = RGBA(11, 10, 9);

void setup()
{
	Serial.begin(9600);

	led.initialize();

	debug("Ready!");
}

void loop()
{
	debug("on");
	led.blue();
	delay(10000);

	debug("off");
	led.off();
	delay(10000);
}

