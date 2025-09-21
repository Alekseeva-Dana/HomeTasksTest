#include <stdio.h>

int isalnum(int c) {
	if (c == EOF) return 0;
	return isalpha(c) || isdigit(c);
}
