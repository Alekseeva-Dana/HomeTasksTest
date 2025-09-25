<h1 align="center">Документация по Task'ам</a> <br>
<img width="300" height="450" alt="image" src="https://github.com/user-attachments/assets/b3e952da-4607-4153-b0d4-010cf65d2625" />
<h2 align="center">Описание <a href="https://github.com/Alekseeva-Dana/tasks/tree/main/tasks/task2" target="_blank">Task2</h2>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task21.c" tarhet="_blank">Task 2.1</h3>
<b>Описание переменных</b>
<br>
</br>
<p>xi - текущее значение xi, xi_prev - предыдыдущее значение xi (в цикле вычисления корня)</p>
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
