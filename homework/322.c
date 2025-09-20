#include <stdio.h>

int main() {
	int n;
	printf("Введите натуральное число n:");
	scanf("%d", &n);

	if (n<=0) {
		printf("Ошибка, число должно быть натуральным\n");
		return 1;
	}

	int sum=0;
	int temp=n;

	while (temp > 0) {
		sum += temp%10;
		temp /= 10;
	}

	int cube = sum*sum*sum;
	int square = n*n;

	if (cube==square) {printf("Верно\n");}
	else {printf("Неверно\n"); }

	return 0;
}	
