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

private:
	int red_pin;
	int green_pin;
	int blue_pin;
};

#endif

