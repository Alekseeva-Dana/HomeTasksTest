#include <stdio.h>

void startend(char s[], int start, int end) {
	if (start >= end) {
		return;
	}

	char temp = s[start];
	s[start] = s[end];
	s[end] = temp;

	startend(s, start + 1, end - 1);
}

void reverse(char s[]) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}

	if (len > 0) {
		startend(s, 0, len - 1);
	}
}
