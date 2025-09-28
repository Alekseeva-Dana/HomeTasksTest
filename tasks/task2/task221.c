#include <stdio.h>

int main() {
	double x, res = 0.0, coef;
	int first_num = 1;

	/*чтение первого числа - точки x*/
	printf("Введите точку x: \n");
	if (scanf("%lf", &x) != 1) {
		printf("Ошибка: не удалось прочитать точку x\n");
		return 1;
	}

	/*чтение коэффициентов многочлена от старшего к младшему*/
	printf("Введите коэффициенты an,...,a0: \n");
	while (scanf("%lf", &coef) == 1) {
		if (first_num) {
			res = coef;
			first_num = 0;
		} else {
			res = res*x + coef; /*использование схемы Горнера*/
		}
	}

	/*вывод результата*/
	printf("%.10g\n", res);

	return 0;
}
