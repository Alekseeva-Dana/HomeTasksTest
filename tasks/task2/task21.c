#include <stdio.h>

double module(double i) {
	return i<0 ? -i : i;
}

double calculate_sqrt(double x, double eps) {
	if (x < 0) return -1;
	if (x == 0) return 0;

	double xi = 1.0, xi_prev;
	do {
		xi_prev = xi;
		xi = 0.5*(xi_prev + x/xi_prev);
	} while (module(xi - xi_prev) >= eps);
	
	return xi;
}

int main() {
	double x, eps;
	
	/*printf("Введите точность вычислений: ");*/
	scanf("%lf", &eps);

	/*printf("Введите вещественные числа (для завершения - Ctrl+D): \n");*/

	while(scanf("%lf", &x) != EOF) {
		if (calculate_sqrt(x,eps) == -1) {
			printf("Ошибка: вычисление корня из отрицательного числа\n");
		} else printf("%.10g\n", calculate_sqrt(x,eps));
	}
	
	return 0;
}
				
