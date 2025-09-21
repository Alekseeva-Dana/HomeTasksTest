#include <stdio.h>

void *memcpy(void *s, const void *ct, size_t n) {
	char *dest = (char *)s;
	const char *src = (const char*)ct;

	for (size_t i = 0; i < n; i++) {
		dest[i] = src[i];
	}
	return s;
}
