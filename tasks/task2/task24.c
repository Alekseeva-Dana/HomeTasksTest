#include <stdio.h>

/*функция проверки на цифру*/
int is_digit(char c) { 
	return c >= '0' && c <= '9';
}

/*функция проверки на ПП*/
int is_space(char c) {
	return c == ' ' || c == '\t' || c == '\n' ||
	       c == '\r' || c == '\v' || c == '\f';
}

double str2double(char str[]) {
	double res = 0.0, frac = 0.0;
	int sign = 1, exp_sign = 1, exp = 0, has_frac = 0,
	    frac_digits = 0, has_exp = 0, i = 0;
	
	while (is_space(str[i])) i++; /*пропускаем пробелы в начале*/

	/*обработка знака*/
	if (str[i] == '+') {
		i++;
	} else if (str[i] == '-') {
			sign = -1;
			i++;
	}

	/*обработка целой части*/
	while (is_digit(str[i])) {
		res = res*10.0 + (str[i] - '0');
		i++;
	}

	/*обработка дробной части*/
	if (str[i] == '.') {
		has_frac = 1;
		i++;

		while (is_digit(str[i])) {
			frac = frac*10.0 + (str[i] - '0');
			frac_digits++;
			i++;
		}
	}

	/*обработка экспоненты*/
	if (str[i] == 'e' || str[i] == 'E') {
		has_exp = 1;
		i++;

		/*обработка знака экспоненты*/
		if (str[i] == '+') {
			i++;
		} else if (str[i] == '-') {
			exp_sign = -1;
			i++;
		}

		/*значение экспоненты*/
		while (is_digit(str[i])) {
			exp = exp*10 + (str[i] - '0');
			i++;
		}
	}

	/*добавление дробной части*/
	if (has_frac) {
		double div = 1.0;
		for (int j = 0; j < frac_digits; j++) {
			div *= 10.0;
		}
		res += frac/div;
	}

	/*применение экспоненты*/
	if (has_exp) {
		double power = 1.0;
		for (int j = 0; j < exp; j++) {
			if (exp_sign > 0) {
				power *= 10.0;
			} else {
				power /= 10.0;
			}
		}
		res *= power;
	}
	return sign*res;
}

int main() {
	char str[1000];
	while (scanf("%99s", str) == 1) {
		printf("%.10g\n", str2double(str));
	}

	return 0;
}

