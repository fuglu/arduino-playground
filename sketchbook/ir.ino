#include <Debug.h>
#include <RGBA.h>
#include <LDR.h>
#include <Temp.h>
#include <IRButtons.h>
#include <IRremote.h>

#define BUTTON_LOCK_TIMEOUT 180000

IRrecv irrecv(2);
RGBA led = RGBA(11, 10, 9);
LDR ldr = LDR(0);
Temp temp = Temp(1);

decode_results results;
int button_lock = 0;
unsigned long button_lock_time = 0;

void setup(void) {
	Serial.begin(9600);

	led.initialize();
	irrecv.enableIRIn();

	debug("Ready!");
}

void switch_button(int button)
{
	switch (button) {
		case BUTTON_1:
			debug("Button red");
			button_lock = 1;
			led.red();
			break;
		case BUTTON_2:
			debug("Button blue");
			button_lock = 1;
			led.blue();
			break;
		case BUTTON_3:
			debug("Button green");
			button_lock = 1;
			led.green();
			break;
		case BUTTON_4:
			debug("Button purple");
			button_lock = 1;
			led.purple();
			break;
		case BUTTON_5:
			debug("Button cyan");
			button_lock = 1;
			led.cyan();
			break;
		case BUTTON_6:
			debug("Button yellow");
			button_lock = 1;
			led.yellow();
			break;
		case BUTTON_7:
			debug("Button white");
			button_lock = 1;
			led.white();
			break;
		case BUTTON_BACK:
			if (button_lock == 0) {
				debug("Button force off");
				button_lock = 1;
			} else {
				debug("Button off");
				button_lock = 0;
			}

			led.off();
			break;
	}

	button_lock_time = millis();
}

void loop(void) {
	double celsius = temp.celsius();

	int lightlevel = ldr.lightlevel();

	if (button_lock && millis() - button_lock_time > BUTTON_LOCK_TIMEOUT) {
		debug("Button lock timeout");
		button_lock = 0;
	}

	if (irrecv.decode(&results)) {
		debug("IR signal: %lu", results.value);
		debug("Light signal: %i", lightlevel);
		debug("Temp: %i", (int) celsius);

		switch_button(results.value);

		delay(300);

		irrecv.resume();
	} else if (! button_lock && lightlevel >= 350) {
		led.blue();
	} else if (! button_lock && lightlevel < 350) {
		led.off();
	}
}
