#include <Arduino.h>
#include "LDR.h"

LDR::LDR(int ldr_pin)
	: ldr_pin(ldr_pin)
{
}

LDR::~LDR()
{
}

int LDR::lightlevel()
{
	return analogRead(ldr_pin);
}
