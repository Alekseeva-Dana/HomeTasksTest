#include <stdio.h>

int main() {
	double x, poly = 0.0; /*значение многочлена*/ 
	double der = 0.0, coef; /*значение производной*/
	int degree = 0;

	/*чтение первого числа - точки x*/
	printf("Введите точку x: \n");
	if (scanf("%lf", &x) != 1) {
		printf("Ошибка: не удалось прочитать точку x\n");
		return 1;
	}

	/*чтение коэффициентов многочлена от старшего к младшему*/
	printf("Введите коэффициенты an,...,a0: \n");
	while (scanf("%lf", &coef) == 1) {
		degree++;
		if (degree == 1) {
			poly = coef;
			der = 0.0; /*производная первого коэффициента*/
		} else {
			der = der*x + poly;
			poly = poly*x + coef;
		}
	}

	/*вывод результата*/
	printf("Значение многочлена: ");
	printf("%.10g\n", poly);
	printf("Значение производной: ");
	printf("%.10g\n", der);

	return 0;
}
