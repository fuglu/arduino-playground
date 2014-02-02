#include <Buzzer.h>

Buzzer buzzer = Buzzer(6);

void setup()
{
	buzzer.initialize();
}

void loop()
{
	buzzer.play(NOTE_C4, 400);
	buzzer.play(NOTE_D4, 400);
	buzzer.play(NOTE_E4, 400);
	buzzer.play(NOTE_F4, 400);
	buzzer.play(NOTE_G4, 400);
	buzzer.play(NOTE_A4, 400);
	buzzer.play(NOTE_B4, 400);
	buzzer.play(NOTE_C5, 400);

	delay(10000);
}

