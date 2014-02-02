#include <RGB.h>
#include <Temp.h>

RGB led = RGB(12, 11, 10);
Temp temp = Temp(1);

void setup()
{
	led.initialize();
}

void loop()
{
	double celsius = temp.celsius();

	if (celsius > 30) {
		led.red();
	} else if (celsius > 20) {
		led.green();
	} else if (celsius > 10) {
		led.blue();
	} else {
		led.off();
	}

	delay(1000);
}

