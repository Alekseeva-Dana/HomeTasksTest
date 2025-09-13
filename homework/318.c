#include <stdio.h>

int main() {
	int count = 0;

	printf("Натуральные числа от 111 до 999 с двумя одинаковыми цифрами:\n");

	for (int n = 111; n <= 999; n++) {
		int digit1 = n/100;
		int digit2 = (n/10)%10;
		int digit3 = n%10;
		
		if ((digit1==digit2) || (digit2==digit3) || (digit1==digit3)) {
			count++;
		}
	}
	printf("\n\nКоличество чисел с двумя одинаковыми цифрами: %d\n", count);

	return 0;
}
