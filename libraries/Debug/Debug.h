#ifndef Debug_h
#define Debug_h

#define debug(format, ...) _debug(__FILE__, __LINE__, __func__, format, ##__VA_ARGS__)

void print(const char* format, ...);
void _debug(const char* file, int line, const char* func, const char* format, ...);

#endif
