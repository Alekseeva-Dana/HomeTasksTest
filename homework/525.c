#include <stdio.h>

double max_sum(double x[], int n) {
	if (n == 0) {
		return 0.0;
	}
	if (n == 1) return 2*x[0];

	double max_s = x[0] + x[n-1];

	for (int i=1; i<= (n-1)/2; i++) {
		int j = n - 1 -i;
		double cur_s = x[i] + x[j];

		if (cur_s > max_s) {
			max_s = cur_s;
		}
	}

	if (n%2 == 1) {
		double mid_s = 2*x[n/2];
		if (mid_s > max_s) {
			max_s = mid_s;
		}
	}
}

int main(){
	int n;
	double x[n];
	printf("Введите n: \n");
	scanf("%d", &n);
	printf("Введите массив x из %d элементов:\n", n);
	for (int k = 0; k<n; k++) {
		scanf("%lf", &x[k]);
	}

	printf("Результат: %.1f\n", max_sum(x, n));

	return 0;
}
