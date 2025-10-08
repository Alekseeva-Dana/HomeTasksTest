#include <stdio.h>
#include <setjmp.h>

jmp_buf begin; /*точка начала диалога с пользователем*/

char curlex; /*текущая лексема*/

void getlex(void); /*выделяет из входного потока очередную лексему*/
int expr(void); /*распознает выражение и вычисляет его значение*/
int term(void); /*распознает слагаемое и вычисляет его значение*/
int factor(void); /*распознает множитель и вычисляет его значение*/
int power(void); /*распознает степень и вычисляет ее значение*/
void error(void); /*сообщает об ошибке в выражении*/

int main() {
	int result;
	setjmp(begin);
	printf("==>");
	getlex();
	result = expr();
	if (curlex != '\n') error();
	printf("\n%d\n", result);
	return 0;
}

void getlex(void) {
	while ((curlex = getchar()) == ' ');
}

void error(void) {
	printf("\nОШИБКА!\n");
	while(getchar() != '\n');longjmp(begin, 1);
}

int expr(void) {
	int e = term();
	while (curlex == '+' || curlex == '-') {
		char op = curlex;
		getlex();
		if (op == '+')
			e += term();
		else
			e -= term();
	}
	return e;
}

int term(void) {
	int t = factor();
	while (curlex == '*' || curlex == '/') {
		char op = curlex;
		getlex();
		int f = factor();
		if (op == '*')
			t *= f;
		else {
			if (f == 0) error(); /*деление на ноль*/
			t /= f;
		}
	}
	return t;
}

int factor(void) {
	int f = power();
	while (curlex == '^') {
		getlex();
		int p = factor(); 
		if (p < 0) error(); /*отрицательная степень*/
		
		int result = 1;
		for (int i = 0; i < p; i++)
			result *= f;
		f = result;
	}
	return f;
}

int power(void) {
	int p;
	switch(curlex) {
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			p = curlex - '0';
			break;
		case '(':
			getlex();
			p = expr();
			if (curlex != ')') error();
			break;
		default:
			error();
	}
	getlex();
	return p;
}

