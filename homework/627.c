#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("ОШИБКА\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void append(Node** head, int data) {
	Node* newNode = createNode(data);

	if (*head == NULL) {
		*head = newNode;
		return;
	}

	Node* temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

/*а) сумма всех элементов списка*/
int sumList(Node* head) {
	int sum = 0;
	Node* current = head;

	while (current != NULL) {
		sum += current->data;
		current = current->next;
	}

	return sum;
}

/*b) максимальный элемент в непустом списке*/
int findMax(Node* head) {
	if (head == NULL) {
		printf("Список пуст\n");
		return -1;
	}

	int max = head->data;
	Node* current = head->next;

	while (current != NULL) {
		if (current->data > max) {
			max = current->data;
		}
		current = current->next;
	}
	return max;
}

/*c) упорядочены ли по возрастанию элементы списка*/
int isSorted(Node* head) {
	if (head == NULL || head->next == NULL) {
		return 1;
	}

	Node* current = head;

	while (current->next != NULL) {
		if (current->data > current->next->data) {
			return 0;
		}
		current = current->next;
	}
	return 1;
}

/*d) сумма максимального и минимального элементов в списке*/
int sumMinMax(Node* head) {
	if (head == NULL) {
		printf("Список пуст\n");
		return -1;
	}

	int min = head->data;
	int max = head->data;
	Node* current = head->next;

	while (current != NULL) {
		if (current->data < min) {
			min = current->data;
		}
		if (current->data > max) {
			max = current->data;
		}
		current = current->next;
	}
	return min + max;
}

