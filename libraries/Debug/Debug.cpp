#include <Arduino.h>
#include <stdarg.h>
#include "Debug.h"

void _debug(const char* file, int line, const char* func, const char* format, ...)
{
	char buf[128];
	va_list args;
	va_start (args,format);
	vsnprintf(buf,sizeof(buf),format,args);
	va_end (args);

	Serial.print(file);
	Serial.print(":");
	Serial.print(line);
	Serial.print(" [");
	Serial.print(millis());
	Serial.print("] ");
	Serial.print(func);
	Serial.print("() - ");
	Serial.println(buf);
}
