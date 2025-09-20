#include <stdio.h>

int is_perfect(int num) {
	if (num <= 1) {
		return 0;
	}

	int sum = 1;

	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			sum += i;
			if (i != num/i) {
				sum += num/i;
			}
		}
	}

	return sum == num;
}

int main() {
	int n;
	printf("Введите натуральное число n: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Ошибка: n должно быть натуральным числом\n");
		return 1;
	}

	int found = 0;
	for (int i = 2; i < n; i++) {
		if (is_perfect(i)) {
			found++;
		}
	}

	printf("Найдено совершенных чисел: %d\n", found);
	return 1;
}
