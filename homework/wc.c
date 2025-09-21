#include <stdio.h>
#include <ctype.h>

int main() {
	int c, char_count = 0, word_count = 0, line_count = 0, in_word = 0;
	printf("Введите текст:\n");

	while ((c=getchar()) != EOF) {
		char_count++;
		
		if (c == '\n') {
			line_count++;
		}

		if (isspace(c)) {
			in_word = 0;
		} else if (!in_word) {
			word_count++;
		}
	}

	printf("Строк: %d\n", line_count);
	printf("Слов: %d\n", word_count);
	printf("Символов: %d\n", char_count);

	return 0;
}


