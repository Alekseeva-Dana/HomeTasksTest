
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
<br>
</br>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task23.c" target="_blank">Task 2.3</h3>
<b>Описание переменных</b>
<br>
a, b, c - переменные типа int, использующиеся в функции fib_iterative для вычисления i-го члена последовательности Фибоначчи, a = Fi-2, b = Fi-1, c = Fi
<pre><code> int a = 0, b = 1, c;</code></pre>
i - индекс члена Фибоначчи, который требуется найти (в основной части программы)
<pre><code>int i;</code></pre>
<b>Описание функций</b>
<br>
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
<br>
Пользователь вводит с клавиатуры индекс i - номер члена Фибоначчи, который нужно найти (нумерация начинается с нуля). Число считается двумя способами - итеративно и рекурсивно. Начиная ~ с i=40 заметна разница в скорости счета: рекурсивный алгоритм считает число медленней
<br>
</br>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task24.c" target="_blank">Task 2.4</h3>
<b>Описание переменных</b>
<br>
c - очередной введенный символ (в функциях)
<pre><code>(char c)</code></pre>
char [str] - массив из символов, который хранит введенные символы (в функции)
<pre><code>(char str[])</code></pre>
res - конечное число(которое нам нужно будет вывести), frac - дробная часть конечного числа, sign - знак числа(1 если "+" и -1 если "-"), exp - значение экспоненты(если она есть), exp_sign - знак экспоненты, has_frac - флаг наличия дробной части, frac_digits - цифры дробной части(счетчик), has_exp - флаг наличия экспоненты, i - индекс для движения по массиву str[]
<pre><code> double res = 0.0, frac = 0.0;
        int sign = 1, exp_sign = 1, exp = 0, has_frac = 0,
            frac_digits = 0, has_exp = 0, i = 0;</code></pre>
div - переменная, в которой накапливается значение, на которое нужно будет поделить для получения дробной части(если она есть)
<pre><code>double div = 1.0;</code></pre>
power - переменная, на которую нужно будет домножить результат при наличии экспоненты
<pre><code>double power = 1.0;</code></pre>
<b>Описание функций</b>
<br>
функция is_digit проверяет, является ли введенный символ c цифрой
<pre><code>int is_digit(char c) {
        return c >= '0' && c <= '9';
}</code></pre>
функция is_space проверяет, является ли введенный символ ПП (для остановки чтения символов)
<pre><code>int is_space(char c) {
        return c == ' ' || c == '\t' || c == '\n' ||
               c == '\r' || c == '\v' || c == '\f';
}</code></pre>
функция str2double преобразует введенную символьную последовательность в вещественное число типа double
<pre><code>double str2double(char str[])</code></pre>
<b>Описание действия программы</b>
<br>
Программа получает на вход последовательность символов, которую пребразует в вещественное число типа double
<br>
</br>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task25.c" target="_blank">Task 2.5</h3>
<b>Описание функций</b>
WordList* create_node(const char *word) - создание нового узла
выделяем память под новый узел:
<pre><code> WordList *new_node = (WordList*)malloc(sizeof(WordList));</code></pre>
если не получилось выделить память - возвращаем NULL
выделяем память под слово и одно место для символа '\0'
<pre><code> new_node->word = (char*)malloc(strlen(word) + 1);</code></pre>
копируем слово в выделенную память и придаем указателю на следующий узел значение NULL
<pre><code> strcpy(new_node->word, word);
        new_node->next = NULL;</code></pre>
void append_word(WordList **head, const char *word) - добавление слова в конец списка
создаем новый узел:
<pre><code> WordList *new_node = create_node(word);</code></pre>
если список пустой, то новый узел становится головой списка
<pre><code> if (*head == NULL) {
                *head = new_node;
        } </code></pre>
иначе доходим до последнего узла и добавляем туда новый узел
char* get_last_word(WordList *head) - получение последнего слова
если список пустой, возвращаем NULL
иначе идем до последнего узла и возвращаем слово последнего узла
<pre><code> WordList *current = head;
        while (current->next != NULL) {
                current = current->next;
        }
        return current->word;</code></pre>
void remove_matching_words(WordList **head) - удаление слов, совпадающих с последним
если список пустой - выходим
<pre><code> if (*head == NULL) {
                return;
        }</code></pre>
получаем последнее слово
<pre><code>char *last_word = get_last_word(*head);</code></pre>
далее, пока не конец списка:
если слово совпадает с последним и это не последний узел, помечаем узел для удаления:
<pre><code> to_delete = current;</code></pre>
если удаляем голову списка, то голова становится следующим узлом и переходим к новой голове:
<pre><code> *head = current->next;
                                current = *head;</code></pre>
иначе пропускаем удаляемый узел и переходим к следующему
<pre><code> prev->next = current->next;
                                current = current->next;</code></pre>
освобождаем память слова и память узла
<pre><code> free(to_delete->word);
                        free(to_delete);</code></pre>
если слово не совпало с последним, переходим к новому узлу
<pre><code> prev = current;
                        current = current->next;</code></pre>
void print_list(WordList *head) - печать списка
начинаем с головы и, пока не конец списка, печатаем слово. если есть следующее слово, то печатаем пробел и переходим к следующему 
<pre><code> WordList *current = head;
        while (current != NULL) {
                printf("%s", current->word);
                if (current->next != NULL) {
                        printf(" ");
                }
                current = current->next;
        }
        printf("\n");</code></pre>
