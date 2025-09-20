#include <stdio.h>

int main() {
	int c, state = 0, found = 0;

	printf("Введите последовательность символов, оканчивающуюся точкой:\n");

	while ((c = getchar()) != '.') {
		switch (state) {
			case 0:
				if (c == 'c' || c=='C') {
					state = 1;
				}
				break;
			case 1:
				if (c=='h' || c=='H') {
					state = 2;
				} else if (c=='c' || c=='C') {
				} else {
					state = 0;
				}
				break;
			case 2:
				if (c=='a' || c=='A') {
					state = 3;
				} else if (c=='c' || c=='C') {
					state = 1;
				} else {
					state = 0;
				}
				break;
			case 3:
				if (c == 'r' || c == 'R') {
					found = 1;
					state = 0;
				} else if (c == 'c' || c== 'C') {
					state = 1;
				} else {
					state = 0;
				}
				break;
		}
	}

	if (found) {
		printf("Да\n");
	} else printf("Нет\n");

	return 0;
}
