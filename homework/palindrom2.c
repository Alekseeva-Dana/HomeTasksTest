#include <stdio.h>

int palindrom(char *s) {
	static char *end = NULL;

	if (end == NULL) {
		end = s;
		while (*end != '\0') end++;
		if (end > s) end--;
	}

	if (s >= end) {
		end = NULL;
		return 1;
	}

	if (*s != *end) {
		end = NULL;
		return 0;
	}

	end--;
	int result = palindrom(s+1);
	end = NULL;
	return result;
}
