#include <Button.h>
#include <LED.h>

LED led = LED(2);
Button btn = Button(12);

void setup()
{
	btn.initialize();
	led.initialize();
}

void loop()
{
	if (btn.isPressed())
		led.on();
	else
		led.off();
}

