#include <stdio.h>

int isxdigit(int c) {
	if (c == EOF) return 0;
	return isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}
