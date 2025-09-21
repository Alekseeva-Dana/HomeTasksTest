#include <stdio.h>

char *strchr(const char *cs, char c) {

	while (*cs != '\0') {
		if (*cs == c) {
			return (char *)cs;
		}
		cs++;
	}

	if (c == '\0') {
		return (char *)cs;
	}

	return NULL;
}