void free_list(WordList *head) - осовбождение памяти списка
WordList* string_to_word_list(const char *str) - преобразование строки в список слов
пока не конец строки, пропускаем пробелы, и если конец строки - выходим из цикла
<pre><code> while (*p != '\0') {
                while (*p != '\0' && isspace(*p)) {
                        p++;
                }
                if (*p == '\0') {
                        break;
                }</code></pre>
запоминаем начало слова и ищем конец слова
<pre><code>const char *word_start = p;
                while (*p != '\0' && !isspace(*p)) {
                        p++;
                }</code></pre>
вычисляем длину слова
<pre><code> size_t word_len = p - word_start;</code></pre>
выделяем память под слово
<pre><code> char *word = (char*)malloc(word_len + 1);</code></pre>
копируем слово и добавляем нулевой символ
<pre><code>strncpy(word, word_start, word_len);
                word[word_len] = '\0';</code></pre>
добавляем слово в список и освобождаем временную память
<pre><code> append_word(&head, word);
                free(word);</code></pre>
<b>Описание действия программы</b>
программа стоит из введенной строки список слов, после чего из списка удаляются все слова, совпадающие с последним, кроме самого последнего. преобразованный список выводится на экран
<br>
</br>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task26.c" target="_blank">Task 2.6</h3>
<b>Описание функций</b>
<br>
tNode* createNode(elemtype elem) - функция для создания нового узла в дереве:
выделение памяти под новый узел: 
<pre><code> tNode* newNode = (tNode*)malloc(sizeof(tNode));</code></pre>
в поле элемента нового узла записываем новое значение, а левого и правого потомков обнуляем
<pre><code> newNode->elem = elem;
        newNode->left = NULL;
        newNode->right = NULL;</code></pre>
tNode* insert(tNode* root, elemtype elem) - добавление нового элемента в дерево
если достигли пустого места, создаем новый узел
<pre><code> if (root == NULL) {
                return createNode(elem);
        }</code></pre>
иначе рекурсивно спускаемся в левое или правое поддерево в зависимости от того, меньше или больше вставляемый элемент текущего элемента
<pre><code> if (elem < root->elem) {
                root->left = insert(root->left, elem);
        } else if (elem > root->elem) {
                root->right = insert(root->right, elem);
        }</code></pre>
tNode* findMin(tNode* root) - поиск минимального элемента в дереве:
спускаемся в самую левую часть дерева (так как наше дерево - дерево поиска)
tNode* delete(tNode* root, elemtype elem) - удаление элемента из дерева
узел не найден:
<pre><code> if (root == NULL) {
                return NULL;
        }</code></pre>
рекурсивно ищем узел для удаления 
<pre><code> if (elem < root->elem) {
                root->left = delete(root->left, elem);
        } else if (elem > root->elem) {
                root->right = delete(root->right, elem);
        } </code></pre>
когда найден узел для удаления:
если левое поддерево - пустое, то копируем правое поддерево в текущий узел
<pre><code>  if (root->left == NULL) {
                        tNode* tmp = root->right;
                        free(root);
                        return tmp;
                } </code></pre>
аналогично, если правое поддерево - пустое
<pre><code> else if (root->right == NULL) {
                        tNode* tmp = root->left;
                        free(root);
                        return tmp;
                }</code></pre>
для общего случая находим минимальный элемент в правом поддереве и копируем его на место элемента, который нужно удалить, после чего очищаем правый минимальный элемент (можно было вместо минимального правого копировать максимальный левый)
int search(tNode* root, elemtype elem) - поиск элемента в дереве
элемент не найден:
<pre><code> if (root == NULL) {
                return 0;
        }</code></pre>
если элемент найден - возвращаем истину, рекурсивный спуск в левое или правое поддерево
void freeTree(tNode* root) - освобождение памяти дерева
<pre><code> if (root != NULL) {
                freeTree(root->left);
                freeTree(root->right);
                free(root);
        }</code></pre>
<b>Описание действия программы</b>
<br>
Программа создает пустое дерево поиска. Если вводится +число, то в дерево добавляется это число, если вводится -число, то из дерева удаляется это число, если вводится ?число, то проверяется, присутствует ли это число в дереве: если да, то выводится число и "yes", иначе - число и "no"
<br>
</br>
<h3 align="center">Модуль <a href="https://github.com/Alekseeva-Dana/tasks/blob/main/tasks/task2/task27.c" target="_blank">Task 2.7</h3>
<b>Описание переменных</b>
<br>
jmp_buf begin - точка начала диалога с пользователем, char curlex - текущая обрабатываемая лексема
<pre><code>jmp_buf begin; /*точка начала диалога с пользователем*/
char curlex; /*текущая лексема*/</code></pre>
<b>Описание функций</b>
void getlex(void) - выделяет из входного потока очередную лексему
<pre><code>void getlex(void) {
        while ((curlex = getchar()) == ' ');
}</code></pre>
void error(void) - сообщает об ошибке в выражении
<pre><code>void error(void) {
        printf("\nОШИБКА!\n");
        while(getchar() != '\n');longjmp(begin, 1);
}
</code></pre>
int expr(void) - распознает выражение и вычисляет его значение
<pre><code>int expr(void) {
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
}</code></pre>
int term(void) - распознает слагаемое и вычисляет его значение
<pre><code>int term(void) {
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
}</code></pre>
int factor(void) - распознает множитель и вычисляет его значение
<pre><code>int factor(void) {
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
}</code></pre>
int power(void) - распознает степень и вычисляет ее значение
<pre><code>int power(void) {
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
}</code></pre>
<b>Описание действия программы</b>
<br>
программа - калькулятор(работающий с однозначными цифрами), вычисляющий такие операции в выражениях, как сложение, умножение, скобки, вычитание, деление с отбрасыванием остатка, возведение в степень
