#include <stdio.h>

int main() {
	unsigned int packed;
	char c1, c2, c3, c4;

	printf("Введите беззнаковое целое число: ");
	scanf("%u", &packed);

	c1 = (packed >> 24) & 0xFF;
	c2 = (packed >> 16) & 0xFF;
	c3 = (packed >> 8) & 0xFF;
	c4 = packed & 0xFF;

	printf("Распакованные символы: '%c' '%c' '%c' '%c'\n", c1, c2, c3, c4);

	return 0;
}
