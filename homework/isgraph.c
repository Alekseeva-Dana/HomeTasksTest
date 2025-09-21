#include <stdio.h>

int isgraph(int c) {
	if (c == EOF) return 0;
	return c >= 33 && c <= 126;
}
