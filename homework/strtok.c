#include <stdio.h>

static char *save = NULL;

int isd(char c, const char *del) {
	const char *d = del;
	while (*d != '\0') {
		if (c == *d) {
			return 1;
		}
		d++;
	}
	return 0;
}

char *strtok(char *s, const char *ct) {
	char *cur;

	if (s = NULL) {
		if (save == NULL) {
			return NULL;
		}
		cur = save;
	} else {
		cur = s;
	}

	while (*cur != '\0' && isd(*cur, ct)) {
		cur++;
	}

	if (*cur == '\0') {
		save = NULL;
		return NULL;
	}

	char *start = cur;

	while (*cur != '\0' && !isd(*cur, ct)) {
		cur++;
	}

	if (*cur != '\0') {
		*cur = '\0';
		save = cur + 1;
	} else {
		save = NULL;
	}
	return start;
}
