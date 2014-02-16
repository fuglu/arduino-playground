#include <Debug.h>
#include <RGBA.h>
#include <LDR.h>
#include <Temp.h>
#include <IRButtons.h>
#include <IRremote.h>

#define BUTTON_LOCK_TIMEOUT 600000

IRrecv irrecv(2);
RGBA led = RGBA(11, 10, 9);
LDR ldr = LDR(0);
Temp temp = Temp(1);

decode_results results;
bool button_lock = false;
unsigned long button_lock_time = 0;

void switch_button(int button)
{
	switch (button) {
		case BUTTON_1:
			debug("Button red");
			button_lock = true;
			led.red();
			break;
		case BUTTON_2:
			debug("Button blue");
			button_lock = true;
			led.blue();
			break;
		case BUTTON_3:
			debug("Button green");
			button_lock = true;
			led.green();
			break;
		case BUTTON_4:
			debug("Button purple");
			button_lock = true;
			led.purple();
			break;
		case BUTTON_5:
			debug("Button cyan");
			button_lock = true;
			led.cyan();
			break;
		case BUTTON_6:
			debug("Button yellow");
			button_lock = true;
			led.yellow();
			break;
		case BUTTON_7:
			debug("Button white");
			button_lock = true;
			led.white();
			break;
		case BUTTON_BACK:
			if (button_lock) {
				debug("Button off");
				button_lock = false;
			} else {
				debug("Button force off");
				button_lock = true;
			}

			led.off();
			break;
	}

	button_lock_time = millis();
}

void setup(void)
{
	Serial.begin(9600);

	led.initialize();
	irrecv.enableIRIn();

	debug("Ready!");
}

void loop(void)
{
	double celsius = temp.celsius();
	int lightlevel = ldr.lightlevel();

	if (button_lock && millis() - button_lock_time > BUTTON_LOCK_TIMEOUT) {
		debug("Button lock timeout");
		button_lock = false;
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

