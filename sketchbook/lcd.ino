#include <Debug.h>
#include <LiquidCrystal.h>
#include <Temp.h>
#include <DHT.h>
#include <LDR.h>
#include <RGBA.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT dht(13, DHT22);
Temp temp(0);
LDR ldr(1);
RGBA led(6, 5, 3);


void setup()
{
	Serial.begin(9600);

	lcd.begin(16, 2);

	dht.begin();

	led.initialize();

}

void loop()
{
	float celsius = dht.readTemperature();
	float humidity = dht.readHumidity();

	bool day = ldr.day();

	lcd.clear();
	lcd.setCursor(0, 0);

	lcd.print("Temp: ");
	lcd.print(celsius);
	lcd.print("C");

	lcd.setCursor(0, 1);
	lcd.print("Luft: ");
	lcd.print(humidity);
	lcd.print("%");

	if (day) {
		led.off();
	} else {
		led.blue();
	}


	delay(2000);
}
