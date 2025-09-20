#include <stdio.h>

int main() {
	int n;
	printf("Введите количество чисел Фибоначчи(>0): ");
	scanf("%d", &n);

	if (n<=0) {
		printf("Ошибка: нужно положительное число\n");
		return 1;
	}

	if (n>=1) printf("f0 = 1");
	if (n>=2) printf(", f1 = 1");

	int fib_prev_prev=1, fib_prev=1, fib;

	for (int i=2; i<n; i++) {
		fib = fib_prev_prev + fib_prev;
		printf(", f%d = %d", i, fib);

		fib_prev_prev = fib_prev;
		fib_prev = fib;
	}
	printf("\n");

	return 0;
}
