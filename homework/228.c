#include <stdio.h>

unsigned int cyclic(unsigned int num, int n) {
	int bits = sizeof(unsigned int)*8;
	
	if (n == 0) return num;

	return(num >> n) | (num << (bits - n));
}

int main() {
	unsigned int num;
	int n;

	printf("Введите число: ");
	scanf("%u", &num);
	printf("Введите n:  ");
	scanf("%d", &n);

	unsigned int res = cyclic(num, n);
	printf("Результат: %u", res);

	return 0;
}

