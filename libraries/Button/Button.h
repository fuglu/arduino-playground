#ifndef Button_h
#define Button_h

class Button {
public:
	Button (int pin);
	~Button ();

	void initialize();
	bool isPressed();

private:
	int pin;
};

#endif

