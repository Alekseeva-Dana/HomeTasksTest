#include <stdio.h>

int isalpha(int c) {
	if (c == EOF) return 0;
	return isupper(c) || islower(c);
}
