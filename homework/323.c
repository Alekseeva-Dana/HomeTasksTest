#include <stdio.h>
#include <stdbool.h>


bool IsPowerOfThree(int n){
	while (n%3==0) {
		n/=3;
	}
	return n==1;
}

int main() {
	
	int n;
	printf("Введите натуральное число: ");
	scanf("%d", &n);

	if (IsPowerOfThree(n)) {
		printf("Число является степенью тройки\n");
	}
	else printf("Число НЕ является степенью тройки\n");

	return 0;
}
