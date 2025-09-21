#include <stdio.h>

size_t strlen(const char *cs) {
	size_t length = 0;

	while (*cs != '\0') {
		length++;
		cs++;
	}

	return length;
}
