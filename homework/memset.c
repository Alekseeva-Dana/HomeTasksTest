#include <stdio.h>

void *memset(void *s, char c, size_t n) {
	char *ptr = (char *)s;

	for (size_t i = 0; i < n; i++) {
		ptr[i] = c;
	}
	return s;
}
