#ifndef Temp_h
#define Temp_h


class Temp {
public:
	Temp (int temp_pin);
	~Temp ();

	double celsius();

private:
	int temp_pin;
};

#endif


