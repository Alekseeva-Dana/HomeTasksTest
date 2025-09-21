#include <stdio.h>

char *strstr(const char *cs, const char *ct) {

	if (*ct == '\0') {
		return (char *)cs;
	}

	while (*cs != '\0') {
		const char *cs_temp = cs;
		const char *ct_temp = ct;

		while (*cs_temp != '\0' && *ct_temp != '\0' && *cs_temp == *ct_temp) {
			cs_temp++;
			ct_temp++;
		}

		if (*ct_temp == '\0') {
			return (char *)cs;
		}

		cs++;
	}
	return NULL;
}
