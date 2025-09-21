#include <stdio.h>

int isspace(int c) {
	if (c == EOF) return 0;
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == '\f' || c == '\v';
}
