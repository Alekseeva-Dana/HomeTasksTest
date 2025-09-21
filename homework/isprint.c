#include <stdio.h>

int isprint(int c) {
	if (c == EOF) return 0;
	return c >= 32 && c <= 126;
}
