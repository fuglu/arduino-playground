#include <Debug.h>
#include <RGBA.h>
#include <IRremote.h>

RGBA led = RGBA(11, 10, 9);
IRrecv irrecv(2);

decode_results results;

void setup(void) {
	Serial.begin(9600);

	led.initialize();
	irrecv.enableIRIn();

	debug("Ready!");
}

void loop(void) {
	if (irrecv.decode(&results)) {
		debug("%lu", results.value);

		if (results.value == 3426156383) {
			led.red();
		} else if (results.value == 1529844149) {
			led.blue();
		} else if (results.value == 3426156382) {
			led.green();
		} else if (results.value == 4011791626) {
			led.purple();
		} else if (results.value == 4011791625) {
			led.off();
		}

		irrecv.resume();
	}
}
