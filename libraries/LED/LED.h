#ifndef LED_h
#define LED_h


class LED {
public:
	LED (int pin);
	~LED ();

	void initialize();
	void on();
	void off();
	void toggle();
	void blink(int interval);

private:
	int pin;
	int state;
	long unsigned int current_millis;
};

#endif

