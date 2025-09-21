#include <stdio.h>
#include <string.h>

int isph(const char *s, int start, int end) {
	if (start >= end) {
		return 1;
	}

	while (start < end) {
		start++;
		end--;
	}

	if (s[start] != s[end]) {
		return 0;
	}
	return isph(s, start + 1, end - 1);
}

int palindrom(const char *s) {
	int len = strlen(s);
	if (len == 0) {
		return 1;
	}
	return isph(s, 0, len-1);
}
