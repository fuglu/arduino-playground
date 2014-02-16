#ifndef Sonar_h
#define Sonar_h


class Sonar {
public:
	Sonar (int trigger_pin, int echo_pin);
	~Sonar ();

	void initialize();
	int cm();

private:
	int trigger_pin;
	int echo_pin;
};

#endif


