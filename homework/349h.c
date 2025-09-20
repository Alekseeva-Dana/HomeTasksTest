#include <stdio.h>

int main() {
	int c, state = 0;
	
	while ((c = getchar()) != '.') {
		if (c >= '0' && c <= '9') {
			if (state == 0) {
				if (c == '0') {
					state = 1;
				} else {
					putchar(c);
					state = 2;
				}
			} else if (state == 1) {
				if (c != '0') {
					putchar('0');
					putchar(c);
					state = 2;
				}
			} else {
				putchar('0');
			}
			putchar(c);
			state = 0;
		}
	}

	if (state == 1) {
		putchar('0');
	}

	return 0;
}	
