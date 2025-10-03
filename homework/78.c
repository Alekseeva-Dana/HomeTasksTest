#include <stdio.h>

int main() {
	int c;
	int was_space = 0; /*флаг: был ли предыдущий символ пробелом*/

	while ((c = getchar()) != '.' && c != EOF) {
		if (c == ' ') {
			if (!was_space) {
				putchar(' '); /*выводим пробел только если предыдущий был не пробелом*/
				was_space = 1;
			}
		}
		else {
			putchar(c); /*выводим непробельный символ*/
			was_space = 0;
		}
	}
	putchar('\n');
	return 0;
}
