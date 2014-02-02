#ifndef LDR_h
#define LDR_h


class LDR {
public:
	LDR (int ldr_pin);
	~LDR ();

	int lightlevel();

private:
	int ldr_pin;
};

#endif


