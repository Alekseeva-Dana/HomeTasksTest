#include <stdio.h>
#include <stdlib.h>

/*структура узла дерева*/
typedef struct tNode *tree;
typedef int elemtype;

typedef struct tNode {
	elemtype elem;
	tree left;
	tree right;
} tNode;

/*создание нового узла*/
tNode* createNode(elemtype elem) {
	tNode* newNode = (tNode*)malloc(sizeof(tNode));
	newNode->elem = elem;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/*добавление элемента в дерево*/
tNode* insert(tNode* root, elemtype elem) {
	if (root == NULL) {
		return createNode(elem);
	}

	if (elem < root->elem) {
		root->left = insert(root->left, elem);
	} else if (elem > root->elem) {
		root->right = insert(root->right, elem);
	}

	return root;
}

/*поиск минимального элемента в дереве*/
tNode* findMin(tNode* root) {
	while (root != NULL && root->left != NULL) {
		root = root->left;
	}
	return root;
}

/*удаление элемента из дерева*/
tNode* delete(tNode* root, elemtype elem) {
	if (root == NULL) {
		return NULL;
	}

	if (elem < root->elem) {
		root->left = delete(root->left, elem);
	} else if (elem > root->elem) {
		root->right = delete(root->right, elem);
	} else {
		/*найден узел для удаления*/
		if (root->left == NULL) {
			tNode* tmp = root->right;
			free(root);
			return tmp;
		} else if (root->right == NULL) {
			tNode* tmp = root->left;
			free(root);
			return tmp;
		}

		tNode* tmp = findMin(root->right);
		root->elem = tmp->elem;
		root->right = delete(root->right, tmp->elem);
	}
	return root;
}

/*поиск элемента в дереве*/
int search(tNode* root, elemtype elem) {
	if (root == NULL) {
		return 0;
	}
	if (elem == root->elem) {
		return 1;
	} else if (elem < root->elem) {
		return search(root->left, elem);
	} else {
		return search(root->right, elem);
	}
}

/*осовобождение памяти дерева*/
void freeTree(tNode* root) {
	if (root != NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main() {
	tNode* root = NULL;
	char operation;
	elemtype number;

	while (scanf(" %c%d", &operation, &number) == 2) {
		switch (operation) {
			case '+':
				root = insert(root, number);
				break;
			case '-':
				root = delete(root, number);
				break;
			case '?':
				printf("%d %s\n", number, search(root, number) ? "yes" : "no");
				break;
			default:
				break;
		}
	}

	/*освобождение памяти*/
	freeTree(root);
	return 0;
}

