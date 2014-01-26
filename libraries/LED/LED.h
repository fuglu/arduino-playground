#ifndef LED_h
#define LED_h


class LED {
public:
	LED (int pin);
	~LED ();

	void initialize();
	void on();
	void off();

private:
	int pin;
};

#endif

