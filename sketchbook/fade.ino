void setup()
{
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
}

void loop()
{
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			for (int k = 0; k < 256; k++) {
				analogWrite(11, 255 - i);
				analogWrite(10, 255 - j);
				analogWrite(9, 255 - k);
			}
		}
	}
}

