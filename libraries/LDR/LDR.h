#ifndef LDR_h
#define LDR_h


class LDR {
public:
	LDR (int ldr_pin);
	~LDR ();

	int lightlevel();
	bool day();
	bool night();

private:
	int ldr_pin;
};

#endif


