#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
	treeNode* newNode = (treeNode*)malloc(sizeof(TreeNode));
	if (newNode == NULL) {
		printf("Ошибка выделения памяти\n");
		exit(1);
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode-right = NULL;
	return newNode;
}

/*a) определение числа вхождений элемента в двоичное дерево*/
int countOcc(TreeNode* root, int value) {
	if (root == NULL) {
		return 0;
	}

	int count = 0;
	if (root->data == value) {
		count = 1;
	}
	return count + countOcc(root->left, value) + countOcc(root->right, value);
}

/*b) сумма элементов двоичного дерева*/
int sumTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	return root->data + sumTree(root->left) + sumTree(root->right);
}

/*c) входит ли данный элемент в двоичное дерево*/
int isElemInTree(TreeNode* root, int value) {
	if (root == NULL) {
		return 0;
	}

	if (root->data == value) {
		return 1;
	}

	return isElemInTree(root->left, value) || isElemInTree(root->right, value);
}

/*d) печать значений из всех узлов дерева, не являющихся листьями*/
void print(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	if (root->left != NULL || root->right != NULL) {
		printf("%d ", root->data);
	}

	print(root->left);
	print(root->right);
}

/*e) идентичны ли два двоичных дерева*/
int Identical(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) {
		return 1;
	}

	if (root1 == NULL || root2 == NULL) {
		return 0;
	}

	return (root1->data == root2->data) &&
		Identical(root1->left, root2->left) &&
		Identical(root1->right, root2->right);
}
