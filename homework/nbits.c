#include <stdio.h>

int nbits() {
	unsigned char c = 1;
	int count = 0;

	while (c != 0) {
		c = c<<1;
		count++;
	}
	return count;
}

int main() {
	printf("Количество бит в типе char: %d\n", nbits());
	return 0;
}
