#include <Debug.h>
#include <RGBA.h>
#include <Sonar.h>

RGBA led = RGBA(11, 10, 9);
Sonar sonar = Sonar(12, 13);

void setup()
{
	Serial.begin(9600);

	led.initialize();
	sonar.initialize();

	debug("Ready!");
}

void loop()
{
	int cm = sonar.cm();

	if (cm < 10) {
		led.red();
	} else if (cm < 20) {
		led.blue();
	} else if (cm < 30) {
		led.green();
	} else {
		led.off();
	}

	delay(500);
}

