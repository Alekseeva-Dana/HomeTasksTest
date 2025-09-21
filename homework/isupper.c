#include <stdio.h>

int isupper(int c) {
	if (c == EOF) return 0;
	return (c >= 'A' && c <= 'Z');
}

