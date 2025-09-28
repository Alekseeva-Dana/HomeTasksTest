
#include <stdio.h>

/*итеративная функция*/
int fib_iterative(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int a = 0, b = 1, c;
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

/*рекурсивная функция*/
int fib_recursive(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib_recursive(n-2) + fib_recursive(n-1);
}

int main() {
	int i;
	printf("Введите номера членов последовательности Фибоначчи:\n");
	while (scanf("%d", &i) == 1) {
		printf("%d\n", fib_iterative(i));
		printf("%d\n", fib_recursive(i));
	}
	return 0;
}

