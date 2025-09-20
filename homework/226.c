#include <stdio.h>

int main() {
	unsigned int packed;
	char c1, c2, c3, c4;

	printf("Введите беззнаковое целое число: ");
	scanf("%u", &packed);

	c1 = (packed >> 24);
	c2 = (packed >> 16);
	c3 = (packed >> 8);
	c4 = packed;

	printf("Распакованные символы: '%c' '%c' '%c' '%c'\n", c1, c2, c3, c4);

	return 0;
}
