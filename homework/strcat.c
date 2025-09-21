#include <stdio.h>

char *strcat(char *s, const char *ct) {
	char *original_s = s;

	while (*s != '\0') {
		s++;
	}

	while (*ct != '\0') {
		*s = *ct;
		s++;
		ct++;
	}
	*s = '\0';

	return original_s;
}
