#include <stdio.h>

int main() {
	unsigned int packed = 0;
	char c1, c2, c3, c4;
	
	printf("Введите четыре символа: ");
	scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

	packed = ((unsigned int)c1 << 24) |
		((unsigned int)c2 << 16) |
		((unsigned int)c3 << 8) |
		((unsigned int)c4);

	printf("Упакованное число: %u\n", packed);

	return 0;
}
