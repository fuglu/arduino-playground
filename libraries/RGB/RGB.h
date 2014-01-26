#ifndef RGB_h
#define RGB_h


class RGB {
public:
	RGB (int red_pin, int green_pin, int blue_pin);
	~RGB ();

	void initialize();
	void on();
	void off();
	void red();
	void green();
	void blue();
	void yellow();
	void cyan();
	void purple();
	void white();

	void blink_red(int interval);
	void blink_green(int interval);
	void blink_blue(int interval);
	void blink_yellow(int interval);
	void blink_cyan(int interval);
	void blink_purple(int interval);
	void blink_white(int interval);

private:
	int red_pin;
	int green_pin;
	int blue_pin;
	int state;
	long unsigned int current_millis;

	void blink(void (RGB::*on)(), int interval);
};

#endif

