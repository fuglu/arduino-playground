#include <Button.h>
#include <LED.h>
#include <RGB.h>


LED leds[] = {LED(2), LED(3), LED(4), LED(5), LED(6), LED(7), LED(8)};
RGB rgb = RGB(9, 10, 11);
Button btn = Button(12);

void setup()
{
	for (int i = 0; i < sizeof(leds)/sizeof(LED); i++) {
		leds[i].initialize();
	}
	btn.initialize();
	rgb.initialize();
}

void loop()
{
	rgb.green();
	if (btn.isPressed()) {
		rgb.red();
		for (int i = 0; i < sizeof(leds)/sizeof(LED); i++) {
			leds[i].on();
			delay(500);
			leds[i].off();
		}
	} else {
		for (int i = 0; i < sizeof(leds)/sizeof(LED); i++) {
			leds[i].off();
		}
	}
}

