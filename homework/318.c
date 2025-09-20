#include <stdio.h>

int main() {
	int count = 0;
	printf("Чисел с двумя одинаковыми цифрами[111,999]: ");

	for (int n = 111; n<=999; n++) {
		int digit1 = n/100; /*первая цифра*/
		int digit2 = (n/10) % 10; /*вторая цифра*/
		int digit3 = n%10; /*третья цифра*/
		
		if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3) {
			count++;
		}
	}
	printf("%d", count);

	return 0;
}
