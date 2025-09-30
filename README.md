<h1 align="center">Документация по Task'ам</a>
<br>
</br>        
<img width="300" height="450" alt="image" src="https://github.com/user-attachments/assets/b3e952da-4607-4153-b0d4-010cf65d2625" />
<br>
</br>
<h2 align="center">Описание <a href="https://github.com/Alekseeva-Dana/tasks/tree/main/tasks/task2" target="_blank">Task2</h2>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task21.c" tarhet="_blank">Task 2.1</h3>
<b>Описание переменных</b>
<p>xi - текущее значение x, xi_prev - предыдыдущее значение x (в цикле вычисления корня)</p>
<pre><code>double xi = 1.0, xi_prev;</code></pre>
<p>x - введенное число, корень которого нужно вычислить, eps - заданная точность поиска корня</p>
<pre><code> double x, eps;</code></pre>
<b>Описание функций</b>
<p>module возвращает модуль числа</p>
<pre><code>double module(double i) {
        return i<0 ? -i : i;
}</code></pre>
<p>calculate_sqrt вычисляет корень по методу Ньютона</p>
<pre><code>double calculate_sqrt(double x, double eps) {
        if (x < 0) return -1;
        if (x == 0) return 0;
        double xi = 1.0, xi_prev;
        do {
                xi_prev = xi;
                xi = 0.5*(xi_prev + x/xi_prev);
        } while (module(xi - xi_prev) >= eps);
        return xi;
}</code></pre>
<b>Описание действия программы</b>
<p>Пока не достигнут конец ввода, на вход подаются вещественные числа, из которых методом Ньютона вычисляется корень с заданной точностью</p>
<br>
</br>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task21.c" target="_blank">Task 2.2</h3>
Task 2.2 включает в себя три пункта: <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task221.c" target="_blank">Task 2.2.1, <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task222.c" target="_blank">Task 2.2.2, <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task223.c" target="_blank">Task 2.2.3
<h3 align="center">Описание для Task 2.2.3</h3>
<b>Описание переменных</b>
<p>n - степень многочлена, x - точка, в которой нужно вычислить значение, poly - переменная, в которой накапливается значение многочлена, deriv - переменная, в которой накапливается значение производной многочлена, integral - переменная, в которой накапливается значение определенного интеграла от многочлена с пределами интегрирования от 0 до x, a - значения коэффициентов многочлена (an, an-1, ..., a0)</p>
<pre><code>
        int n;
        double x;
        double poly = 0.0; 
        double deriv = 0.0; 
        double integral = 0.0;
        double a;</code></pre>
<b>Описание действия программы</b>
<p>Вводится последовательность вещественных чисел: степень многочлена, точка, в которой нужно посчитать значение многочлена, производной многочлена и определенного интеграла с пределами интегрирования 0 и x, а также коэффициенты этого многочлена. Значение многочлена и производной считаются по схеме Горнера. Для подсчета значения интеграла используется схема Горнера с предварительным вынесением x за скобку, и с последующим умножением на него</p>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task23.c" target="_blank">Task 2.3</h3>
<b>Описание переменных</b>
a, b, c - переменные типа int, использующиеся в функции fib_iterative для вычисления i-го члена последовательности Фибоначчи, a = Fi-2, b = Fi-1, c = Fi
<pre><code> int a = 0, b = 1, c;</code></pre>
i - индекс члена Фибоначчи, который требуется найти (в основной части программы)
<pre><code>int i;</code></pre>
<b>Описание функций</b>
fib_iterative - функция, которая итеративно считает i-ый член последовательности Фибоначчи
<pre><code>int fib_iterative(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
                c = a + b;
                a = b;
                b = c;
        }
        return b;
}</code></pre>
fib_recursive - функция, которая рекурсивно считает i-ый член последовательности Фибоначчи
<pre><code>int fib_recursive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fib_recursive(n-2) + fib_recursive(n-1);
}</code></pre>
<b>Описание действия программы</b>
Пользователь вводит с клавиатуры индекс i - номер члена Фибоначчи, который нужно найти (нумерация начинается с нуля). Число считается двумя способами - итеративно и рекурсивно. Начиная ~ с i=40 заметна разница в скорости счета: рекурсивный алгоритм считает число медленней
