#include <stdio.h>
#include <math.h>

int main() {
	double x;
	int n;

	printf("Введите x: ");
	scanf("%lf", &x);
	printf("Введите натуральное n: ");
	scanf("%d", &n);

	double sum = 0.0, current = sin(x);

	for (int i = 1; i<=n; i++) {
		sum += current;
		current *= sin(x);
	}
	printf("Результат: %.10g\n", sum);

	return 0;
}
