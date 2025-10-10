#include <stdio.h>

int main() {
	
	int n;
	double x;

	/*printf("Введите степень многочлена n, точку x и коэффициенты an, an-1, ..., a0:\n");*/
	scanf("%d", &n);
	scanf("%lf", &x);

	double poly = 0.0; /*значение многочлена*/
	double deriv = 0.0; /*значение производной*/
	double integral = 0.0; /*значение интеграла*/

	for (int i = n; i >= 0; i--) {
		double a;
		scanf("%lf", &a);

		/*схема Горнера для многочлена*/
		poly = poly*x + a;

		/*схема Горнера для производной*/
		if (i >0) {
			deriv = deriv*x + a*i;
		}

		/*вычисление части интеграла*/
		integral = integral*x + a/(i+1);
	}

	/*конечный интеграл*/
	integral *= x;

	printf("%.10g\n", poly);
	printf("%.10g\n", deriv);
	printf("%.10g\n", integral);

	return 0;
}
