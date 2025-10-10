#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;
char curlex;

void getlex(void);
int expr(void);
int term(void);
int factor(void);
void error(void);

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

void getlex() {
    while ((curlex = getchar()) == ' ');
}

void error(void) {
    printf("\nОШИБКА!\n");
    while (getchar() != '\n');
    longjmp(begin, 1);
}

int expr() {
    int e = term();
    while (curlex == '+' || curlex == '-') {
        if (curlex == '+') {
            getlex();
            e += term();
        } else {
            getlex();
            e -= term();
        }
    }
    return e;
}

int term() {
    int t = factor();
    while (curlex == '*' || curlex == '/') {
        if (curlex == '*') {
            getlex();
            t *= factor();
        } else {
            getlex();
            int divisor = factor();
            if (divisor == 0) {
                printf("ОШИБКА: Деление на ноль!\n");
                error();
            }
            t /= divisor;
        }
    }
    return t;
}

int factor() {
    int f;
    
    // Обработка чисел и скобок
    if (curlex >= '0' && curlex <= '9') {
        f = curlex - '0';
        getlex();
    } else if (curlex == '(') {
        getlex();
        f = expr();
        if (curlex != ')') {
            error();
        }
        getlex();
    } else {
        error();
    }
    
    // Обработка степени
    if (curlex == '^') {
        getlex();
        int exponent = factor();
        if (exponent < 0) {
            printf("ОШИБКА: Отрицательная степень!\n");
            error();
        }
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= f;
        }
        f = result;
    }
    
    return f;
}
