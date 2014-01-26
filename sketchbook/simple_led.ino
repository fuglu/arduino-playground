#include <LED.h>

const int BLINK_INTERVAL = 2000;

LED led1 = LED(2);
LED led2 = LED(3);

void setup()
{
	led1.initialize();
	led2.initialize();
}

void loop()
{
	led1.blink(BLINK_INTERVAL);
	led2.on();
}
