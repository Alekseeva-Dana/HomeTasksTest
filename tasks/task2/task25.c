#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*определение списка слов*/
struct Node {
	char *word;
	struct Node* next;
};

typedef struct Node WordList;

/*функция для создания нового узла*/
WordList* create_node(const char *word) {
	WordList *new_node = (WordList*)malloc(sizeof(WordList));
	if (!new_node) {
		return NULL;
	}

	new_node->word = (char*)malloc(strlen(word) + 1);
	if (!new_node->word) {
		free(new_node);
		return NULL;
	}

	strcpy(new_node->word, word);
	new_node->next = NULL;
	return new_node;
}

/*функция для добавления слова в конец списка*/
void append_word(WordList **head, const char *word) {
	WordList *new_node = create_node(word);
	if (!new_node) {
		return;
	}

	if (*head == NULL) {
		*head = new_node;
	} else {
		WordList *current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}

/*функция для получения последнего слова в списке*/
char* get_last_word(WordList *head) {
	if (head == NULL) {
		return NULL;
	}

	WordList *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	return current->word;
}

/*функция для удаления слов, совпадающих с последним (кроме самого последнего)*/
void remove_matching_words(WordList **head) {
	if (*head == NULL) {
		return;
	}

	char *last_word = get_last_word(*head);
	if (!last_word) {
		return;
	}

	WordList *current = *head;
	WordList *prev = NULL;
	WordList *to_delete = NULL;

	while (current != NULL) {
		if (strcmp(current->word, last_word) == 0 && current->next != NULL) {
			to_delete = current;

			if (prev == NULL) {
				*head = current->next;
				current = *head;
			} else {
				prev->next = current->next;
				current = current->next;
			}

			free(to_delete->word);
			free(to_delete);
		} else {
			prev = current;
			current = current->next;
		}
	}
}

/*функция для печати списка*/
void print_list(WordList *head) {
	WordList *current = head;
	while (current != NULL) {
		printf("%s", current->word);
		if (current->next != NULL) {
			printf(" ");
		}
		current = current->next;
	}
	printf("\n");
}

/*функция для освобождения памяти списка*/
void free_list(WordList *head) {
	WordList *current = head;
	while (current != NULL) {
		WordList *next = current->next;
		free(current->word);
		free(current);
		current = next;
	}
}

/*функция для разбиения строки на слова и создания списка*/
WordList* string_to_word_list(const char *str) {
	WordList *head = NULL;
	const char *p = str;

	while (*p != '\0') {
		while (*p != '\0' && isspace(*p)) {
			p++;
		}

		if (*p == '\0') {
			break;
		}

		const char *word_start = p;
		while (*p != '\0' && !isspace(*p)) {
			p++;
		}

		size_t word_len = p - word_start;
		char *word = (char*)malloc(word_len + 1);
		if (!word) {
			free_list(head);
			return NULL;
		}

		strncpy(word, word_start, word_len);
		word[word_len] = '\0';

		append_word(&head, word);
		free(word);
	}
	return head;
}

int main() {
	char input[1000];

	if (fgets(input, sizeof(input), stdin) == NULL) {
		return 1;
	}

	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n') {
		input[len - 1] = '\0';
	}
	WordList *word_list = string_to_word_list(input);
	remove_matching_words(&word_list);
	print_list(word_list);
	free_list(word_list);
	return 0;
}
