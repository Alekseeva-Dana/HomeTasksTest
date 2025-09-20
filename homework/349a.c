#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != '.') {
		if (c == '?') {
			putchar('!');
		} else {
			putchar(c);
		}
	}

	return 0;
}
