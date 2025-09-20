#include <stdio.h>

unsigned int replace_bits(unsigned int x, unsigned int y, int p,int n) {

	unsigned int inverted_y = ~y;

	unsigned int mask_y = (~0u) << (sizeof(unsigned int)*8 - n);
	unsigned int high_bits = inverted_y & mask_y;

	high_bits = high_bits >> (sizeof(unsigned int)*8 - n - p);

	unsigned int mask_clear = (~0u) << (sizeof(unsigned int)*8 - n);
	mask_clear = ~(mask_clear >>(sizeof(unsigned int)*8 - n - p));

	x = x & mask_clear;

	x = x | high_bits;

	return x;
}

int main() {
	unsigned int x, y;
	int p, n;
	printf("Введите x, y, p, n: ");
	scanf("%u %u %d %d", &x, &y, &p, &n);
	
	unsigned int res = replace_bits(x, y, p, n);
	printf("Результат: %u", res);

	return 0;
}
