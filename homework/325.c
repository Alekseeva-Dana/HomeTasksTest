#include <stdio.h>

int main() {

	double a;
	int n=1;
	double sum=0.0;

	printf("Введите положительное вещественное число a: ");
	scanf("%lf", &a);

	while (sum <= a) {
		sum += 1.0/n;
		n++;
	}
	printf("Наименьшее n: %d\n", n-1);

	return 0;
}
