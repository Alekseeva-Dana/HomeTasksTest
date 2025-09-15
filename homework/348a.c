#include <stdio.h>

int main() {
	
	char c;
	int count=0;

	printf("Введите последовательность, оканчивающуюся точкой: ");

	do {
		scanf("%c", &c);

		if (c == 'a') {
			count++;
		}
	}
	while (c != '.');

	printf("Символ 'a' встречается %d раз(а)\n", count);

	return 0;
}
