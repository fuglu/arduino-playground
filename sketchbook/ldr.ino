#include <RGB.h>
#include <LDR.h>


RGB led = RGB(12, 11, 10);
LDR ldr = LDR(0);

void setup()
{
	led.initialize();
}


void loop()
{
	int lightlevel = ldr.lightlevel();

	if (lightlevel > 900) {
		led.red();
	} else if (lightlevel > 600) {
		led.blue();
	} else if (lightlevel > 300) {
		led.green();
	} else {
		led.off();
	}
	delay(1000);
}

