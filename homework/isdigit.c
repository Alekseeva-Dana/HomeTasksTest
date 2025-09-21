#include <stdio.h>

int isdigit(int c) {
	if (c == EOF) return 0;
	return (c >= '0' && c <= '9');
}
